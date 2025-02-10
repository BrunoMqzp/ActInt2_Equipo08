#ifndef METODOS_TEST
#define METODOS_TEST

#include <vector>
#include <utility> 
#include <algorithm> 
#include <limits> 
#include <cmath> 

// Estructura para representar una arista en el grafo
struct Edge {
    int u, v;
    double weight;
    bool operator<(const Edge& other) const {
        return weight < other.weight;
    }
};

// Función para encontrar el representante de un conjunto en el algoritmo de Kruskal
int find(std::vector<int>& parent, int i) {
    if (parent[i] != i)
        parent[i] = find(parent, parent[i]);
    return parent[i];
}

// Función para unir dos conjuntos en el algoritmo de Kruskal
void unionSets(std::vector<int>& parent, std::vector<int>& rank, int x, int y) {
    int rootX = find(parent, x);
    int rootY = find(parent, y);
    if (rootX != rootY) {
        if (rank[rootX] > rank[rootY])
            parent[rootY] = rootX;
        else if (rank[rootX] < rank[rootY])
            parent[rootX] = rootY;
        else {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
    }
}

// Algoritmo de Kruskal para encontrar el árbol de expansión mínima
std::vector<std::pair<char, char>> kruskalMST(const std::vector<std::vector<double>>& graph) {
    int N = graph.size();
    std::vector<Edge> edges;
    std::vector<std::pair<char, char>> result;

    // Convertir la matriz de adyacencia en una lista de aristas
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            if (graph[i][j] > 0) {
                edges.push_back({ i, j, graph[i][j] });
            }
        }
    }

    std::sort(edges.begin(), edges.end());

    std::vector<int> parent(N), rank(N, 0);
    for (int i = 0; i < N; i++)
        parent[i] = i;

    for (const auto& edge : edges) {
        if (find(parent, edge.u) != find(parent, edge.v)) {
            result.push_back({ char('A' + edge.u), char('A' + edge.v) });
            unionSets(parent, rank, edge.u, edge.v);
        }
    }
    return result;
}

// Resolver el problema del viajante usando fuerza bruta (TSP)
std::pair<double, std::vector<int>> tsp(const std::vector<std::vector<double>>& graph) {
    int N = graph.size();
    std::vector<int> cities(N);
    for (int i = 0; i < N; i++) cities[i] = i;

    double minCost = std::numeric_limits<double>::max();
    std::vector<int> bestPath;

    do {
        double currentCost = 0;
        for (int i = 0; i < N - 1; i++) {
            currentCost += graph[cities[i]][cities[i + 1]];
        }
        currentCost += graph[cities[N - 1]][cities[0]];

        if (currentCost < minCost) {
            minCost = currentCost;
            bestPath = cities;
        }
    } while (std::next_permutation(cities.begin() + 1, cities.end()));

    return { minCost, bestPath };
}

// Búsqueda de la central más cercana
std::pair<int, int> findNearestCentral(std::pair<int, int> newHouse, const std::vector<std::pair<int, int>>& centrals) {
    double minDist = std::numeric_limits<double>::max();
    std::pair<int, int> nearestCentral = { -1, -1 };

    for (const auto& central : centrals) {
        double dist = std::sqrt(std::pow(newHouse.first - central.first, 2) + std::pow(newHouse.second - central.second, 2));
        if (dist < minDist) {
            minDist = dist;
            nearestCentral = central;
        }
    }
    return nearestCentral;
}

#endif 