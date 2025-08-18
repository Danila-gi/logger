#include <iostream>
#include <memory>
#include "Application.h"

/* Функция для выбора работы приложения */
std::shared_ptr<Logger> choose_logger(int argc, char* argv[]){
    std::shared_ptr<Logger> logger;
    std::string log_file = "log.txt";
    Severity default_level = Severity::DEBUG;
    bool flag_file = true;
    if (argc >= 2){
        if (strcmp(argv[1], "socket") == 0){
            flag_file = false;
        }
        else{
            log_file = argv[1];
        }
    }
    
    if (argc >= 3){
        try{
            int sev_int = std::stoi(argv[2]);
            if (sev_int >= 0 && sev_int < static_cast<int>(Severity::COUNT))
                default_level = static_cast<Severity>(sev_int);
        }
        catch (const std::exception& e){
            std::cerr << "Incorrect input default level!" << std::endl;
        }
    }
    if (flag_file){
        logger = std::make_shared<LoggerFile>(log_file, default_level);
    }
    else{
        logger = std::make_shared<LoggerSocket>("127.0.0.1", 8000, default_level);
    }
    return logger;
}

/* Функция запуска разработанного приложения */
int main(int argc, char* argv[]){
    std::shared_ptr<Logger> logger = choose_logger(argc, argv);

    if (logger != nullptr){
        Application app = Application(logger);
        app.run();
    }

    return 0;
}