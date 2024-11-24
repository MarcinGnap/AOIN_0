#pragma once

#include "GraphGenerator.h"
#include "FileReader.h"

#include "../Algorithms/GeneticAlgorithm.h"

class Tests
{
    AdjacencyMatrix* matrix {nullptr};
    Path* returnPath {nullptr};
    Path* best {nullptr};
    Path* worst {nullptr};
    Path* avg {nullptr};

    FileWritter fileWritter;
    FileReader fileReader;
    Timer timer;

    void task1Tests();
    void generateInstance(GraphGenerator& gg_, size_t size_);

    void task2Tests();

    void task3Tests();

    void task3TestsFinal();

    void createMatrix(std::string fileName);

    void setVariables(double* stopTimes, double basicstopTimes, size_t* populations, size_t basicpopulations, int* generaions, int basicgeneraions, CrossoverType* crossTypes, CrossoverType basiccrossTypes, MutationType* mutationTypes, MutationType basicmutationTypes, char* selectionTypes, char basicselectionTypes, int* tournamentSize, int basictournamentSize, char* initializationTypes, char basicinitializationTypes, double* mutationProbs, double basicmutationProbs, double* crossoverProbs, double basiccrossoverProbs, std::string* fileNames);
    void task3PopulationsSizeTestnew(int basicgeneraions, size_t* populations, double basicstopTimes, CrossoverType basiccrossTypes, MutationType basicmutationTypes, char basicselectionTypes, int basictournamentSize, char basicinitializationTypes, double basicmutationProbs, double basiccrossoverProbs, std::string* fileNames);
    void task3SelectionTestnew(int basicgeneraions, size_t basicpopulations, double basicstopTimes, CrossoverType basiccrossTypes, MutationType basicmutationTypes, char* selectionTypes, int basictournamentSize, char basicinitializationTypes, double basicmutationProbs, double basiccrossoverProbs, std::string* fileNames);
    void task3TournamentTestnew(int basicgeneraions, size_t basicpopulations, double basicstopTimes, CrossoverType basiccrossTypes, MutationType basicmutationTypes, char basicselectionTypes, int* tournamentSize, char basicinitializationTypes, double basicmutationProbs, double basiccrossoverProbs, std::string* fileNames);
    void task3InicjalizationTestnew(int basicgeneraions, size_t basicpopulations, double basicstopTimes, CrossoverType basiccrossTypes, MutationType basicmutationTypes, char basicselectionTypes, int basictournamentSize, char* initializationTypes, double basicmutationProbs, double basiccrossoverProbs, std::string* fileNames);
    void task3CrossoverTestnew(int basicgeneraions, size_t basicpopulations, double basicstopTimes, CrossoverType* crossTypes, MutationType basicmutationTypes, char basicselectionTypes, int basictournamentSize, char basicinitializationTypes, double basicmutationProbs, double basiccrossoverProbs, std::string* fileNames);
    void task3CrossoverProbTestnew(int basicgeneraions, size_t basicpopulations, double basicstopTimes, CrossoverType basiccrossTypes, MutationType basicmutationTypes, char basicselectionTypes, int basictournamentSize, char basicinitializationTypes, double basicmutationProbs, double* crossoverProbs, std::string* fileNames);
    void task3MutationProbTestnew(int basicgeneraions, size_t basicpopulations, double basicstopTimes, CrossoverType basiccrossTypes, MutationType basicmutationTypes, char basicselectionTypes, int basictournamentSize, char basicinitializationTypes, double* mutationProbs, double basiccrossoverProbs, std::string* fileNames);
    void task3GenerationNumberTestnew(int basicgeneraions, size_t basicpopulations, double* stopTimes, CrossoverType basiccrossTypes, MutationType basicmutationTypes, char basicselectionTypes, int basictournamentSize, char basicinitializationTypes, double basicmutationProbs, double basiccrossoverProbs, std::string* fileNames);
    void task3MutationTestnew(int basicgeneraions, size_t basicpopulations, double basicstopTimes, CrossoverType basiccrossTypes, MutationType* mutationTypes, char basicselectionTypes, int basictournamentSize, char basicinitializationTypes, double basicmutationProbs, double basiccrossoverProbs, std::string* fileNames);
    void task3GenerationTestnew(int* generaions, size_t basicpopulations, double basicstopTimes, CrossoverType basiccrossTypes, MutationType basicmutationTypes, char basicselectionTypes, int basictournamentSize, char basicinitializationTypes, double basicmutationProbs, double basiccrossoverProbs, std::string* fileNames);

    void task3PopulationsSizeTest();
    void task3CrossoverProbTest();
    void task3MutationProbTest();

public:

    Tests();
    ~Tests();

    void performAutoTests();
};