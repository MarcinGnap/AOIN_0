#include "../../inc/Utils/Tests.h"

#include "../../inc/Utils/Loader.h"

Tests::Tests()
{
    this->fileWritter.openFile("out/results.csv");
}

Tests::~Tests()
{

    if(this->matrix != nullptr)
        delete this->matrix;

    if(this->returnPath != nullptr)
        delete this->returnPath;
    
}

void Tests::performAutoTests()
{
    task3Tests();
}


void Tests::task3Tests()
{
    // task3MutationProbTest();
    // task3CrossoverProbTest();
    // task3PopulationsSizeTest();
    task3TestsFinal();

    // double stopTimes[] = {30.0, 60.0, 90.0};
    // double basicstopTimes = 90.0;
    // size_t populations[] = {50, 100, 300};
    // size_t basicpopulations = 300;
    // CrossoverType crossTypes[] = {CrossoverType::PMX, CrossoverType::OX};
    // CrossoverType basiccrossTypes = CrossoverType::OX;
    // MutationType mutationTypes[] = {MutationType::Swap, MutationType::Insert};
    // MutationType basicmutationTypes = MutationType::Swap;
    // char selectionTypes[] = {'t', 'r'};
    // char basicselectionTypes = 't';
    // int tournamentSize[] = {3, 5, 10};
    // int basictournamentSize = 5;
    // char initializationTypes[] = {'z', 'l'};
    // char basicinitializationTypes = 'l';
    // double mutationProbs[] = {0.01, 0.05, 0.1};
    // double basicmutationProbs = 0.01;
    // double crossoverProbs[] = {0.5, 0.7, 0.9};
    // double basiccrossoverProbs = 0.8;
    // std::string fileNames[] = {"berlin52.tsp", "kroA100.tsp", "kroA150.tsp", "kroA200.tsp", "fl417.tsp", "gr666.tsp"};
    //
    // std::cout << "All tests started\n";
    //
    // std::cout << "Population size test started\n";
    // for(int i = 0; i < sizeof(fileNames); ++i) {
    //     GeneticAlgorithm ga;
    //     Loader loader;
    //
    //     if(this->matrix != nullptr)
    //         delete this->matrix;
    //
    //     loader.openTSPFile(fileNames[i]);
    //     this->matrix = new AdjacencyMatrix(loader.verticesNumber, loader.convertToAM());
    //         GeneticAlgorithm::setPopulationSize(50);
    //         GeneticAlgorithm::setStopTime(90.0);
    //         GeneticAlgorithm::setCrossoverType(CrossoverType::OX);
    //         GeneticAlgorithm::setMutationType(MutationType::Swap);
    //         GeneticAlgorithm::setSelectionType('t');
    //         GeneticAlgorithm::setTournamentSize(5);
    //         GeneticAlgorithm::setInitializationType('l');
    //         GeneticAlgorithm::setMutationProbability(0.01);
    //         GeneticAlgorithm::setCrossoverProbability(0.8);
    //
    //         if(this->returnPath != nullptr)
    //             delete this->returnPath;
    //
    //         this->returnPath = ga.solveTSP(*matrix);
    //         fileWritter.writeextendedGAIntoFile(fileNames[i], basicmutationTypes, basicmutationProbs, basiccrossTypes, basiccrossoverProbs, returnPath->getTotalCost(), basicpopulations, basicstopTimes, basicselectionTypes, basictournamentSize, basicinitializationTypes);
    //
    //     std::cout << "File " << fileNames[i] << " done\n";
    // }
    // std::cout << "Population size test done\n";
}


