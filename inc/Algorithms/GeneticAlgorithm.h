#pragma once

#include "TSPSolver.h"

#include "../Enums/CrossoverType.h"

#include "../Structures/Individual.h"

#include "../Utils/CrossoverGenerator.h"
#include "../Utils/FileWritter.h"

#include <vector>
#include <algorithm>

struct PopulationStatistics {
    double bestFitness;
    double worstFitness;
    double averageFitness;
    double standardDeviation;
};

class GeneticAlgorithm : public TSPSolver
{
public:

    GeneticAlgorithm() = default;

    Path * solveTSP(const AdjacencyMatrix & matrix_, size_t sourceCity_ = 0) override;
    Path * solveTenTSP(const AdjacencyMatrix &matrix_, size_t sourceCity_, FileWritter &writter, const std::string &instanceName, int runIndex);

    Path * solveTSP(std::string fileName_, FileWritter &writter_, const AdjacencyMatrix & matrix_, size_t sourceCity_ = 0);
    Path * perfectSolveTSP(std::string fileName_, FileWritter &writter_, const AdjacencyMatrix & matrix_, size_t sourceCity_ = 0);

    Path * solveTSP(size_t  diff_, std::string fileName_, FileWritter &writter_, const AdjacencyMatrix & matrix_);

    static void setStopTime(double stopTime_)
    {
        stopTime = stopTime_;
    }

    static void setPopulationSize(size_t size_)
    {
        populationSize = size_;
    }

    static void setMutationType(MutationType type_)
    {
        mutationType = type_;
    }

    static void setCrossoverType(CrossoverType type_)
    {
        crossoverType = type_;
    }

    static void setMutationProbability(double probability_)
    {
        mutationProbability = probability_;
    }

    static void setCrossoverProbability(double probability_)
    {
        crossoverProbability = probability_;
    }

    static void setSelectionType(char selectionType_)
    {
        selectionType = selectionType_;
    }

    static void setTournamentSize(int tournamentSize_)
    {
        tournamentSize = tournamentSize_;
    }

    static void setGenereationNumber(int genereationNumber_)
    {
        genereationNumber = genereationNumber_;
    }

    static void setInitializationType(char initializationType_)
    {
        initializationType = initializationType_;
    }
private:

    size_t sourceCity{0};
    size_t citiesNumber{0};

    Individual bestOne;

    int bestOnesCrossovers{0};

    std::vector<Individual> population;

    static double mutationProbability;
    static double crossoverProbability;
    static size_t populationSize;

    static MutationType mutationType;
    static CrossoverType crossoverType;
    static char selectionType;
    static int tournamentSize;
    static int genereationNumber;
    static char initializationType;

    static double stopTime;
    Timer timer;

    void setupVariables(const AdjacencyMatrix & matrix_, size_t sourceCity_) override;

    std::vector<int> createGreedyChromosome(const AdjacencyMatrix & matrix_, int startCity);
    void generateFirstPopulation(const AdjacencyMatrix & matrix_);
    std::vector<int> shuffleChromosome(const std::vector<int> & cities_);

    PopulationStatistics calculatePopulationStatistics();
    PopulationStatistics calculatePopulationStatistics2() const;

    void generateNewPopulation(std::vector<Individual> & newPopulation_);
    int rouletteSelection();
    int tournamentSelection(int tournamentSize);

    void crossover(std::vector<Individual> & newPopulation_);
    void executeCrossover(std::vector<int> & chromosome1_, std::vector<int> & chromosome2_);

    void mutate(std::vector<Individual> & newPopulation_);

    void calculatePopulationFitness(const AdjacencyMatrix& matrix_);

    void clearVariables();

};