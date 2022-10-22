#include <iostream>
#include <unistd.h>
#include "valid.cc"


//TODO: get current directory
int main() {
    if(userCheck()) {
        std::cout << "UserTrue";
    }
    else {
        std::cout << "UserFalse";
    }

}