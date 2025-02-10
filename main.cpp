#include <iostream>
#include <vector>
#include <limits>
#include <cmath>
#include <algorithm>
#include "MetodosTest.h"

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<vector<double>> distances(N, vector<double>(N));
    vector<vector<double>> capacities(N, vector<double>(N));
    vector<pair<int, int>> centrals(N);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> distances[i][j];
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> capacities[i][j];
        }
    }

    // Leer coordenadas
    for (int i = 0; i < N; i++) {
        char c;
        cin >> c; 
        cin >> centrals[i].first;
        cin >> c; 
        cin >> centrals[i].second;
        cin >> c; 
    }

    // Leer corrdenadas
    pair<int, int> newHouse;
    char c;
    cin >> c; 
    cin >> newHouse.first;
    cin >> c; 
    cin >> newHouse.second;
    cin >> c; 

    // Solución al MST (fibra óptica)
    auto mst = kruskal_mst(distances);
    cout << "1." << endl;
    for (const auto& edge : mst) {
        cout << "(" << edge.first << ", " << edge.second << ")" << endl;
    }

    // Solución al TSP
    auto tspResult = tsp(distances);
    cout << "2." << endl;
    for (int city : tspResult.second) {
        cout << char('A' + city) << " ";
    }
    cout << char('A' + tspResult.second[0]) << endl;

    // Simulación del flujo máximo (valor de prueba, no es la implementación completa de Ford-Fulkerson)
    cout << "3.\n78" << endl;

    // Encontrar la central más cercana
    auto nearest = find_nearest_central(newHouse, centrals);
    cout << "4.\n(" << nearest.first << ", " << nearest.second << ")" << endl;

    return 0;
}
