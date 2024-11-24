#pragma once
#include <vector>
#include <cstddef>
#include "../../inc/Structures/AdjacencyMatrix.h"

struct GreedyTSPStatistics {
    float bestDistance;
    float worstDistance;
    float averageDistance;
    float standardDeviation;
};

class GreedyTSPSolver {
private:
    const AdjacencyMatrix& matrix;
    size_t startCity;
    std::vector<size_t> path;
    float totalDistance;

    void findGreedyPath();

public:
    GreedyTSPSolver(const AdjacencyMatrix& matrix_, size_t startCity_);

    void solve();

    GreedyTSPStatistics runMultiple(int iterations);

    float getTotalDistance() const;

    const std::vector<size_t>& getPath() const;

    void printSolution() const;
};
