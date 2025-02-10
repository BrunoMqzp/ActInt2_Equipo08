#include <gtest/gtest.h>
#include <vector>
#include <utility>
#include <cmath>
#include "MetodosTest.h"


// Test Kruskal's MST algorithm
TEST(KruskalTest, BasicTest) {
        std::vector<std::vector<double>> graph = {
            {0, 16, 45, 32},
            {16, 0, 18, 21},
            {45, 18, 0, 7},
            {32, 21, 7, 0}
        };

    std::vector<std::pair<char, char>> expected = { {'C', 'D'}, {'A', 'B'}, {'B', 'C'} };
    auto result = kruskal_mst(graph);
    EXPECT_TRUE(std::is_permutation(result.begin(), result.end(), expected.begin()));
}

// Test TSP algorithm
TEST(TSPTest, BasicTest) {
    std::vector<std::vector<double>> graph = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };

    auto result = tsp(graph);
    double expectedCost = 80;
    ASSERT_NEAR(result.first, expectedCost, 1e-6);
}

// Test Nearest Central function
TEST(NearestCentralTest, BasicTest) {
    std::vector<std::pair<int, int>> centrals = {
        {200, 500},
        {300, 100},
        {450, 150},
        {520, 480}
    };

    std::pair<int, int> newHouse = { 400, 300 };
    auto result = find_nearest_central(newHouse, centrals);
    std::pair<int, int> expected = { 450, 150 };

    ASSERT_EQ(result, expected);
}

TEST(EdgeTest, CompareEdges) {
    
    Edge edge1{ 1, 2, 10.0 };
    Edge edge2{ 2, 3, 20.0 };

    
    EXPECT_TRUE(edge1 < edge2);

    
    EXPECT_FALSE(edge2 < edge1);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
