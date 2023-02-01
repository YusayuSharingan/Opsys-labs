#include <gtest/gtest.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#include "lab3.h"


using namespace std;
const int N = 10000;
const char file[] = "input";

class ThirdLabTest : public ::testing::Test {
};

TEST(ThirdLabTest, 4ThreadsTest){

    //ARRANGE
    time_t utc = time(NULL);
    srand(utc);
    int value, minV = INT_MAX;
    int result, threadNum = 5;
    FILE *input1;
    input1 = fopen(file, "w");

    //ACT
    for(int i=0; i<N; i++){
        value = INT_MIN + 2*rand();
        fprintf(input1, "%d\n", value);
        if(value < minV){
            minV = value;
        }
    }
    fclose(input1);
    input1 = freopen(file, "r", stdin);
    result = main_routine(threadNum);
    fclose(input1);
    remove(file);

    //ASSERT
    ASSERT_EQ(minV, result);
}


TEST(ThirdLabTest, 7ThreadsTest){

    //ARRANGE
    time_t utc = time(NULL);
    srand(utc);
    int value, minV = INT_MAX;
    int result, threadNum = 7;
    FILE *input1;
    input1 = fopen(file, "w");

    //ACT
    for(int i=0; i<N; i++){
        value = INT_MIN + 2*rand();
        fprintf(input1, "%d\n", value);
        if(value < minV){
            minV = value;
        }
    }
    fclose(input1);
    input1 = freopen(file, "r", stdin);
    result = main_routine(threadNum);
    fclose(input1);
    remove(file);

    //ASSERT
    ASSERT_EQ(minV, result);
}


TEST(ThirdLabTest, OneThreadsTest){

    //ARRANGE
    time_t utc = time(NULL);
    srand(utc);
    int value, minV = INT_MAX;
    int result, threadNum = 1;
    FILE *input1;
    input1 = fopen(file, "w");

    //ACT
    for(int i=0; i<N; i++){
        value = INT_MIN + 2*rand();
        fprintf(input1, "%d\n", value);
        if(value < minV){
            minV = value;
        }
    }
    fclose(input1);
    input1 = freopen(file, "r", stdin);
    result = main_routine(threadNum);
    fclose(input1);
    remove(file);

    //ASSERT
    ASSERT_EQ(minV, result);
}

int main(int argc, char *argv[]){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}