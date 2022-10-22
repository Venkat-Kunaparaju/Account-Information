#include <iostream>
#include <unistd.h>
#include "valid.cc"


//TODO: get current directory
int main() {
    if(userCheck("check")) {
        std::cout << "UserTrue";
    }
    else {
        std::cout << "UserFalse";
    }
    if(loginCheck("check", "b")) {
        std::cout << "UserTrue";
    }
    else {
        std::cout << "UserFalse";
    }

}