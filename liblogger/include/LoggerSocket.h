#ifndef LOGGER_SOCK_H
#define LOGGER_SOCK_H

#include <iostream>
#include <mutex>
#include "Severity.h"
#include "Logger.h"
#include <fstream>
#include <chrono>
#include <sstream>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <unistd.h>

/* Класс библиотеки для записи сообщений в журнал через сокет */
class LoggerSocket: public Logger{
    int sock; // сокет клиента
    struct sockaddr_in addr; // адрес для связи сокета
    Severity default_level; // уровень важности по умолчанию
    std::mutex mtx; // мьютекс для потокобезопасной записи сообщения
    bool flag_connect;
    
public:
    LoggerSocket(const char* address, int port, Severity default_level);

    void save_message(std::string message, Severity level); // метод записи сообщения
    void save_message(std::string message);

    void set_default_level(Severity new_level); // метод изменения уровня важности по умолчанию

    bool is_good_connect(); // метод проверки успешного соединения

    ~LoggerSocket();
};

#endif