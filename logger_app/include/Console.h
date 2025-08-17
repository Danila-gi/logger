#ifndef CONSOLE_H
#define CONSOLE_H

#include <iostream>
#include <limits>

/* Класс для вывода и ввода информации в консоль */
class Console {
public:
    void print_info();
    void print_unknown_command();
    void print_severity_level();
    void print_message();
    void input_severity_level(int& sev);
    void input_message(std::string& message);
    void input_command(int& command);
    void print_command();
};

#endif