void Tests::task3TestsFinal() {

    double stopTimes[] = {30.0, 60.0, 90.0};
    double basicstopTimes = 100.0;
    size_t populations[] = {50, 100, 300};
    size_t basicpopulations = 100;
    int generaions[] = {50, 100, 300};
    int basicgeneraions = 50;
    CrossoverType crossTypes[] = {CrossoverType::PMX, CrossoverType::OX};
    CrossoverType basiccrossTypes = CrossoverType::OX;
    MutationType mutationTypes[] = {MutationType::Swap, MutationType::Insert};
    MutationType basicmutationTypes = MutationType::Insert;
    char selectionTypes[] = {'t', 'r'};
    char basicselectionTypes = 't';
    int tournamentSize[] = {3, 5, 10};
    int basictournamentSize = 5;
    char initializationTypes[] = {'z', 'l'};
    char basicinitializationTypes = 'l';
    double mutationProbs[] = {0.01, 0.05, 0.1};
    double basicmutationProbs = 0.1;
    double crossoverProbs[] = {0.5, 0.7, 0.9};
    double basiccrossoverProbs = 0.7;
    std::string fileNames[] = {"berlin52.tsp", "kroA100.tsp", "kroA150.tsp", "kroA200.tsp", "fl417.tsp", "gr666.tsp"};

    std::cout << "All tests started\n";

    task3GenerationTestnew(generaions,  basicpopulations,  basicstopTimes,  basiccrossTypes,  basicmutationTypes,  basicselectionTypes,  basictournamentSize,  basicinitializationTypes,  basicmutationProbs,  basiccrossoverProbs,  fileNames);
    // task3PopulationsSizeTestnew(basicgeneraions, populations,  basicstopTimes,  basiccrossTypes,  basicmutationTypes,  basicselectionTypes,  basictournamentSize,  basicinitializationTypes,  basicmutationProbs,  basiccrossoverProbs,  fileNames);
    // task3SelectionTestnew(basicgeneraions,  basicpopulations,  basicstopTimes,  basiccrossTypes,  basicmutationTypes,  selectionTypes,  basictournamentSize,  basicinitializationTypes,  basicmutationProbs,  basiccrossoverProbs,  fileNames);
    // task3TournamentTestnew(basicgeneraions,  basicpopulations,  basicstopTimes,  basiccrossTypes,  basicmutationTypes,  basicselectionTypes,  tournamentSize,  basicinitializationTypes,  basicmutationProbs,  basiccrossoverProbs,  fileNames);
    // task3InicjalizationTestnew(basicgeneraions,  basicpopulations,  basicstopTimes,  basiccrossTypes,  basicmutationTypes,  basicselectionTypes,  basictournamentSize,  initializationTypes,  basicmutationProbs,  basiccrossoverProbs,  fileNames);
    // task3CrossoverTestnew(basicgeneraions,  basicpopulations,  basicstopTimes,  crossTypes,  basicmutationTypes,  basicselectionTypes,  basictournamentSize,  basicinitializationTypes,  basicmutationProbs,  basiccrossoverProbs,  fileNames);
    // task3CrossoverProbTestnew(basicgeneraions,  basicpopulations,  basicstopTimes,  basiccrossTypes,  basicmutationTypes,  basicselectionTypes,  basictournamentSize,  basicinitializationTypes,  basicmutationProbs,  crossoverProbs,  fileNames);
    // task3MutationTestnew(basicgeneraions,  basicpopulations,  basicstopTimes,  basiccrossTypes,  mutationTypes,  basicselectionTypes,  basictournamentSize,  basicinitializationTypes,  basicmutationProbs,  basiccrossoverProbs,  fileNames);
    // task3MutationProbTestnew(basicgeneraions,  basicpopulations,  basicstopTimes,  basiccrossTypes,  basicmutationTypes,  basicselectionTypes,  basictournamentSize,  basicinitializationTypes,  mutationProbs,  basiccrossoverProbs,  fileNames);
    // task3GenerationNumberTestnew(basicgeneraions,  basicpopulations,  stopTimes,  basiccrossTypes,  basicmutationTypes,  basicselectionTypes,  basictournamentSize,  basicinitializationTypes,  basicmutationProbs,  basiccrossoverProbs,  fileNames);

    std::cout << "ALL tests done\n";
}

void Tests::task3PopulationsSizeTestnew(int basicgeneraions, size_t* populations, double basicstopTimes, CrossoverType basiccrossTypes, MutationType basicmutationTypes, char basicselectionTypes, int basictournamentSize, char basicinitializationTypes, double basicmutationProbs, double basiccrossoverProbs, std::string* fileNames){

    GeneticAlgorithm ga;
    std::cout << "Population size test started\n";
    for(int i = 0; i < 6; ++i) {
        Loader loader;

        if(this->matrix != nullptr)
            delete this->matrix;

        loader.openTSPFile(fileNames[i]);
        this->matrix = new AdjacencyMatrix(loader.verticesNumber, loader.convertToAM());
        for(int j = 0; j < 3; ++j) {
            for(int ii = 0; ii < 10; ++ii) {
                GeneticAlgorithm::setPopulationSize(populations[j]);
                GeneticAlgorithm::setStopTime(basicstopTimes);
                GeneticAlgorithm::setCrossoverType(basiccrossTypes);
                GeneticAlgorithm::setMutationType(basicmutationTypes);
                GeneticAlgorithm::setSelectionType(basicselectionTypes);
                GeneticAlgorithm::setTournamentSize(basictournamentSize);
                GeneticAlgorithm::setInitializationType(basicinitializationTypes);
                GeneticAlgorithm::setMutationProbability(basicmutationProbs);
                GeneticAlgorithm::setCrossoverProbability(basiccrossoverProbs);
                GeneticAlgorithm::setGenereationNumber(basicgeneraions);

                if(this->returnPath != nullptr)
                    delete this->returnPath;

                this->returnPath = ga.solveTSP(*matrix);
                fileWritter.writeextendedGAIntoFile(fileNames[i], basicmutationTypes, basicmutationProbs, basiccrossTypes, basiccrossoverProbs, returnPath->getTotalCost(), populations[j], basicstopTimes, basicselectionTypes, basictournamentSize, basicinitializationTypes);

            }
        }
        std::cout << "File " << fileNames[i] << " done\n";
    }
    std::cout << "Population size test done\n";
}

