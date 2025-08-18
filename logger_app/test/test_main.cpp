#include <iostream>
#include "Test.h"

/* Функция запуска тестирования приложения */
int main(){
    Test test("test_log.txt");

    test.run_tests();
    std::cout << "All tests passed!" << std::endl;

    return 0;
}