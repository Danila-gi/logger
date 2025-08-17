#include "Test.h"

Test::Test(std::string file_name):file_name(file_name){
    std::ofstream {file_name};
};

void Test::test_library_count_messages(){
    Logger logger(file_name, Severity::ERROR);
    logger.save_message("First message", Severity::ERROR);
    logger.save_message("Second message", Severity::EMERGENCY);
    logger.save_message("Third message", Severity::DEBUG);
    logger.save_message("Fourth message");

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
    assert(count_lines == 3);
}

void Test::run_tests(){
    test_library_count_messages();
}