void Tests::task3SelectionTestnew(int basicgeneraions, size_t basicpopulations, double basicstopTimes, CrossoverType basiccrossTypes, MutationType basicmutationTypes, char* selectionTypes, int basictournamentSize, char basicinitializationTypes, double basicmutationProbs, double basiccrossoverProbs, std::string* fileNames){

    GeneticAlgorithm ga;
    std::cout << "Selection type test started\n";
    for(int i = 0; i < 6; ++i) {
        Loader loader;

        if(this->matrix != nullptr)
            delete this->matrix;

        loader.openTSPFile(fileNames[i]);
        this->matrix = new AdjacencyMatrix(loader.verticesNumber, loader.convertToAM());
        for(int j = 0; j < 2; ++j) {
            for(int ii = 0; ii < 10; ++ii) {
                GeneticAlgorithm::setPopulationSize(basicpopulations);
                GeneticAlgorithm::setStopTime(basicstopTimes);
                GeneticAlgorithm::setCrossoverType(basiccrossTypes);
                GeneticAlgorithm::setMutationType(basicmutationTypes);
                GeneticAlgorithm::setSelectionType(selectionTypes[j]);
                GeneticAlgorithm::setTournamentSize(basictournamentSize);
                GeneticAlgorithm::setInitializationType(basicinitializationTypes);
                GeneticAlgorithm::setMutationProbability(basicmutationProbs);
                GeneticAlgorithm::setCrossoverProbability(basiccrossoverProbs);
                GeneticAlgorithm::setGenereationNumber(basicgeneraions);

                if(this->returnPath != nullptr)
                    delete this->returnPath;

                this->returnPath = ga.solveTSP(*matrix);
                fileWritter.writeextendedGAIntoFile(fileNames[i], basicmutationTypes, basicmutationProbs, basiccrossTypes, basiccrossoverProbs, returnPath->getTotalCost(), basicpopulations, basicstopTimes, selectionTypes[j], basictournamentSize, basicinitializationTypes);
            }
        }
        std::cout << "File " << fileNames[i] << " done\n";
    }
    std::cout << "Selection type test done\n";
}

void Tests::task3TournamentTestnew(int basicgeneraions, size_t basicpopulations, double basicstopTimes, CrossoverType basiccrossTypes, MutationType basicmutationTypes, char basicselectionTypes, int* tournamentSize, char basicinitializationTypes, double basicmutationProbs, double basiccrossoverProbs, std::string* fileNames){

    GeneticAlgorithm ga;
    std::cout << "Tournament size test started\n";
    for(int i = 0; i < 6; ++i) {
        Loader loader;

        if(this->matrix != nullptr)
            delete this->matrix;

        loader.openTSPFile(fileNames[i]);
        this->matrix = new AdjacencyMatrix(loader.verticesNumber, loader.convertToAM());
        for(int j = 0; j < 3; ++j) {
            for(int ii = 0; ii < 10; ++ii) {
                GeneticAlgorithm::setPopulationSize(basicpopulations);
                GeneticAlgorithm::setStopTime(basicstopTimes);
                GeneticAlgorithm::setCrossoverType(basiccrossTypes);
                GeneticAlgorithm::setMutationType(basicmutationTypes);
                GeneticAlgorithm::setSelectionType(basicselectionTypes);
                GeneticAlgorithm::setTournamentSize(tournamentSize[j]);
                GeneticAlgorithm::setInitializationType(basicinitializationTypes);
                GeneticAlgorithm::setMutationProbability(basicmutationProbs);
                GeneticAlgorithm::setCrossoverProbability(basiccrossoverProbs);
                GeneticAlgorithm::setGenereationNumber(basicgeneraions);

                if(this->returnPath != nullptr)
                    delete this->returnPath;

                this->returnPath = ga.solveTSP(*matrix);
                fileWritter.writeextendedGAIntoFile(fileNames[i], basicmutationTypes, basicmutationProbs, basiccrossTypes, basiccrossoverProbs, returnPath->getTotalCost(), basicpopulations, basicstopTimes, basicselectionTypes, tournamentSize[j], basicinitializationTypes);
            }
        }
        std::cout << "File " << fileNames[i] << " done\n";
    }
    std::cout << "Tournament size test done\n";
}

