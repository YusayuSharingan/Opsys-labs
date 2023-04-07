#include <iostream>
#include <vector>
#include <dlfcn.h>

using namespace std;
const double ACC = 100000.0;

double prog2(vector<int> argv){
    int argc = argv.size();
    if (argc == 1){
        printf("INCORRECT INPUT KEYS (need more arguments)\n");
        exit(EXIT_FAILURE);
    }
    void * lib;
    if (argv[0] == 1) {
            lib = dlopen("./libmath1.so", RTLD_LAZY);
            if (lib == NULL) {
                printf("Couldn't open library math1\n");
                exit(EXIT_FAILURE);
            }
            int (*fun)(int A, int B);
            fun = (int (*)(int,int))dlsym(lib, "GCF");
            if(fun == NULL){
                printf("Error: Couldn't link function");
                exit(EXIT_FAILURE);
            }
            double rez = fun(argv[1], argv[2]);
            dlclose(lib);
            return rez;

    } else if (argv[0] == 2) {
            lib = dlopen("./libmath2.so", RTLD_LAZY);
            if (lib == NULL) {
                printf("cannot open library math2\n");
                exit(EXIT_FAILURE);
            }
            double (*fun)(int n);
            fun = (double (*)(int))dlsym(lib, "Pi1");
            if(fun == NULL){
                printf("Error: Couldn't link function");
                exit(EXIT_FAILURE);
            }
            double rez = fun(argv[1]);
            dlclose(lib);
            rez *= ACC;
            int rezint = rez;
            double rezi = rezint/ACC;
            return rezi;
    }
    return EXIT_FAILURE;
}
