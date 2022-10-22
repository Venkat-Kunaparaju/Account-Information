#include <iostream>
#include <unistd.h>
#include "valid.cc"


int main() {
    if(userCheck("check")) {
        std::cout << "UserTrue";
    }
    else {
        std::cout << "UserFalse";
    }
    std::cout << "\n";

    if(loginCheck("check", "b")) {
        std::cout << "LoginTrue";
    }
    else {
        std::cout << "LoginFalse";
    }
    std::cout << "\n";
    
    int *strength = new int[5];
    passCheck("A^", strength);

    for (int i = 0; i < 5; i++) {
        std::cout << strength[i];
    }



}