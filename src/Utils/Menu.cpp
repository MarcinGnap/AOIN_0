#include "../../inc/Utils/Menu.h"

#include "../../inc/Algorithms/RandomTSPSolver.h"
#include "../../inc/Utils/Loader.h"

Menu::Menu()
{
}

Menu::~Menu()
{
    if(this->matrix != nullptr)
        delete this->matrix;

    if(this->result != nullptr)
        delete this->result;
}

void Menu::chooseTestsType()
{
    while(true)
    {
        std::cout << "1. Task 1 - Random\n";
        std::cout << "2. Task 2 - Greedy\n";
        std::cout << "3. Task 3 - Genethic Algorithm\n";
        std::cout << "4. Task 3 - Pretty print\n";
        std::cout << "5. Auto Tests\n";
        std::cout << "6. Random graph generation\n";
        std::cout << "7. Exit\n";

        std::cin >> choice;

        switch(choice) {
            case 1: {
                FileWritter writter;
                writter.openFile("out/results.csv");
                std::string fileNames[] = {"berlin52.tsp", "kroA100.tsp", "kroA150.tsp", "kroA200.tsp", "fl417.tsp", "gr666.tsp"};
                for(int i = 0; i < 6; i++) {
                    Loader loader;
                    int iterations = 300000;
                    loader.openTSPFile(fileNames[i]);
                    AdjacencyMatrix matrixRandom(loader.verticesNumber, loader.convertToAM());
                    // matrixGreedy.printMatrix();

                    RandomTSPSolver solver(matrixRandom, 0);
                    RandomTSPStatistics stats = solver.runMultiple(iterations);
                    // solver.printSolution();
                    writter.writeGreedyIntoFile(fileNames[i], stats.bestDistance, stats.worstDistance, stats.averageDistance, stats.standardDeviation);
                    std:: cout << "Random done " << fileNames[i] << "for " << iterations << " iterations\n";
                }
                break;
            }

            case 2:{
                FileWritter writter;
                writter.openFile("out/results.csv");
                std::string fileNames[] = {"berlin52.tsp", "kroA100.tsp", "kroA150.tsp", "kroA200.tsp", "fl417.tsp", "gr666.tsp"};
                for(int i = 0; i < 6; i++) {
                    Loader loader;
                    int iterations = 1000;
                    loader.openTSPFile(fileNames[i]);
                    AdjacencyMatrix matrixGreedy(loader.verticesNumber, loader.convertToAM());
                    // matrixGreedy.printMatrix();

                    GreedyTSPSolver solver(matrixGreedy, 0);
                    GreedyTSPStatistics stats = solver.runMultiple(iterations);
                    // solver.printSolution();
                    writter.writeGreedyIntoFile(fileNames[i], stats.bestDistance, stats.worstDistance, stats.averageDistance, stats.standardDeviation);
                    std:: cout << "Greedy done " << fileNames[i] << "for " << iterations << " iterations\n";
                }
                break;
            }

            case 3: {
                FileWritter writter;
                writter.openFile("out/results.csv");
                GeneticAlgorithm::setPopulationSize(300);
                GeneticAlgorithm::setStopTime(100);
                GeneticAlgorithm::setCrossoverType(CrossoverType::OX);
                GeneticAlgorithm::setMutationType(MutationType::Insert);
                GeneticAlgorithm::setSelectionType('t');
                GeneticAlgorithm::setTournamentSize(5);
                GeneticAlgorithm::setInitializationType('l');
                GeneticAlgorithm::setMutationProbability(0.1);
                GeneticAlgorithm::setCrossoverProbability(0.7);

                GeneticAlgorithm ga;
                std::string fileNames[] = {"berlin52.tsp", "kroA100.tsp", "kroA150.tsp", "kroA200.tsp", "fl417.tsp", "gr666.tsp"};
                for(int i = 0; i < 6; i++) {
                    Loader loader;
                    loader.openTSPFile(fileNames[i]);
                    matrix = new AdjacencyMatrix(loader.verticesNumber, loader.convertToAM());
                    for(size_t ii = 0; ii < 10; ii++) {
                        result = ga.solveTenTSP(*matrix, 0, writter, fileNames[i], ii);

                        std:: cout << "GA done " << fileNames[i] << " for " << ii << " time \n";
                    }
                    std:: cout << "GA done " << fileNames[i] << " \n";
                }
                // task3Menu();
                break;
            }
            case 4: {
                FileWritter writter;
                writter.openFile("out/results.csv");
                GeneticAlgorithm::setPopulationSize(300);
                GeneticAlgorithm::setStopTime(100);
                GeneticAlgorithm::setCrossoverType(CrossoverType::OX);
                GeneticAlgorithm::setMutationType(MutationType::Insert);
                GeneticAlgorithm::setSelectionType('t');
                GeneticAlgorithm::setTournamentSize(5);
                GeneticAlgorithm::setInitializationType('l');
                GeneticAlgorithm::setMutationProbability(0.1);
                GeneticAlgorithm::setCrossoverProbability(0.7);

                GeneticAlgorithm ga;
                std::string fileNames[] = {"berlin52.tsp", "kroA100.tsp", "kroA150.tsp", "kroA200.tsp", "fl417.tsp", "gr666.tsp"};
                for(int i = 0; i < 6; i++) {
                    Loader loader;
                    loader.openTSPFile(fileNames[i]);
                    matrix = new AdjacencyMatrix(loader.verticesNumber, loader.convertToAM());

                    result = ga.perfectSolveTSP(fileNames[i], writter, *matrix);
                    std:: cout << "GA done " << fileNames[i] << " \n";
                }
                break;
            }
            case 5:
                autoTests.performAutoTests();
            break;

            case 6:{
                std:: cout << "Random graph generation - commented";

            // Loader loader;
            // loader.createRandomGraph(10, 15);
            // loader.printGraph();
            break;
            }
            case 7:
                exit(0);
            break;

            default:
                break;
        }
    }
}

