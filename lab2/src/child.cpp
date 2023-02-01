#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "functions.h"


int main(){
    char number[32];
    while (scanf("%s", number) != STOP_SIG){
        int n = GetNumber(number);
        if (n < 0){
            write(STDOUT_FILENO, &NEGATIVE, sizeof(int));
            exit(EXIT_FAILURE);
        } else if (IsPrime(n)){
            write(STDOUT_FILENO, &NEGATIVE, sizeof(int));
            exit(EXIT_FAILURE);
        } else {
            write(STDOUT_FILENO, &n, sizeof(int));
        }
    }
    return 0;
}