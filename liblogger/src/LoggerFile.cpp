#include "LoggerFile.h"


LoggerFile::LoggerFile(std::string file_name, Severity default_level):default_level(default_level){
    file.open(file_name, std::ios::app);
}

void LoggerFile::save_message(std::string message, Severity level){
    if (file.is_open() && level >= default_level){
        std::string severity_str = severity_to_string(level);
        std::string curr_time = get_current_time();

        std::unique_lock<std::mutex> guard(mtx);
        file << message << " : " << severity_str
             << " : [" << curr_time << "]" << std::endl;
        guard.unlock();
    }
    if (file.fail()) {
        std::cerr << "Failed to write to file!" << std::endl;
        file.clear();
    }
}

void LoggerFile::save_message(std::string message){ this->save_message(message, default_level); }

void LoggerFile::set_default_level(Severity new_level){ default_level = new_level; }

bool LoggerFile::is_good_connect(){
    return file.is_open();
}

LoggerFile::~LoggerFile(){
    if (file.is_open())
        file.close();
}