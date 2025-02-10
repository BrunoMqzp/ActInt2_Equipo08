#include <gtest/gtest.h>
#include <vector>
#include <utility>
#include <cmath>
#include "MetodosTest.h"


// Prueba para kruskalMST
TEST(MetodosTest, KruskalMST) {
    std::vector<std::vector<double>> graph = {
        {0, 16, 45, 32},
        {16, 0, 18, 21},
        {45, 18, 0, 7},
        {32, 21, 7, 0}
    };

    std::vector<std::pair<char, char>> expected = { {'C', 'D'}, {'A', 'B'}, {'B', 'C'} };
    EXPECT_EQ(kruskalMST(graph), expected);
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
    EXPECT_EQ(result.second, std::vector<int>({ 0, 2, 1, 3, 0 })); // A B C D A
    EXPECT_EQ(static_cast<int>(result.first), 78);
}

// Prueba para findNearestCentral
TEST(MetodosTest, FindNearestCentral) {
    std::vector<std::pair<int, int>> centrals = {
        {200, 500}, {300, 100}, {450, 150}, {520, 480}, {400, 300}
    };

    std::pair<int, int> house = { 400, 300 };
    EXPECT_EQ(findNearestCentral(house, centrals), std::make_pair(450, 150));
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
