#include <iostream>
#include <unistd.h>
#include "valid.cc"

void login() {
    int login = 0;
    do {
        std::string userName;
        std::cout << "Enter Username\n";
        std::cin >> userName;
        std::cout << "Enter Username\n";

    

    } while (!login);
}
int main() {
    int choice;
    std::cout << "Simple Accont Information\n";
    do {
        std::cout << "1. Login\n2. Sign In\n3. Exit\n";
        std::cin >> choice;


        if (choice == 1) {


        }
        else if (choice == 2) {

        }
        else if (choice == 3) {
            std::cout << "GOODBYE!\n";
        }
        else {
            std::cout << "Invalid choice\n";
        }


    } while(choice != 3);



}