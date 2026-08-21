#include "mylib.h"

namespace mylib {

std::string greet(const std::string& name) {
    return "Hello, " + name + "!";
}

int add(int a, int b) {
    return a + b;
}

int multiply(int a, int b) {
    return a * b;
}

}  // namespace mylib