void Tests::task3InicjalizationTestnew(int basicgeneraions, size_t basicpopulations, double basicstopTimes, CrossoverType basiccrossTypes, MutationType basicmutationTypes, char basicselectionTypes, int basictournamentSize, char* initializationTypes, double basicmutationProbs, double basiccrossoverProbs, std::string* fileNames){

    GeneticAlgorithm ga;
    std::cout << "Initialization type test started\n";
    for(int i = 0; i < 6; ++i) {
        Loader loader;

        if(this->matrix != nullptr)
            delete this->matrix;

        loader.openTSPFile(fileNames[i]);
        this->matrix = new AdjacencyMatrix(loader.verticesNumber, loader.convertToAM());
        for(int j = 0; j < 2; ++j) {
            for(int ii = 0; ii < 10; ++ii) {
                GeneticAlgorithm::setPopulationSize(basicpopulations);
                GeneticAlgorithm::setStopTime(basicstopTimes);
                GeneticAlgorithm::setCrossoverType(basiccrossTypes);
                GeneticAlgorithm::setMutationType(basicmutationTypes);
                GeneticAlgorithm::setSelectionType(basicselectionTypes);
                GeneticAlgorithm::setTournamentSize(basictournamentSize);
                GeneticAlgorithm::setInitializationType(initializationTypes[j]);
                GeneticAlgorithm::setMutationProbability(basicmutationProbs);
                GeneticAlgorithm::setCrossoverProbability(basiccrossoverProbs);
                GeneticAlgorithm::setGenereationNumber(basicgeneraions);

                if(this->returnPath != nullptr)
                    delete this->returnPath;

                this->returnPath = ga.solveTSP(*matrix);
                fileWritter.writeextendedGAIntoFile(fileNames[i], basicmutationTypes, basicmutationProbs, basiccrossTypes, basiccrossoverProbs, returnPath->getTotalCost(), basicpopulations, basicstopTimes, basicselectionTypes, basictournamentSize, initializationTypes[j]);
            }
        }
        std::cout << "File " << fileNames[i] << " done\n";
    }
    std::cout << "Initialization type test done\n";
}

void Tests::task3CrossoverTestnew(int basicgeneraions, size_t basicpopulations, double basicstopTimes, CrossoverType* crossTypes, MutationType basicmutationTypes, char basicselectionTypes, int basictournamentSize, char basicinitializationTypes, double basicmutationProbs, double basiccrossoverProbs, std::string* fileNames){

    GeneticAlgorithm ga;
    std::cout << "Crossover types test started\n";
    for(int i = 0; i < 6; ++i) {
        Loader loader;

        if(this->matrix != nullptr)
            delete this->matrix;

        loader.openTSPFile(fileNames[i]);
        this->matrix = new AdjacencyMatrix(loader.verticesNumber, loader.convertToAM());
        for(int j = 0; j < 2; ++j) {
            for(int ii = 0; ii < 10; ++ii) {
                GeneticAlgorithm::setPopulationSize(basicpopulations);
                GeneticAlgorithm::setStopTime(basicstopTimes);
                GeneticAlgorithm::setCrossoverType(crossTypes[j]);
                GeneticAlgorithm::setMutationType(basicmutationTypes);
                GeneticAlgorithm::setSelectionType(basicselectionTypes);
                GeneticAlgorithm::setTournamentSize(basictournamentSize);
                GeneticAlgorithm::setInitializationType(basicinitializationTypes);
                GeneticAlgorithm::setMutationProbability(basicmutationProbs);
                GeneticAlgorithm::setCrossoverProbability(basiccrossoverProbs);
                GeneticAlgorithm::setGenereationNumber(basicgeneraions);

                if(this->returnPath != nullptr)
                    delete this->returnPath;

                this->returnPath = ga.solveTSP(*matrix);
                fileWritter.writeextendedGAIntoFile(fileNames[i], basicmutationTypes, basicmutationProbs, crossTypes[j], basiccrossoverProbs, returnPath->getTotalCost(), basicpopulations, basicstopTimes, basicselectionTypes, basictournamentSize, basicinitializationTypes);
            }
        }
        std::cout << "File " << fileNames[i] << " done\n";
    }
    std::cout << "Crossover types test done\n";
}

