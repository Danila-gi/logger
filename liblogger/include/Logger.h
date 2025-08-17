#ifndef LIBRARY_H
#define LIBRARY_H

#include <iostream>
#include <mutex>
#include "Severity.h"
#include <fstream>
#include <chrono>
#include <sstream>

/* Класс библиотеки для записи сообщений в журнал */
class Logger {
    std::fstream file; // файл, в который будет происходить запись
    Severity default_level; // уровень важности по умолчанию

    std::string get_current_time(); // функция подсчета времени записи сообщения
    std::string severity_to_string(Severity level); // функция перевода уровня важности в строковой тип
    std::mutex mtx; // мьютекс для потокобезопасной записи сообщения
    
public:
    Logger(std::string file_name, Severity default_level);

    void save_message(std::string message, Severity level); // метод записи сообщения
    void save_message(std::string message);

    void set_default_level(Severity new_level); // метод изменения уровня важности по умолчанию

    ~Logger();
};

#endif