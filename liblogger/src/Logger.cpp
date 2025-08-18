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