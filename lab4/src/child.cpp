#include <sys/mman.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "utils.h"
#include "functions.h"


int main(int argc, char *argv[]){

    int sfd;
    int *memory = nullptr;
    SharingMemory(sfd, argv[2]);
    MakeMmap(&memory, PROT_READ | PROT_WRITE, MAP_SHARED, sfd);

    int n, p = 0, ans = 1;
    char number[32];
    for (int i=0; argv[1][i] != EOS; i++) {
        number[p++] = argv[1][i];
        if(argv[1][i] == EOL) {
            p = 0;
            n = GetNumber(number);
            if (n < 0) {
                memory[0] = ans;
                exit(EXIT_FAILURE);
            } else if (IsPrime(n)) {
                memory[0] = ans;
                exit(EXIT_FAILURE);
            } else {
                memory[ans++] = n;
            }
        }
    }
    memory[0] = ans;
    
    return 0;
}