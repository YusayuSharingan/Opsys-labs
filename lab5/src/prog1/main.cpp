#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include "lab5_1.h"

int main(int argc, char *argv[]){
    if(argc != 4){
        printf("Error: invalid arguments\n");
        return EXIT_FAILURE;
    }
    std::vector<int> args =  {1, atoi(argv[2]), atoi(argv[3])};
    printf("%d\n", prog1(args));
    return 0;
}