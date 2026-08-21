#include <iostream>
#include "mylib.h"

int main() {
    std::cout << mylib::greet("World") << std::endl;
    std::cout << "2 + 3 = " << mylib::add(2, 3) << std::endl;
    return 0;
}
