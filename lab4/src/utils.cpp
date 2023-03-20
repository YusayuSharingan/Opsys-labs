#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include "utils.h"


void OpenFile(int &pfd, char *filename) {
    if((pfd = open(filename, O_RDWR)) == -1) {
        printf("Error: couldn't open file %s\n", filename);
        exit(EXIT_FAILURE);
    }
}

void SharingMemory(int &sfd, char name[]) {
    if((sfd = shm_open(name, O_CREAT | O_RDWR, S_IRWXU)) == -1) {
        printf("Error: couldn't share memory\n");
        exit(EXIT_FAILURE);
    }
}

void UnLinkingShm(char name[]) {
    if(shm_unlink(name) == -1) {
        printf("Error: couldn't unlink shared memory\n");
        exit(EXIT_FAILURE);
    }
}

void FtruncateShm(int &sfd) {
    if((ftruncate(sfd, getpagesize())) == -1) {
        printf("Error: couldn't truncate shared memory\n");
        exit(EXIT_FAILURE);
    }
}

void MakeMmap(int **ptr, int prot, int flags, int fd) {
    *ptr = (int*) mmap(nullptr, getpagesize(), PROT_READ | PROT_WRITE, flags, fd, 0);
    if(ptr == MAP_FAILED) {
        printf("Error: mmap error\n");
        exit(EXIT_FAILURE);
    }
}

void UnMapping() {
    if(munmap(nullptr, getpagesize()) == -1) {
        printf("Error: munmap error\n");
        exit(EXIT_FAILURE);
    }
}

void ForkError() {
    printf("Error: could't create new process\n");
    exit(EXIT_FAILURE);
}

void ExecError(){
    printf("Error: couldn't execute child program");
    exit(EXIT_FAILURE);

}