void Menu::task3Menu()
{
    while(choice != 10)
    {
        std::cout << "1. Read from file\n";
        std::cout << "2. Print graph\n";
        std::cout << "3. Set stop time for GA\n";
        std::cout << "4. Set start population size\n";
        std::cout << "5. Set mutation propability\n";
        std::cout << "6. Set crossover propability\n";
        std::cout << "7. Set crossover method\n";
        std::cout << "8. Set mutation method\n";
        std::cout << "9. Solve Genetic Algorithm\n";
        std::cout << "10. Exit\n";

        std::cin >> choice;

        task3ManualTests();
    }

    choice = 0;
}

void Menu::task3ManualTests()
{
    std::string filePath;
    double stopTime{0.0}, mutationPropability{0.0}, crossoverPropability{0.0};
    size_t populationSize{0};

    GeneticAlgorithm ga;
    Loader loader;

    switch(choice)
    {
        case 1:
            if(matrix != nullptr)
                delete matrix;

            std::cout << "Type file name:\n";
            std::cin >> filePath;

            fileReader.readFromFile(filePath);
            loader.openTSPFile(filePath);

            matrix = new AdjacencyMatrix(loader.verticesNumber, loader.convertToAM());

            break;

        case 2:

            if(matrix == nullptr)
                break;

            matrix->printMatrix();

            break;

        case 3:
            std::cout << "Type stop time in seconds:\n";
            std::cin >> stopTime;

            GeneticAlgorithm::setStopTime(stopTime);
            break;

        case 4:
            std::cout << "Type population size:\n";
            std::cin >> populationSize;

            GeneticAlgorithm::setPopulationSize(populationSize);
            break;

        case 5:
            std::cout << "Type mutation propability:\n";
            std::cin >> mutationPropability;

            GeneticAlgorithm::setMutationProbability(mutationPropability);
            break;

        case 6:
            std::cout << "Type crossover propability:\n";
            std::cin >> crossoverPropability;

            GeneticAlgorithm::setCrossoverProbability(crossoverPropability);
            break;

        case 7:
            setCrossoverType();
            break;

        case 8:
            setMutationType();
            break;
        
        case 9:
            
            if(this->result != nullptr)
                delete this->result;

            if(this->matrix == nullptr)
                break;
            
            result = ga.solveTSP(*matrix);

            result->printPathInfo();

            break;

        case 10:
            return;

        default:
            break;

    }
}

void Menu::setCrossoverType()
{
    CrossoverType type = CrossoverType::PMX;
    int choice{-1};

    while(choice < 1 || choice > 2)
    {   
        std::cout << "Choose type:\n1. PMX\n2. OX\n";
        std::cin >> choice;
    }

    switch (choice)
    {
        case 1:
            type = CrossoverType::PMX;
            break;

        case 2:
            type = CrossoverType::OX;
            break;

        default:
            break;
    }

    GeneticAlgorithm::setCrossoverType(type);  
}

void Menu::setMutationType()
{
    MutationType type = MutationType::Swap;
    int choice{-1};

    while(choice < 1 || choice > 2)
    {   
        std::cout << "Choose type:\n1. Swap\n2. Insert\n";
        std::cin >> choice;
    }

    switch (choice)
    {
        case 1:
            type = MutationType::Swap;
            break;

        case 2:
            type = MutationType::Insert;
            break;

        default:
            break;
    }

    GeneticAlgorithm::setMutationType(type);  
}