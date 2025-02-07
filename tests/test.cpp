// test_main.cpp
#include <gtest/gtest.h>
#include "headertest.h"

// Test cases (unchanged)
TEST(KruskalTest, BasicTest) {
    std::vector<std::vector<double>> graph = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };

    auto result = kruskalMST(graph);
    std::vector<std::pair<char, char>> expected = {
        {'A', 'B'},
        {'B', 'C'},
        {'A', 'D'},
        {'B', 'E'}
    };

    ASSERT_EQ(result, expected);
}

TEST(TSPTest, BasicTest) {
    std::vector<std::vector<double>> graph = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };

    auto result = tsp(graph);
    double expectedCost = 80; // Known minimum cost for this graph
    ASSERT_NEAR(result.first, expectedCost, 1e-6);
}

TEST(NearestCentralTest, BasicTest) {
    std::vector<std::pair<int, int>> centrals = {
        {200, 500},
        {300, 100},
        {450, 150},
        {520, 480}
    };

    std::pair<int, int> newHouse = { 400, 300 };
    auto result = findNearestCentral(newHouse, centrals);
    std::pair<int, int> expected = { 450, 150 };

    ASSERT_EQ(result, expected);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}