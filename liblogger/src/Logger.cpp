#include "Logger.h"

std::string Logger::get_current_time(){
    auto now = std::chrono::system_clock::now();
    std::time_t time_now = std::chrono::system_clock::to_time_t(now);
    tm* ltm = std::localtime(&time_now);

    std::stringstream ss;
    ss << ltm->tm_mday
       << "/"
       << 1 + ltm->tm_mon
       << "/"
       << 1900 + ltm->tm_year
       << " "
       << ltm->tm_hour
       << ":"
       << ltm->tm_min
       << ":"
       << ltm->tm_sec;

    return ss.str();
}

std::string Logger::severity_to_string(Severity level){
    std::string result;
    switch (level)
    {
    case Severity::DEBUG:
        result = "Debug";
        break;

    case Severity::ERROR:
        result = "Error";
        break;

    case Severity::EMERGENCY:
        result = "Emergency";
        break;
    
    default:
        result = "NONE";
        break;
    }
    return result;
}

Logger::Logger(std::string file_name, Severity default_level):default_level(default_level){
    file.open(file_name, std::ios::app);
    if (!file.is_open()) {
        std::cerr << "Error with open log file!" << std::endl;
    }
}

void Logger::save_message(std::string message, Severity level){
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

void Logger::save_message(std::string message){this->save_message(message, default_level);}

void Logger::set_default_level(Severity new_level){
    default_level = new_level;
}

Logger::~Logger(){
    if (file.is_open())
        file.close();
}