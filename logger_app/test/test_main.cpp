#include <iostream>
#include "Test.h"

/* Функция запуска тестирования приложения */
int main(){
    Test test("test_log.txt");

    test.run_tests();
    std::cout << "All test passed!" << std::endl;

    return 0;
}