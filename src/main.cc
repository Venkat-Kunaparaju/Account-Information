#include <iostream>
#include <unistd.h>
#include "valid.cc"

void login() {
    int login = 0;
    std::string userName;
    std::string password;
    do {
        
        std::cout << "Enter Username or Email\n";
        std::cin >> userName;
        std::cout << "Enter Password\n";
        std::cin >> password;

        login = loginCheck(userName, password);
        if (login) {
            std::cout << "Login Successful! Logging out...\n";
        }
        else {
            std::cout << "Login unsuccessful. Try again (0 - Yes, 1 - No)\n";
            std::cin >> login;
        }

    } while (!login);
 
}
void signUp() {
    std::string userName;
    std::string email;
    std::string password;
    do {
        
        std::cout << "Enter Username\n";
        std::cin >> userName;
        std::cout << "Enter Email\n";
        std::cin >> email;
        std::cout << "Enter Password\n";
        std::cin >> password;

        if (!userCheck(userName) or !userCheck(email)) {
            std::cout << "Username invalid\n";
            continue;
        }
        int *strength = new int[5];
        passCheck(password, strength);
        if (!strength[0]) {
            std::cout << "Password too short\n";
        }
        


    } while (true);

}
int main() {
    int choice;
    std::cout << "Simple Accont Information\n";
    do {
        std::cout << "1. Log in\n2. Sign Up\n3. Exit\n";
        std::cin >> choice;


        if (choice == 1) {
            login();
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