void Tests::task3CrossoverProbTestnew(int basicgeneraions, size_t basicpopulations, double basicstopTimes, CrossoverType basiccrossTypes, MutationType basicmutationTypes, char basicselectionTypes, int basictournamentSize, char basicinitializationTypes, double basicmutationProbs, double* crossoverProbs, std::string* fileNames){

    GeneticAlgorithm ga;
    std::cout << "Crossover prob test started\n";
    for(int i = 0; i < 6; ++i) {
        Loader loader;

        if(this->matrix != nullptr)
            delete this->matrix;

        loader.openTSPFile(fileNames[i]);
        this->matrix = new AdjacencyMatrix(loader.verticesNumber, loader.convertToAM());
        for(int j = 0; j < 3; ++j) {
            for(int ii = 0; ii < 10; ++ii) {
                GeneticAlgorithm::setPopulationSize(basicpopulations);
                GeneticAlgorithm::setStopTime(basicstopTimes);
                GeneticAlgorithm::setCrossoverType(basiccrossTypes);
                GeneticAlgorithm::setMutationType(basicmutationTypes);
                GeneticAlgorithm::setSelectionType(basicselectionTypes);
                GeneticAlgorithm::setTournamentSize(basictournamentSize);
                GeneticAlgorithm::setInitializationType(basicinitializationTypes);
                GeneticAlgorithm::setMutationProbability(basicmutationProbs);
                GeneticAlgorithm::setCrossoverProbability(crossoverProbs[j]);
                GeneticAlgorithm::setGenereationNumber(basicgeneraions);

                if(this->returnPath != nullptr)
                    delete this->returnPath;

                this->returnPath = ga.solveTSP(*matrix);
                fileWritter.writeextendedGAIntoFile(fileNames[i], basicmutationTypes, basicmutationProbs, basiccrossTypes, crossoverProbs[j], returnPath->getTotalCost(), basicpopulations, basicstopTimes, basicselectionTypes, basictournamentSize, basicinitializationTypes);
            }
        }
        std::cout << "File " << fileNames[i] << " done\n";
    }
    std::cout << "Crossover prob test done\n";
}


void Tests::task3MutationTestnew(int basicgeneraions, size_t basicpopulations, double basicstopTimes, CrossoverType basiccrossTypes, MutationType* mutationTypes, char basicselectionTypes, int basictournamentSize, char basicinitializationTypes, double basicmutationProbs, double basiccrossoverProbs, std::string* fileNames){

    GeneticAlgorithm ga;
    std::cout << "Crossover types test started\n";
    for(int i = 0; i < 6; ++i) {
        Loader loader;

        if(this->matrix != nullptr)
            delete this->matrix;

        loader.openTSPFile(fileNames[i]);
        this->matrix = new AdjacencyMatrix(loader.verticesNumber, loader.convertToAM());
        for(int j = 0; j < 2; ++j) {
            for(int ii = 0; ii < 10; ++ii) {
                GeneticAlgorithm::setPopulationSize(basicpopulations);
                GeneticAlgorithm::setStopTime(basicstopTimes);
                GeneticAlgorithm::setCrossoverType(basiccrossTypes);
                GeneticAlgorithm::setMutationType(mutationTypes[j]);
                GeneticAlgorithm::setSelectionType(basicselectionTypes);
                GeneticAlgorithm::setTournamentSize(basictournamentSize);
                GeneticAlgorithm::setInitializationType(basicinitializationTypes);
                GeneticAlgorithm::setMutationProbability(basicmutationProbs);
                GeneticAlgorithm::setCrossoverProbability(basiccrossoverProbs);
                GeneticAlgorithm::setGenereationNumber(basicgeneraions);

                if(this->returnPath != nullptr)
                    delete this->returnPath;

                this->returnPath = ga.solveTSP(*matrix);
                fileWritter.writeextendedGAIntoFile(fileNames[i], mutationTypes[j], basicmutationProbs, basiccrossTypes, basiccrossoverProbs, returnPath->getTotalCost(), basicpopulations, basicstopTimes, basicselectionTypes, basictournamentSize, basicinitializationTypes);
            }
        }
        std::cout << "File " << fileNames[i] << " done\n";
    }
    std::cout << "Crossover types test done\n";
}

