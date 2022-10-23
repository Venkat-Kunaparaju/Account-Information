#include <iostream>
#include <unistd.h>

//Returns 0 if user does not exist, 1 if does exist
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
        usernameCheck += "/ShellScripts/userCheck.sh";
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
//Returns 0 if login info not found, 1 if found
int loginCheck(std::string user, std::string pass) {
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
        usernameCheck +=  "/ShellScripts/loginCheck.sh";
        char *args[4];
        args[0] = (char *)usernameCheck.c_str();
        args[1] = (char *)user.c_str();
        args[2] = (char *)pass.c_str();
        args[3] = NULL;
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
void passCheck(std::string pass, int *ret) {
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
        usernameCheck +=  "/ShellScripts/passCheck.sh";
        char *args[3];
        args[0] = (char *)usernameCheck.c_str();
        args[1] = (char *)pass.c_str();
        args[2] = NULL;
        execvp(args[0], args);
        std::cerr << "excvp error";
        exit(1);
    
    }
    //Waits for child process to finish
    pid = waitpid(pid, &status, WUNTRACED);

    //Get output of child from pipe
    char *out = new char[5];
    int bytes = read(fdpipe[0], out, 5);
    close(fdpipe[0]);

    //Length, Special, Number, Upper, Lower
    for (int i = 0; i < bytes; i++) {
        ret[i] = (int) (out[i] - 48);
    }
    
    //Restore standard out
    dup2(defaultOut, 1);
    close(defaultOut);

}
void writeFile(std::string username, std::string email, std::string password) {
    int ret = fork();
    if(!ret) {
        char *pwd = getenv("PWD");
        std::string usernameCheck = pwd;
        usernameCheck +=  "/ShellScripts/writeToFile.sh";
        char *args[5];
        args[0] = (char *)usernameCheck.c_str();
        args[1] = (char *)username.c_str();
        args[2] = (char *)email.c_str();
        args[3] = (char *)password.c_str();
        args[4] = NULL;
        execvp(args[0], args);
        std::cerr << "excvp error";
        exit(1);
    }
}

