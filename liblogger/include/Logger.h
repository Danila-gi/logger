#ifndef LIBRARY_H
#define LIBRARY_H

#include <iostream>
#include <mutex>
#include "Severity.h"
#include <fstream>
#include <chrono>
#include <sstream>

/* Абстрактный класс библиотеки для записи сообщений в журнал */
class Logger{
protected:
    std::string get_current_time(); // функция подсчета времени записи сообщения
    std::string severity_to_string(Severity level); // функция перевода уровня важности в строковой тип
    
public:
    virtual void save_message(std::string message, Severity level) = 0; // метод записи сообщения
    
    virtual void save_message(std::string message) = 0;

    virtual void set_default_level(Severity new_level) = 0; // метод изменения уровня важности по умолчанию

    virtual bool is_good_connect() = 0; // метод проверки успешного соединения 
};

#endif