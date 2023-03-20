#ifndef UTILS_H
#define UTILS_H

#include <fcntl.h>

const int ERROR = -1;
const int CHILD_ID = 0;


void OpenFile(int &fd, char *filename);

void SharingMemory(int &sfd, char name[]);

void UnLinkingShm(char name[]);

void FtruncateShm(int &sfd);

void MakeMmap(int **ptr, int prot, int flags, int fd);

void UnMapping();

void ForkError();

void ExecError();


#endif //UTILS_H