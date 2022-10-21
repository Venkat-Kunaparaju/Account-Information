#include <iostream>
#include <unistd.h>

int main() {
    pid_t pid;
    time_t t;
    int status;

    //Child process for checking user
    if (!fork()) {

        std::string userCheck = "/Users/venkat/Downloads/Account-Information/userCheck.sh";
        char *args[2];
        args[0] = (char *)userCheck.c_str();
        args[1] = NULL;
        execvp(args[0], args);
        std::cerr << "excvp error";
        exit(1);
    
    }

    //system("/Users/venkat/Downloads/Account-Information/userCheck.sh");

    



}