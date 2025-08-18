#include <iostream>
#include "Application.h"

/* Функция запуска разработанного приложения */
int main(int argc, char* argv[]){
    std::string log_file = "log.txt";
    Severity default_level = Severity::DEBUG;

    if (argc >= 2){
        log_file = argv[1];
    }
    if (argc >= 3){
        try{
            default_level = static_cast<Severity>(std::stoi(argv[2]));
        }
        catch (const std::exception& e){
            std::cerr << "Incorrect input default level!" << std::endl;
            return 0;
        }
    }

    Application app = Application(log_file, default_level);
    app.run();

    return 0;
}