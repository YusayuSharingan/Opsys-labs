#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include "lab5_2.h"

int main(int argc, char *argv[]){
    if(argc == 4){
        std::vector<int> args =  {atoi(argv[1]), atoi(argv[2]), atoi(argv[3])};
        printf("%f\n", prog2(args));
        return 0;
    } else if(argc == 3){
        std::vector<int> args =  {atoi(argv[1]), atoi(argv[2])};
        printf("%f\n", prog2(args));
        return 0;
    } else {
        printf("Error: invalid arguments\n");
        return EXIT_FAILURE;
    }

}