#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include "math1.h"

using namespace std;

int prog1(vector<int> argv){
    if(argv[0] == 1){ 
        return GCF(argv[1], argv[2]);
    } else {
        printf("Error: Incorrect arguments for GCF\n");
        exit(EXIT_FAILURE);
    }
}