#ifndef HEADERTEST_H
#define HEADERTEST_H

#include <vector>
#include <utility>
#include <cmath>

// Estructura para representar una arista en el grafo
struct Edge {
    int u, v;
    double weight;
    bool operator<(const Edge& other) const {
        return weight < other.weight;
    }
};

// Function declarations
std::vector<std::pair<char, char>> kruskalMST(const std::vector<std::vector<double>>& graph);
std::pair<double, std::vector<int>> tsp(const std::vector<std::vector<double>>& graph);
std::pair<int, int> findNearestCentral(std::pair<int, int> newHouse, const std::vector<std::pair<int, int>>& centrals);

#endif // HEADERTEST_H