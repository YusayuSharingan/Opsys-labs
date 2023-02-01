#ifndef CHECKERS_H
#define CHECKERS_H

const int ERROR = -1;
const int BREAKER = -1;
const int CHILD_ID = 0;
const int STOP_SIG = 0;

void CreatePipe(int fd[]);
void ForkError();
void FileError();
void MakeDup2(int oldFd, int newFd);
void ExecError();

#endif //CHECKERS_H

