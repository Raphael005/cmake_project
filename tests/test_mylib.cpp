#include <cassert>
#include <iostream>
#include "mylib.h"

void test_greet() {
    assert(mylib::greet("World") == "Hello, World!");
    assert(mylib::greet("CMake") == "Hello, CMake!");
    std::cout << "test_greet passed" << std::endl;
}

void test_add() {
    assert(mylib::add(2, 3) == 5);
    assert(mylib::add(-1, 1) == 0);
    assert(mylib::add(0, 0) == 0);
    std::cout << "test_add passed" << std::endl;
}

int main() {
    test_greet();
    test_add();
    std::cout << "All tests passed!" << std::endl;
    return 0;
}
