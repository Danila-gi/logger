#ifndef TEST_H
#define TEST_H

#include <iostream>
#include <fstream>
#include <cassert>
#include "Application.h"

/* Класс для тестирования приложения */
class Test {
    std::string file_name;

    void test_library_count_messages();
public:
    Test(std::string file_name);
    void run_tests();
};

#endif