void Tests::task3GenerationTestnew(int *generaions, size_t basicpopulations, double basicstopTimes,
    CrossoverType basiccrossTypes, MutationType basicmutationTypes, char basicselectionTypes, int basictournamentSize,
    char basicinitializationTypes, double basicmutationProbs, double basiccrossoverProbs, std::string *fileNames) {

    GeneticAlgorithm ga;
    std::cout << "Generation number test started\n";
    for(int i = 0; i < 6; ++i) {
        Loader loader;

        if(this->matrix != nullptr)
            delete this->matrix;

        loader.openTSPFile(fileNames[i]);
        this->matrix = new AdjacencyMatrix(loader.verticesNumber, loader.convertToAM());
        for(int j = 0; j < 3; ++j) {
            for(int ii = 0; ii < 10; ++ii) {
                GeneticAlgorithm::setPopulationSize(basicpopulations);
                GeneticAlgorithm::setStopTime(basicstopTimes);
                GeneticAlgorithm::setCrossoverType(basiccrossTypes);
                GeneticAlgorithm::setMutationType(basicmutationTypes);
                GeneticAlgorithm::setSelectionType(basicselectionTypes);
                GeneticAlgorithm::setTournamentSize(basictournamentSize);
                GeneticAlgorithm::setInitializationType(basicinitializationTypes);
                GeneticAlgorithm::setMutationProbability(basicmutationProbs);
                GeneticAlgorithm::setCrossoverProbability(basiccrossoverProbs);
                GeneticAlgorithm::setGenereationNumber(generaions[j]);

                if(this->returnPath != nullptr)
                    delete this->returnPath;

                this->returnPath = ga.solveTSP(*matrix);
                fileWritter.writeextendedGAIntoFile(fileNames[i], basicmutationTypes, basicmutationProbs, basiccrossTypes, basiccrossoverProbs, returnPath->getTotalCost(), basicpopulations, basicstopTimes, basicselectionTypes, basictournamentSize, basicinitializationTypes);
            }
        }
        std::cout << "File " << fileNames[i] << " done\n";
    }
    std::cout << "Generation number test done\n";
}

void Tests::task3MutationProbTestnew(int basicgeneraions, size_t basicpopulations, double basicstopTimes, CrossoverType basiccrossTypes, MutationType basicmutationTypes, char basicselectionTypes, int basictournamentSize, char basicinitializationTypes, double* mutationProbs, double basiccrossoverProbs, std::string* fileNames){

    GeneticAlgorithm ga;
    std::cout << "Mutation prob test started\n";
    for(int i = 0; i < 6; ++i) {
        Loader loader;

        if(this->matrix != nullptr)
            delete this->matrix;

        loader.openTSPFile(fileNames[i]);
        this->matrix = new AdjacencyMatrix(loader.verticesNumber, loader.convertToAM());
        for(int j = 0; j < 3; ++j) {
            for(int ii = 0; ii < 10; ++ii) {
                GeneticAlgorithm::setPopulationSize(basicpopulations);
                GeneticAlgorithm::setStopTime(basicstopTimes);
                GeneticAlgorithm::setCrossoverType(basiccrossTypes);
                GeneticAlgorithm::setMutationType(basicmutationTypes);
                GeneticAlgorithm::setSelectionType(basicselectionTypes);
                GeneticAlgorithm::setTournamentSize(basictournamentSize);
                GeneticAlgorithm::setInitializationType(basicinitializationTypes);
                GeneticAlgorithm::setMutationProbability(mutationProbs[j]);
                GeneticAlgorithm::setCrossoverProbability(basiccrossoverProbs);
                GeneticAlgorithm::setGenereationNumber(basicgeneraions);

                if(this->returnPath != nullptr)
                    delete this->returnPath;

                this->returnPath = ga.solveTSP(*matrix);
                fileWritter.writeextendedGAIntoFile(fileNames[i], basicmutationTypes, mutationProbs[j], basiccrossTypes, basiccrossoverProbs, returnPath->getTotalCost(), basicpopulations, basicstopTimes, basicselectionTypes, basictournamentSize, basicinitializationTypes);
            }
        }
        std::cout << "File " << fileNames[i] << " done\n";
    }
    std::cout << "Mutation prob test done\n";
}

