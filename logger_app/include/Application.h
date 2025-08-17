#ifndef LOGGER_H
#define LOGGER_H

#include <iostream>
#include <thread>
#include "Severity.h"
#include "Logger.h"
#include "Console.h"

/* Класс приложения */
class Application {
    Logger* logger; // объект подключенной библиотеки
    Console console; // объект консоли для работы с вводом и выводом информации
    
public:
    Application(std::string file_name, Severity default_level);

    void run(); // метод запуска приложения
    ~Application();
};

#endif