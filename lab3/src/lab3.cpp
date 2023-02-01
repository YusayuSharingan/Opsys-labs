#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <malloc.h>
#include <pthread.h>

pthread_mutex_t mutex;
const int STOP_SIG = -1;

void* ThreadFunc(void* arg){
    int num, *minV=(int*)arg;
    while(scanf("%d", &num)!=STOP_SIG){
        pthread_mutex_lock(&mutex);
        if(num < *minV){
            *minV = num;
        }
        pthread_mutex_unlock(&mutex);

    }
    return NULL;
}


int main_routine(int threadNum){
    int minValue = INT_MAX;
    pthread_t *ths = (pthread_t*)malloc(sizeof(pthread_t)*threadNum);
    if (ths == NULL){
        printf("ERROR: couldn't allocate memmmory\n");
        return EXIT_FAILURE;
    }
    pthread_mutex_init(&mutex, NULL);
    for (int i=0; i<threadNum; i++){
        if(pthread_create(ths + i, NULL, ThreadFunc, &minValue)){
            printf("ERROR: couldn't create thread\n");
            return EXIT_FAILURE;
        }
    }
    for(int i=0; i<threadNum; i++){
        pthread_join(ths[i], NULL);
    }
    pthread_mutex_destroy(&mutex);
    return minValue;
}