void Tests::task3GenerationNumberTestnew(int basicgeneraions, size_t basicpopulations, double* stopTimes, CrossoverType basiccrossTypes, MutationType basicmutationTypes, char basicselectionTypes, int basictournamentSize, char basicinitializationTypes, double basicmutationProbs, double basiccrossoverProbs, std::string* fileNames) {

    GeneticAlgorithm ga;
    std::cout << "Generations number test started\n";
    for(int i = 0; i < 6; ++i) {
        Loader loader;

        if(this->matrix != nullptr)
            delete this->matrix;

        loader.openTSPFile(fileNames[i]);
        this->matrix = new AdjacencyMatrix(loader.verticesNumber, loader.convertToAM());
        for(int j = 0; j < 3; ++j) {
            for(int ii = 0; ii < 10; ++ii) {
                GeneticAlgorithm::setPopulationSize(basicpopulations);
                GeneticAlgorithm::setStopTime(stopTimes[j]);
                GeneticAlgorithm::setCrossoverType(basiccrossTypes);
                GeneticAlgorithm::setMutationType(basicmutationTypes);
                GeneticAlgorithm::setSelectionType(basicselectionTypes);
                GeneticAlgorithm::setTournamentSize(basictournamentSize);
                GeneticAlgorithm::setInitializationType(basicinitializationTypes);
                GeneticAlgorithm::setMutationProbability(basicmutationProbs);
                GeneticAlgorithm::setCrossoverProbability(basiccrossoverProbs);
                GeneticAlgorithm::setGenereationNumber(basicgeneraions);

                if(this->returnPath != nullptr)
                    delete this->returnPath;

                this->returnPath = ga.solveTSP(*matrix);
                fileWritter.writeextendedGAIntoFile(fileNames[i], basicmutationTypes, basicmutationProbs, basiccrossTypes, basiccrossoverProbs, returnPath->getTotalCost(), basicpopulations, stopTimes[j], basicselectionTypes, basictournamentSize, basicinitializationTypes);
            }
        }
        std::cout << "File " << fileNames[i] << " done\n";
    }
    std::cout << "Generations number test done\n";
}


void Tests::createMatrix(std::string fileName) {
    Loader loader;

    if(this->matrix != nullptr)
        delete this->matrix;

    loader.openTSPFile(fileName);
    this->matrix = new AdjacencyMatrix(loader.verticesNumber, loader.convertToAM());
}

void Tests::setVariables(double *stopTimes, double basicstopTimes, size_t *populations, size_t basicpopulations,
    int *generaions, int basicgeneraions, CrossoverType *crossTypes, CrossoverType basiccrossTypes,
    MutationType *mutationTypes, MutationType basicmutationTypes, char *selectionTypes, char basicselectionTypes,
    int *tournamentSize, int basictournamentSize, char *initializationTypes, char basicinitializationTypes,
    double *mutationProbs, double basicmutationProbs, double *crossoverProbs, double basiccrossoverProbs,
    std::string *fileNames) {
    GeneticAlgorithm::setPopulationSize(basicpopulations);
    GeneticAlgorithm::setStopTime(basicstopTimes);
    GeneticAlgorithm::setGenereationNumber(basicgeneraions);
    GeneticAlgorithm::setCrossoverType(basiccrossTypes);
    GeneticAlgorithm::setMutationType(basicmutationTypes);
    GeneticAlgorithm::setSelectionType(basicselectionTypes);
    GeneticAlgorithm::setTournamentSize(basictournamentSize);
    GeneticAlgorithm::setInitializationType(basicinitializationTypes);
    GeneticAlgorithm::setMutationProbability(basicmutationProbs);
    GeneticAlgorithm::setCrossoverProbability(basiccrossoverProbs);
}

void Tests::task3PopulationsSizeTest()
{
    GeneticAlgorithm ga;

    double stopTimes[] = {30.0, 60.0, 90.0};
    std::string fileNames[] = {"berlin52.tsp", "kroA100.tsp", "kroA150.tsp", "kroA200.tsp", "fl417.tsp", "gr666.tsp"};
    int bestKnownValues[] = {1776, 2755, 2465};
    size_t populations[] = {50, 100, 300};

    CrossoverType crossTypes[] = {CrossoverType::PMX, CrossoverType::OX};
    MutationType mutationTypes[] = {MutationType::Swap, MutationType::Insert}; 

    GeneticAlgorithm::setCrossoverProbability(0.8);
    GeneticAlgorithm::setMutationProbability(0.01);

    std::cout << "Population Size test started\n";

    for(int i = 0; i < 6; ++i)
    {
        GeneticAlgorithm::setStopTime(stopTimes[i]);
        Loader loader;

        if(this->matrix != nullptr)
            delete this->matrix;

        loader.openTSPFile(fileNames[i]);
        this->matrix = new AdjacencyMatrix(loader.verticesNumber, loader.convertToAM());
        
        for(int u = 0; u < 3; ++u)
        {
            GeneticAlgorithm::setPopulationSize(populations[u]);

            for(int j = 0; j < 2; ++j)
            {
                GeneticAlgorithm::setCrossoverType(crossTypes[j]);

                for(int k = 0; k < 2; ++k)
                {
                    GeneticAlgorithm::setMutationType(mutationTypes[k]);

                    if(this->returnPath != nullptr)
                        delete this->returnPath;

                    this->returnPath = ga.solveTSP(1, fileNames[i], fileWritter, *matrix);
                }

            }      

            std::cout << "File " << i + 1 << " population size " << u + 1 <<" done\n";  
        }

        std::cout << "File " << i + 1 << " done\n";  
    }

    std::cout << "Population Size test done\n";
}

