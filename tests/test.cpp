#include "MetodosTest.h"
#include <gtest/gtest.h>
#include <algorithm>

// Prueba para kruskalMST
TEST(MetodosTest, KruskalMST) {
    std::vector<std::vector<double>> graph = {
        {0, 16, 45, 32},
        {16, 0, 18, 21},
        {45, 18, 0, 7},
        {32, 21, 7, 0}
    };

    std::vector<std::pair<char, char>> expected = { {'C', 'D'}, {'A', 'B'}, {'B', 'C'} };
    auto result = kruskalMST(graph);
    EXPECT_TRUE(std::is_permutation(result.begin(), result.end(), expected.begin()));
}

// Prueba para tsp
TEST(MetodosTest, TSP) {
    std::vector<std::vector<double>> graph = {
        {0, 48, 12, 18},
        {52, 0, 42, 32},
        {18, 46, 0, 56},
        {24, 36, 52, 0}
    };

    auto result = tsp(graph);
    std::vector<int> expectedPath1 = { 0, 2, 1, 3, 0 };
    std::vector<int> expectedPath2 = { 0, 3, 1, 2, 0 }; 
    EXPECT_TRUE(result.second == expectedPath1 || result.second == expectedPath2);
    EXPECT_NEAR(result.first, 78, 1e-6);
}

// Prueba para findNearestCentral
TEST(MetodosTest, FindNearestCentral) {
    std::vector<std::pair<int, int>> centrals = {
        {200, 500}, {300, 100}, {450, 150}, {520, 480}, {400, 300}
    };

    std::pair<int, int> house = { 410, 310 }; 
    std::pair<int, int> expected = { 450, 150 };
    auto result = findNearestCentral(house, centrals);
    EXPECT_EQ(result, expected) << "Nearest central is incorrect. Expected: " << expected.first << ", " << expected.second << " but got: " << result.first << ", " << result.second;
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
