#include <iostream>
#include <unistd.h>

int main() {
   
    if (!fork()) {

        std::string userCheck = "/Users/venkat/Downloads/Account-Information/userCheck.sh";
        char *args[2];
        args[0] = (char *)userCheck.c_str();
        args[1] = NULL;
        execvp(args[0], args);
        std::cout << "check";
       
    }

    //system("/Users/venkat/Downloads/Account-Information/userCheck.sh");

    



}