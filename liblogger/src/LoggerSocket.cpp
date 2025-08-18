#include "LoggerSocket.h"

LoggerSocket::LoggerSocket(const char* address, int port, Severity default_level):default_level(default_level), flag_connect(true){
    sock = socket(AF_INET, SOCK_STREAM, 0);

    if (sock < 0){
        flag_connect = false;
    }
    
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = inet_addr(address);

    if (connect(sock, (struct sockaddr *)&addr, sizeof(addr)) < 0){
        flag_connect = false;
    }
}

void LoggerSocket::save_message(std::string message, Severity level){
    if (level >= default_level){
        std::string severity_str = severity_to_string(level);
        std::string curr_time = get_current_time();

        std::string result_log = message + " : " + severity_str + " : " + curr_time;

        std::unique_lock<std::mutex> guard(mtx);
        send(sock, result_log.c_str(), result_log.length() + 1, 0);
        guard.unlock();
    }
}

void LoggerSocket::save_message(std::string message){ this->save_message(message, default_level); }

void LoggerSocket::set_default_level(Severity new_level){ default_level = new_level; }

bool LoggerSocket::is_good_connect(){ return flag_connect; }

LoggerSocket::~LoggerSocket(){
    close(sock);
}