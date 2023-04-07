#include <gtest/gtest.h>
#include <vector>
#include "../../src/prog1/lab5_1.h"

using namespace std;

TEST(LabTests, FirstTest) {
    vector <int> input = {1, 55, 45};
    EXPECT_EQ(prog1(input), 5);
}

TEST(LabTests, SecondTest) {
    vector <int> input = {1, 9, 36};
    EXPECT_EQ(prog1(input), 9);
}

TEST(LabTests, ThirdTest) {
    vector <int> input = {1, 0, 1};
    EXPECT_EQ(prog1(input), 1);
}

int main(int argc, char *argv[]){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}