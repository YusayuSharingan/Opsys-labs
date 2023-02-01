#include <stdio.h>
#include <vector>
#include "parent.h"


int main(){
    char input[256];
    printf("Input name of file\n");
    scanf("%s", input);

    std::vector <int> output;
    output = ParentRoutine("./child", input);

    for (int i=0; i<output.size(); i++){
        printf("%d ", output[i]);
    }

    printf("\n");
    return 0;
}