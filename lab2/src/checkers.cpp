#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "checkers.h"


void CreatePipe(int fd[]) {
    if (pipe(fd) != 0) {
        printf("Error: couldn't create pipe\n");
        exit(EXIT_FAILURE);
    }
}

void ForkError() {
    printf("Error: could't create new process\n");
    exit(EXIT_FAILURE);
}

void FileError(){
    printf("Error: couldn't open file\n");
    exit(EXIT_FAILURE);
}

void MakeDup2(int oldFd, int newFd) {
    if (dup2(oldFd, newFd) == ERROR) {
        printf("Error: couldn't change child stdin\n");
        exit(EXIT_FAILURE);
    }
}

void ExecError(){
    printf("Error: couldn't execute child program");
    exit(EXIT_FAILURE);

}
