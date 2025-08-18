#ifndef LOGGER_H
#define LOGGER_H

#include <iostream>
#include <memory>
#include <thread>
#include "Severity.h"
#include "LoggerFile.h"
#include "LoggerSocket.h"
#include "Console.h"

/* Класс приложения */
class Application {
    std::shared_ptr<Logger> logger; // объект подключенной библиотеки
    Console console; // объект консоли для работы с вводом и выводом информации
    
public:
    Application(std::shared_ptr<Logger> logger);

    void run(); // метод запуска приложения
};

#endif