void Tests::task3CrossoverProbTest()
{
    GeneticAlgorithm ga;

    double stopTimes[] = {30.0, 60.0, 90.0};
    std::string fileNames[] = {"kroA100.tsp", "kroA150.tsp", "kroA200.tsp", "fl417.tsp", "gr666.tsp"};
    int bestKnownValues[] = {1776, 2755, 2465};

    CrossoverType crossTypes[] = {CrossoverType::PMX, CrossoverType::OX};
    MutationType mutationTypes[] = {MutationType::Swap, MutationType::Insert}; 

    // double crossoverProbs[] = {0.3, 0.6, 0.9};
    double crossoverProbs[] = {0.5, 0.7, 0.9};

    GeneticAlgorithm::setPopulationSize(100);
    GeneticAlgorithm::setMutationProbability(0.01);

    std::cout << "Crossover Probability test started\n";

    for(int i = 0; i < 5; ++i)
    {
        Loader loader;
        GeneticAlgorithm::setStopTime(stopTimes[i]);
        // this->fileReader.readFromFile(fileNames[i]);
        loader.openTSPFile(fileNames[i]);\

        if(this->matrix != nullptr)
            delete this->matrix;

        this->matrix = new AdjacencyMatrix(loader.verticesNumber, loader.convertToAM());

        for(int u = 0; u < 3; ++u)
        {
            GeneticAlgorithm::setCrossoverProbability(crossoverProbs[u]);    

            for(int j = 0; j < 2; ++j)
            {
                GeneticAlgorithm::setCrossoverType(crossTypes[j]);

                for(int k = 0; k < 2; ++k)
                {
                    GeneticAlgorithm::setMutationType(mutationTypes[k]);

                    if(this->returnPath != nullptr)
                        delete this->returnPath;

                    this->returnPath = ga.solveTSP(fileNames[i], fileWritter, *matrix);
                }

            }      

            std::cout << "File " << i + 1 << " crossover prob " << u + 1 <<" done\n";  
        }

        std::cout << "File " << i + 1 << " done\n";  
    }

    std::cout << "Crossover Probability test done\n"; 
}

void Tests::task3MutationProbTest()
{
    GeneticAlgorithm ga;
    Loader loader;

    double stopTimes[] = {30.0, 60.0, 90.0};
    std::string fileNames[] = {"berlin52.tsp", "kroA100.tsp", "kroA150.tsp", "kroA200.tsp", "fl417.tsp", "gr666.tsp"};
    int bestKnownValues[] = {1776, 2755, 2465};

    CrossoverType crossTypes[] = {CrossoverType::PMX, CrossoverType::OX};
    MutationType mutationTypes[] = {MutationType::Swap, MutationType::Insert}; 

    double mutationProbs[] = {0.01, 0.05, 0.1};

    GeneticAlgorithm::setPopulationSize(100);
    GeneticAlgorithm::setCrossoverProbability(0.8);

    std::cout << "Mutation Probability test started\n";

    for(int i = 0; i < 6; ++i)
    {
        GeneticAlgorithm::setStopTime(stopTimes[i]);\
        loader.openTSPFile(fileNames[i]);

        if(this->matrix != nullptr)
            delete this->matrix;

        this->matrix = new AdjacencyMatrix(loader.verticesNumber, loader.convertToAM());

        for(int u = 0; u < 3; ++u)
        {
            GeneticAlgorithm::setMutationProbability(mutationProbs[u]);    

            for(int j = 0; j < 2; ++j)
            {
                GeneticAlgorithm::setCrossoverType(crossTypes[j]);

                for(int k = 0; k < 2; ++k)
                {
                    GeneticAlgorithm::setMutationType(mutationTypes[k]);

                    if(this->returnPath != nullptr)
                        delete this->returnPath;

                    this->returnPath = ga.solveTSP(fileNames[i], fileWritter, *matrix);
                }

            }      

            std::cout << "File " << i + 1 << " mutation prob " << u + 1 <<" done\n";  
        }

        std::cout << "File " << i + 1 << " done\n";  
    }

    std::cout << "Mutation Probability test done\n"; 

}
