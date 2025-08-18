#include "Test.h"

Test::Test(std::string file_name):file_name(file_name){};

int Test::count_lines(){
    std::ifstream file;
    file.open(file_name);

    int count_lines = 0;
    if (file.is_open()){
        std::string line;
        while (getline(file, line)){
            count_lines++;
        }
    }
    file.close();
    return count_lines;
}

void Test::test_library_count_messages(){
    std::ofstream {file_name};

    LoggerFile logger(file_name, Severity::ERROR);
    logger.save_message("First message", Severity::ERROR);
    logger.save_message("Second message", Severity::EMERGENCY);
    logger.save_message("Third message", Severity::DEBUG);
    logger.save_message("Fourth message");

    assert(count_lines() == 3);
}

void Test::test_library_set_level(){
    std::ofstream {file_name};

    LoggerFile logger(file_name, Severity::ERROR);
    logger.save_message("First message", Severity::ERROR);
    logger.set_default_level(Severity::EMERGENCY);
    logger.save_message("Second message", Severity::ERROR);

    std::string line;
    std::ifstream file;
    file.open(file_name);
    getline(file, line); 

    assert(count_lines() == 1 && line.find("First message") != std::string::npos);
}

void Test::test_application_console_input(){
    std::ofstream {file_name};
    auto orig_cin_buf = std::cin.rdbuf();

    std::string test_input = "0\n1\nMsg from console\n3\n";
    std::istringstream test_input_stream(test_input);

    std::cin.rdbuf(test_input_stream.rdbuf());

    std::shared_ptr<Logger> logger = std::make_shared<LoggerFile>(file_name, Severity::DEBUG);
    Application app(logger);
    app.run();

    std::cin.rdbuf(orig_cin_buf);

    std::string line;
    std::ifstream file;
    file.open(file_name);
    getline(file, line);

    assert(line.find("Msg from console : Error") != std::string::npos);
}

void Test::run_tests(){
    test_library_count_messages();
    test_library_set_level();
    test_application_console_input();
}