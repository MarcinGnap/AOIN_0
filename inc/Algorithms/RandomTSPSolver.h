#pragma once
#include <vector>
#include <cstddef>
#include "../../inc/Structures/AdjacencyMatrix.h"

struct RandomTSPStatistics {
    float bestDistance;
    float worstDistance;
    float averageDistance;
    float standardDeviation;
};

class RandomTSPSolver {
private:
    const AdjacencyMatrix& matrix;
    size_t startCity;
    std::vector<size_t> currentPath;
    float currentDistance;

    void generateRandomPath();

public:
    RandomTSPSolver(const AdjacencyMatrix& matrix_, size_t startCity_);

    RandomTSPStatistics runMultiple(int iterations);

    float getCurrentDistance() const;

    const std::vector<size_t>& getCurrentPath() const;

    void printCurrentPath() const;
};