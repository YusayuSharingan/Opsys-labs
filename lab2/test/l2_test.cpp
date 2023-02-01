#include <gtest/gtest.h>
#include <vector>
#include "../src/parent.h"

using namespace std;

TEST(FirstLabTests, SimpleTest) {
    vector <int> output1 = {16, 0, 49, 27, 35, 64, 144, 169};
    vector <int> output2 = {72, 927, 39, 455, 343, 15, 0};
    vector <int> output3 = {};
    vector <int> output4 = {12, 999};
    EXPECT_EQ(ParentRoutine("./child", "../input1.txt"), output1);
    EXPECT_EQ(ParentRoutine("./child", "../input2.txt"), output2);
    EXPECT_EQ(ParentRoutine("./child", "../input3.txt"), output3);
    EXPECT_EQ(ParentRoutine("./child", "../input4.txt"), output4);
}