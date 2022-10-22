#include <iostream>
#include <unistd.h>

int userCheck(std::string user) {
    pid_t pid;
    int status;

    //Save default standard out
    int defaultOut = dup(1);
    
    //Pipe output of child to parent
    int fdpipe[2];
    pipe(fdpipe);
    dup2(fdpipe[1], 1);
    close(fdpipe[1]);


    //Child process for checking user
    pid = fork();
    if (pid == 0) {
        char *pwd = getenv("PWD");
        std::string usernameCheck = pwd;
        usernameCheck += "/userCheck.sh";
        char *args[3];
        args[0] = (char *)usernameCheck.c_str();
        args[1] = (char *)user.c_str();
        args[2] = NULL;
        execvp(args[0], args);
        std::cerr << "excvp error";
        exit(1);
    
    }
    //Waits for child process to finish
    
    pid = waitpid(pid, &status, WUNTRACED);

    //Get output of child from pipe
    char *out = new char[1];
    int bytes = read(fdpipe[0], out, 1);
    int ret = (int) out[0] - 48;
    close(fdpipe[0]);

    //Restore standard out
    dup2(defaultOut, 1);
    close(defaultOut);

    return ret;
}

