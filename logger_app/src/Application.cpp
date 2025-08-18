#include "Application.h"

Application::Application(std::shared_ptr<Logger> logger): logger(logger){}

void Application::run(){
    if (!logger->is_good_connect()){
        console.print_file_error();
        return;
    }

    console.print_info();
    bool flag = true;
    std::string message;
    while (flag){
        int command;
        console.print_command();
        console.input_command(command);
        if (command == 0){
            int sev;
            std::string message;

            console.print_severity_level();
            console.input_severity_level(sev);

            console.print_message();
            console.input_message(message);

            std::thread th([=](){ 
                if (sev >= 0 && sev < static_cast<int>(Severity::COUNT))
                    logger->save_message(message, static_cast<Severity>(sev));
                else
                    logger->save_message(message);
            });
            th.join();
        }
        else if (command == 1){
            console.print_info();
        }
        else if (command == 2){
            int sev;
            console.print_severity_level();
            console.input_severity_level(sev);
            if (sev >= 0 && sev < static_cast<int>(Severity::COUNT)){
                logger->set_default_level(static_cast<Severity>(sev));
            }
        }
        else if (command == 3){
            return;
        }
        else{
            console.print_unknown_command();
        }
        
    }
}