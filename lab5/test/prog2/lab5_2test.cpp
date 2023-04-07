#include <gtest/gtest.h>
#include <vector>
#include "../../src/prog2/lab5_2.h"

using namespace std;

TEST(LabTests, FirstTest) {
    vector <int> input = {1, 55, 45};
    EXPECT_EQ(prog2(input), 5);
}

TEST(LabTests, SecondTest) {
    vector <int> input = {1, 9, 36};
    EXPECT_EQ(prog2(input), 9);
}

TEST(LabTests, ThirdTest) {
    vector <int> input = {1, 0, 1};
    EXPECT_EQ(prog2(input), 1);
}

TEST(LabTests, FourthTest) {
    vector <int> input = {2, 10};
    EXPECT_EQ(prog2(input), 3.041830);
}

TEST(LabTests, FifthTest) {
    vector <int> input = {2, 100};
    EXPECT_EQ(prog2(input), 3.131590);
}

TEST(LabTests, SixthTest) {
    vector <int> input = {2, 1000};
    EXPECT_EQ(prog2(input), 3.140590);
}

int main(int argc, char *argv[]){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}