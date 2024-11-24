#include "../../inc/Algorithms/GreedyTSPSolver.h"
#include <iostream>
#include <limits>
#include <cmath>
#include <algorithm>
#include <numeric>

GreedyTSPSolver::GreedyTSPSolver(const AdjacencyMatrix& matrix_, size_t startCity_)
    : matrix(matrix_), startCity(startCity_), totalDistance(0) {}

void GreedyTSPSolver::solve() {
    findGreedyPath();
}

GreedyTSPStatistics GreedyTSPSolver::runMultiple(int iterations) {
    std::vector<float> distances;
    distances.reserve(iterations);

    for (int i = 0; i < iterations; ++i) {
        solve();
        distances.push_back(getTotalDistance());
    }

    float bestDistance = *std::min_element(distances.begin(), distances.end());
    float worstDistance = *std::max_element(distances.begin(), distances.end());
    float sum = std::accumulate(distances.begin(), distances.end(), 0.0f);
    float averageDistance = sum / iterations;

    float variance = 0.0f;
    for (float distance : distances) {
        variance += (distance - averageDistance) * (distance - averageDistance);
    }
    variance /= iterations;
    float standardDeviation = std::sqrt(variance);

    return { bestDistance, worstDistance, averageDistance, standardDeviation };
}

void GreedyTSPSolver::findGreedyPath() {
    size_t citiesNumber = matrix.citiesNumber;
    std::vector<bool> visited(citiesNumber, false);

    path.clear();
    totalDistance = 0;
    path.push_back(startCity);
    visited[startCity] = true;
    size_t currentCity = startCity;

    for (size_t i = 1; i < citiesNumber; ++i) {
        float minDistance = std::numeric_limits<float>::infinity();
        size_t nextCity = startCity;

        for (size_t city = 0; city < citiesNumber; ++city) {
            if (!visited[city] && matrix.getValue(currentCity, city) < minDistance) {
                minDistance = matrix.getValue(currentCity, city);
                nextCity = city;
            }
        }

        path.push_back(nextCity);
        visited[nextCity] = true;
        totalDistance += minDistance;
        currentCity = nextCity;
    }

    path.push_back(startCity);
    totalDistance += matrix.getValue(currentCity, startCity);
}

float GreedyTSPSolver::getTotalDistance() const {
    return totalDistance;
}

const std::vector<size_t>& GreedyTSPSolver::getPath() const {
    return path;
}

void GreedyTSPSolver::printSolution() const {
    std::cout << "Greedy TSP path: ";
    for (size_t city : path) {
        std::cout << city << " ";
    }
    std::cout << "\nTotal Distance: " << totalDistance << "\n";
}
