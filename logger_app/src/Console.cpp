#include "Console.h"

void Console::print_info(){
    std::cout << "Commands:" << std::endl;
    std::cout << "0 - write message" << std::endl;
    std::cout << "1 - help" << std::endl;
    std::cout << "2 - change default level" << std::endl;
    std::cout << "3 - exit" << std::endl;
}

void Console::print_unknown_command(){
    std::cout << "Unknown_command" << std::endl;
}

void Console::print_severity_level(){
    std::cout << "Input severity level (0 - DEBUG, 1 - ERROR, 2 - EMERGENCY, 3 - NULL):" << std::endl;
}

void Console::print_message(){
    std::cout << "Input message:" << std::endl;
}

void Console::print_command(){
    std::cout << "Print command:" << std::endl;
}

void Console::input_severity_level(int& sev){
    std::cin >> sev;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
}

void Console::input_message(std::string& message){ 
    std::getline(std::cin, message);
}

void Console::input_command(int& command){
    std::cin >> command;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
}

void Console::print_file_error(){
    std::cerr << "Error with connect!" << std::endl;
}