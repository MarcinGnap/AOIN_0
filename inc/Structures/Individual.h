#pragma once

#include "../Structures/AdjacencyMatrix.h"
#include "../Enums/MutationType.h"

#include "../Utils/RandomGenerator.h"

#include <vector>
#include <float.h>

class Individual
{

public:
    Individual() = default;
    explicit Individual(std::vector<int> & chromosome_);
    ~Individual() = default;

    Individual& operator=(const Individual& other_)
    {
        this->chromosome = other_.chromosome;
        this->fitness = other_.fitness;

        return *this;
    }

    void killIndividual();

    void calculateFitness(const AdjacencyMatrix & matrix_, size_t source_);
    void mutate(MutationType mutationType_);

    bool operator<(const Individual& other_)
    {
        return this->fitness < other_.fitness;
    }

    float getFitness() const
    {
        return this->fitness;
    }

    std::vector<int> getChromosome() const 
    {
        return chromosome;
    }

private:
    std::vector<int> chromosome;
    float fitness{FLT_MAX};


};