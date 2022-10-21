#include <iostream>
#include <unistd.h>


//TODO: get current directory
int main() {
    pid_t pid;
    int status;

    //Child process for checking user
    pid = fork();
    if (pid == 0) {
        
        std::string userCheck = "/Users/venkat/Downloads/Account-Information/userCheck.sh";
        char *args[2];
        args[0] = (char *)userCheck.c_str();
        args[1] = NULL;
        execvp(args[0], args);
        std::cerr << "excvp error";
        exit(1);
        
    
    }

    //Waits for child process to finish
    pid = waitpid(pid, &status, WUNTRACED);

    //Checks for parent execution
    std::cout << "check";



    



}