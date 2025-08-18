#ifndef LOGGER_FILE_H
#define LOGGER_FILE_H

#include <iostream>
#include <mutex>
#include "Severity.h"
#include "Logger.h"
#include <fstream>
#include <chrono>
#include <sstream>

/* Класс библиотеки для записи сообщений в текстовый файл */
class LoggerFile : public Logger{
    std::fstream file; // файл, в который будет происходить запись
    Severity default_level; // уровень важности по умолчанию
    std::mutex mtx; // мьютекс для потокобезопасной записи сообщения
    
public:
    LoggerFile(std::string file_name, Severity default_level);

    void save_message(std::string message, Severity level); // метод записи сообщения
    
    void save_message(std::string message);

    void set_default_level(Severity new_level); // метод изменения уровня важности по умолчанию

    bool is_good_connect(); // метод проверки успешности открытия файла

    ~LoggerFile();
};

#endif