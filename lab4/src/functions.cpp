#include "functions.h"

int GetNumber(char* s){
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


int IsPrime(int num){
    if (num % 2 == 0){
        return num == 2;
    }
    int div = 3;
    while (div * div <= num && num % div != 0){
        div += 2;
    }
    return div * div > num;
}
