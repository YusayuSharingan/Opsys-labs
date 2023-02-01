#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "lab3.h"

const char MINUS = '-';
const char ZERO = '0';
const char EOS = '\0';


int GetNumber(char *s){
    int code = ZERO;
    int cntr = 0;
    if (s[cntr] - MINUS == 0){
        return -1;
    }
    int sum = 0;
    while (s[cntr] != EOS){
        code = s[cntr] - ZERO;
        if(code < 0 || code > 9){
            break;
        } 
        sum = sum*10 + code;
        cntr++;
    }
    return sum;
}


int main(int argc, char *argv[]){
    int result, threadNum = GetNumber(argv[1]);
    if(argc==2){
        long double start, end;
        start = clock();
        result = main_routine(threadNum);
        end = clock();
        int time = (end - start) / 1000;
        printf("Min value is %d\n", result);
        printf("Time of executing: %d\n", time);
    } else {
        printf("Error: input number of threads\n");
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}