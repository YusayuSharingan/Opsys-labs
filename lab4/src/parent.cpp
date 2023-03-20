#include <sys/mman.h>
#include <sys/wait.h>
#include <vector>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include "utils.h"


char name[] = "shared_memory";
char child[] = "./child";

std::vector <int> ParentRoutine(char child[], char filename[]){
    std::vector <int> output = {};

        int sfd;
        int *aptr = nullptr;
        SharingMemory(sfd, name);
        FtruncateShm(sfd);

        int pid = fork();
        if(pid == ERROR) {
                ForkError();
        } else if (pid == CHILD_ID) {
                int fd;
                int *fptr = nullptr;
                OpenFile(fd, filename);
                MakeMmap(&fptr, PROT_READ, MAP_SHARED, fd);
                execl(child, child, fptr, name, NULL);
        } else {
                wait(NULL);
                MakeMmap(&aptr, PROT_READ | PROT_WRITE, MAP_SHARED, sfd);
                int cnt = 0;
                for(int i = 1; i < aptr[0]; i++) {
                        output.push_back(aptr[i]);
                }

        }
        
        UnMapping();

        UnLinkingShm(name);

        return output;
}
