#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <vector>
#include "checkers.h"
#include "parent.h"


std::vector <int> ParentRoutine(char child[], char filename[]){
    std::vector <int> output = {};

    int fd[2];
    CreatePipe(fd);

    int pid = fork();
    if (pid == ERROR){              // fork error check
        ForkError();
    } else if (pid == CHILD_ID) {  // for child process
        close(fd[0]);
        FILE *fi;
        if (!(fi = freopen(filename, "r", stdin))){
            FileError();
        }
        MakeDup2(fd[1], STDOUT_FILENO);
        if (execl(child, child, NULL) == ERROR){
            ExecError();
        }
    } else {                    // for parent process
        close(fd[1]);
        int result;
        while(read(fd[0], &result, sizeof(int)) != STOP_SIG){
            if (result == BREAKER){
                return output;
            }
            output.push_back(result);
        }
    }
    return output;
}