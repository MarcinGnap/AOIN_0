#include "../../inc/Algorithms/RandomTSPSolver.h"
#include <iostream>
#include <limits>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <random>

RandomTSPSolver::RandomTSPSolver(const AdjacencyMatrix& matrix_, size_t startCity_)
    : matrix(matrix_), startCity(startCity_), currentDistance(0) {
    for (size_t i = 0; i < matrix.citiesNumber; ++i) {
        if (i != startCity) {
            currentPath.push_back(i);
        }
    }
}

void RandomTSPSolver::generateRandomPath() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::shuffle(currentPath.begin(), currentPath.end(), gen);

    currentDistance = 0;
    size_t previousCity = startCity;

    for (size_t city : currentPath) {
        currentDistance += matrix.getValue(previousCity, city);
        previousCity = city;
    }
    currentDistance += matrix.getValue(previousCity, startCity);
}

float RandomTSPSolver::getCurrentDistance() const {
    return currentDistance;
}

const std::vector<size_t>& RandomTSPSolver::getCurrentPath() const {
    return currentPath;
}

void RandomTSPSolver::printCurrentPath() const {
    std::cout << "Random TSP path: " << startCity << " ";
    for (size_t city : currentPath) {
        std::cout << city << " ";
    }
    std::cout << startCity << "\nTotal Distance: " << currentDistance << "\n";
}

RandomTSPStatistics RandomTSPSolver::runMultiple(int iterations) {
    std::vector<float> distances;
    distances.reserve(iterations);

    for (int i = 0; i < iterations; ++i) {
        generateRandomPath();
        distances.push_back(getCurrentDistance());
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
