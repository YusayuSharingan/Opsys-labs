#include <gtest/gtest.h>
#include <vector>
#include "../src/parent.h"

using namespace std;

TEST(LabTests, FirstTest) {
    vector <int> output1 = {16, 0, 49, 27, 35, 64, 144, 169};
    EXPECT_EQ(ParentRoutine("./child", "./input1.txt"), output1);
}

TEST(LabTests, SecondTest) {
    vector <int> output2 = {72, 927, 39, 455, 343, 15, 0};

    EXPECT_EQ(ParentRoutine("./child", "./input2.txt"), output2);
}

TEST(LabTests, ThirdTest) {
    vector <int> output3 = {};
    EXPECT_EQ(ParentRoutine("./child", "./input3.txt"), output3);
}

TEST(LabTests, FourthTest) {
    vector <int> output4 = {12, 999};
    EXPECT_EQ(ParentRoutine("./child", "./input4.txt"), output4);
}

int main(int argc, char *argv[]){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}