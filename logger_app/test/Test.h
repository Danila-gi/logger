#ifndef TEST_H
#define TEST_H

#include <iostream>
#include <fstream>
#include <cassert>
#include "Application.h"

/* Класс для тестирования приложения */
class Test {
    std::string file_name;

    int count_lines();

    void test_library_count_messages();
    void test_library_set_level();
    void test_application_console_input();
public:
    Test(std::string file_name);
    void run_tests();
};

#endif