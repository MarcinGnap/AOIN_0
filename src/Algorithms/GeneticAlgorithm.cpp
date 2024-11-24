#include "../../inc/Algorithms/GeneticAlgorithm.h"
#include <limits>
#include <cmath>


double GeneticAlgorithm::mutationProbability{0.1};
double GeneticAlgorithm::crossoverProbability{0.7};
size_t GeneticAlgorithm::populationSize{300};
int GeneticAlgorithm::genereationNumber{50};

MutationType GeneticAlgorithm::mutationType{MutationType::Insert};
CrossoverType GeneticAlgorithm::crossoverType{CrossoverType::OX};
double GeneticAlgorithm::stopTime{100};
char GeneticAlgorithm::selectionType{'t'};
char GeneticAlgorithm::initializationType{'l'};
int GeneticAlgorithm::tournamentSize{5};


Path * GeneticAlgorithm::solveTSP(const AdjacencyMatrix & matrix_, size_t sourceCity_)
{
    double algorithmTime{0.0};
    int generationCount = 0;

    setupVariables(matrix_, 0);

    generateFirstPopulation(matrix_);

    std::sort(population.begin(), population.end());
    this->bestOne = this->population[0];

    while((algorithmTime / 1000.0) < stopTime && generationCount < genereationNumber)
    {
        timer.startTimer();

        std::vector<Individual> newPopulation;

        generateNewPopulation(newPopulation);

        this->population = newPopulation;

        calculatePopulationFitness(matrix_);

        std::sort(this->population.begin(), this->population.end());

        if(this->bestOne.getFitness() > this->population[0].getFitness()) {
            this->bestOne = this->population[0];

            algorithmTime += timer.stopTimer();
            continue;
        }
        algorithmTime += timer.stopTimer();
    }

    auto returnPath = new Path(this->bestOne.getFitness(), this->bestOne.getChromosome());

    returnPath->addCityAtFront(this->sourceCity);
    returnPath->addCityAtEnd(this->sourceCity);

    clearVariables();

    std::cout << bestOne.getFitness() << std::endl;
    return returnPath;
}

Path * GeneticAlgorithm::solveTenTSP(const AdjacencyMatrix &matrix_, size_t sourceCity_, FileWritter &writter, const std::string &instanceName, int runIndex) {
    double algorithmTime{0.0};

    setupVariables(matrix_, sourceCity_);
    generateFirstPopulation(matrix_);
    std::sort(population.begin(), population.end());
    this->bestOne = this->population[0];

    while ((algorithmTime / 1000.0) < stopTime) {
        timer.startTimer();

        std::vector<Individual> newPopulation;
        generateNewPopulation(newPopulation);
        this->population = newPopulation;

        calculatePopulationFitness(matrix_);
        std::sort(this->population.begin(), this->population.end());

        if (this->bestOne.getFitness() > this->population[0].getFitness()) {
            this->bestOne = this->population[0];
            algorithmTime += timer.stopTimer();
            continue;
        }
        algorithmTime += timer.stopTimer();
    }

    PopulationStatistics stats = calculatePopulationStatistics2();
    writter.writeGreedyIntoFile(instanceName, stats.bestFitness, stats.worstFitness, stats.averageFitness, stats.standardDeviation);

    auto returnPath = new Path(this->bestOne.getFitness(), this->bestOne.getChromosome());
    returnPath->addCityAtFront(this->sourceCity);
    returnPath->addCityAtEnd(this->sourceCity);

    clearVariables();
    std::cout << bestOne.getFitness() << std::endl;
    return returnPath;
}

void GeneticAlgorithm::setupVariables(const AdjacencyMatrix & matrix_, size_t sourceCity_)
{       
    this->sourceCity = sourceCity_;
    this->citiesNumber = matrix_.citiesNumber;

    this->bestOnesCrossovers = static_cast<int>(0.1 * populationSize);
}

std::vector<int> GeneticAlgorithm::createGreedyChromosome(const AdjacencyMatrix & matrix_, int startCity)
{
    std::vector<int> chromosome;
    std::vector<bool> visited(this->citiesNumber, false);

    int currentCity = startCity;
    visited[currentCity] = true;

    for(int i = 0; i < this->citiesNumber - 1; ++i)
    {
        int nearestCity = -1;
        double nearestDistance = std::numeric_limits<double>::max();

        for(int j = 0; j < this->citiesNumber; ++j)
        {
            if(!visited[j] && matrix_.getValue(currentCity, j) < nearestDistance)
            {
                nearestCity = j;
                nearestDistance = matrix_.getValue(currentCity, j);
            }
        }

        if(nearestCity != -1)
        {
            chromosome.push_back(nearestCity);
            visited[nearestCity] = true;
            currentCity = nearestCity;
        }
    }

    return chromosome;
}



void GeneticAlgorithm::generateFirstPopulation(const AdjacencyMatrix & matrix_)
{

    if (this->initializationType == 'z') {
        for(int i = 0; i < populationSize; ++i)
        {
            std::vector<int> chromosome = createGreedyChromosome(matrix_, this->sourceCity);

            Individual individual(chromosome);
            individual.calculateFitness(matrix_, this->sourceCity);

            this->population.push_back(individual);
        }
    }else {
        std::vector<int> cities;

        for(int i = 0; i < this->citiesNumber; ++i)
        {
            if(i == this->sourceCity)
                continue;

            cities.push_back(i);
        }

        for(int i = 0; i < populationSize; ++i)
        {
            std::vector<int> chromosome = shuffleChromosome(cities);

            Individual individual(chromosome);
            individual.calculateFitness(matrix_, this->sourceCity);

            this->population.push_back(individual);
        }
    }
}

std::vector<int> GeneticAlgorithm::shuffleChromosome(const std::vector<int> & cities_)
{
    std::vector<int> chromosome = cities_;

    for(int i = 0; i < chromosome.size(); ++i)
    {
        auto firstIndex = RandomGenerator::getInt(0, chromosome.size() - 1);
        auto secondIndex = RandomGenerator::getInt(0, chromosome.size() - 1);

        std::swap(chromosome[firstIndex], chromosome[secondIndex]);
    }

    return chromosome;
}

int GeneticAlgorithm::rouletteSelection()
{
    double totalFitness = 0.0;
    for (const auto& individual : population) {
        totalFitness += individual.getFitness();
    }

    double pick = RandomGenerator::getDouble(0.0, totalFitness);
    double current = 0.0;

    for (int i = 0; i < population.size(); ++i) {
        current += population[i].getFitness();
        if (current >= pick) {
            return i;
        }
    }

    return population.size() - 1;
}

int GeneticAlgorithm::tournamentSelection(int tournamentSize)
{
    int bestIndex = RandomGenerator::getInt(0, population.size() - 1);
    double bestFitness = population[bestIndex].getFitness();

    for (int i = 1; i < tournamentSize; ++i) {
        int competitorIndex = RandomGenerator::getInt(0, population.size() - 1);
        double competitorFitness = population[competitorIndex].getFitness();

        if (competitorFitness < bestFitness) {
            bestIndex = competitorIndex;
            bestFitness = competitorFitness;
        }
    }

    return bestIndex;
}

void GeneticAlgorithm::generateNewPopulation(std::vector<Individual> & newPopulation_)
{
    crossover(newPopulation_);   
    mutate(newPopulation_); 
}

void GeneticAlgorithm::crossover(std::vector<Individual> & newPopulation_)
{
    if(this->selectionType == 't') {
        newPopulation_.push_back(this->bestOne);

        while (newPopulation_.size() < populationSize) {
            int parent1Index = tournamentSelection(10);
            int parent2Index = tournamentSelection(10);

            // zapewnienie że nie wybierze się tego samego rodzica dwa razy
            while (parent2Index == parent1Index) {
                parent2Index = tournamentSelection(10);
            }

            auto chromosome1 = population[parent1Index].getChromosome();
            auto chromosome2 = population[parent2Index].getChromosome();

            double randomProbability = RandomGenerator::getDouble(0.0, 1.0);
            if (randomProbability < crossoverProbability) {
                executeCrossover(chromosome1, chromosome2);
            }

            newPopulation_.push_back(Individual(chromosome1));
            newPopulation_.push_back(Individual(chromosome2));
        }
    }else if(this->selectionType == 'r') {
        // Ruletka poniżej
        // elita zostaje
        newPopulation_.push_back(this->bestOne);

        while (newPopulation_.size() < populationSize) {
            int parent1Index = rouletteSelection();
            int parent2Index = rouletteSelection();

            // sprawdzam czy nie ma już takiego osobnika wybranego za pierwszym razem
            while (parent2Index == parent1Index) {
                parent2Index = rouletteSelection();
            }

            auto chromosome1 = population[parent1Index].getChromosome();
            auto chromosome2 = population[parent2Index].getChromosome();

            double randomProbability = RandomGenerator::getDouble(0.0, 1.0);
            if (randomProbability < crossoverProbability) {
                executeCrossover(chromosome1, chromosome2);
            }

            newPopulation_.push_back(Individual(chromosome1));
            newPopulation_.push_back(Individual(chromosome2));
        }

    }else {
    // basic below
    // best one is always alive until new best one 
    newPopulation_.push_back(this->bestOne);

    for(int i = 1; i < bestOnesCrossovers + 1; ++i)
    {
        auto randomPropability = RandomGenerator::getDouble(0.0, 1.0);

        if(randomPropability > crossoverProbability)
        {
            newPopulation_.push_back(this->population[i]);
            continue;
        }

        auto chromosome1 = this->bestOne.getChromosome();
        auto chromosome2 = this->population[i].getChromosome();

        executeCrossover(chromosome1, chromosome2);

        newPopulation_.push_back(Individual(chromosome1));
        newPopulation_.push_back(Individual(chromosome2));
    }

    for(int i = bestOnesCrossovers + 1; i < populationSize - 3; i += 2)
    {
        auto randomPropability = RandomGenerator::getDouble(0.0, 1.0);

        if(randomPropability > crossoverProbability)
        {
            newPopulation_.push_back(this->population[i]);
            newPopulation_.push_back(this->population[i + 1]);
            continue;
        }

        auto chromosome1 = this->population[i].getChromosome();
        auto chromosome2 = this->population[i + 1].getChromosome();

        executeCrossover(chromosome1, chromosome2);

        newPopulation_.push_back(Individual(chromosome1));
        newPopulation_.push_back(Individual(chromosome2));
    }

    auto preLastChromosome = this->population[this->populationSize - 2].getChromosome();

    newPopulation_.push_back(Individual(preLastChromosome));
    }
}

void GeneticAlgorithm::executeCrossover(std::vector<int> & chromosome1_, std::vector<int> & chromosome2_)
{
    switch (crossoverType)
    {

        case CrossoverType::PMX:

            CrossoverGenerator::pmxCrossover(chromosome1_, chromosome2_);
   
            break;
    
        case CrossoverType::OX:

            CrossoverGenerator::oxCrossover(chromosome1_, chromosome2_);

            break;
    }
}

void GeneticAlgorithm::mutate(std::vector<Individual> & newPopulation_)
{
    for(int i = 0; i < populationSize; ++i)
    {
        auto randomPropability = RandomGenerator::getDouble(0.0, 1.0);

        if(randomPropability > mutationProbability)
            continue;

        newPopulation_[i].mutate(mutationType);
    }
}

void GeneticAlgorithm::calculatePopulationFitness(const AdjacencyMatrix& matrix_)
{
    for(auto & individual : this->population)
        individual.calculateFitness(matrix_, this->sourceCity);
}

void GeneticAlgorithm::clearVariables()
{
    this->sourceCity = 0;
    this->citiesNumber = 0;

    this->population.clear();
    this->bestOne.killIndividual();
}

PopulationStatistics GeneticAlgorithm::calculatePopulationStatistics2() const {
    double bestFitness = population.front().getFitness();
    double worstFitness = population.back().getFitness();

    double totalFitness = 0.0;
    for (const auto& individual : population) {
        totalFitness += individual.getFitness();
    }
    double averageFitness = totalFitness / population.size();

    double variance = 0.0;
    for (const auto& individual : population) {
        variance += std::pow(individual.getFitness() - averageFitness, 2);
    }
    double standardDeviation = std::sqrt(variance / population.size());

    return {bestFitness, worstFitness, averageFitness, standardDeviation};
}

PopulationStatistics GeneticAlgorithm::calculatePopulationStatistics() {
    double bestFitness = std::numeric_limits<double>::max();
    double worstFitness = std::numeric_limits<double>::lowest();
    double totalFitness = 0.0;

    for (const auto& individual : population) {
        double fitness = individual.getFitness();
        bestFitness = std::min(bestFitness, fitness);
        worstFitness = std::max(worstFitness, fitness);
        totalFitness += fitness;
    }

    double averageFitness = totalFitness / population.size();

    // Obliczanie odchylenia standardowego
    double variance = 0.0;
    for (const auto& individual : population) {
        double fitness = individual.getFitness();
        variance += (fitness - averageFitness) * (fitness - averageFitness);
    }
    variance /= population.size();
    double standardDeviation = std::sqrt(variance);

    return { bestFitness, worstFitness, averageFitness, standardDeviation };
}

Path *GeneticAlgorithm::perfectSolveTSP(std::string fileName_, FileWritter &writter_, const AdjacencyMatrix &matrix_, size_t sourceCity_) {
    setupVariables(matrix_, sourceCity_);
    generateFirstPopulation(matrix_);
    std::sort(population.begin(), population.end());
    this->bestOne = this->population[0];

    const int generations = 100;

    for (int generation = 0; generation < generations; ++generation) {
        timer.startTimer();

        std::vector<Individual> newPopulation;
        generateNewPopulation(newPopulation);
        this->population = newPopulation;

        calculatePopulationFitness(matrix_);
        std::sort(this->population.begin(), this->population.end());

        PopulationStatistics stats = calculatePopulationStatistics();

        writter_.writeGreedyIntoFile(fileName_, stats.bestFitness, stats.worstFitness, stats.averageFitness, stats.standardDeviation);

        if (this->bestOne.getFitness() > this->population[0].getFitness()) {
            this->bestOne = this->population[0];
        }

        std::cout << "Generation " << generation + 1 << ": Best fitness = " << bestOne.getFitness() << std::endl;

        timer.stopTimer();
    }

    auto returnPath = new Path(this->bestOne.getFitness(), this->bestOne.getChromosome());
    returnPath->addCityAtFront(this->sourceCity);
    returnPath->addCityAtEnd(this->sourceCity);

    clearVariables();
    return returnPath;
}


Path * GeneticAlgorithm::solveTSP(std::string fileName_, FileWritter& writter_, const AdjacencyMatrix & matrix_, size_t sourceCity_)
{
    double algorithmTime{0.0};

    setupVariables(matrix_, sourceCity_);

    generateFirstPopulation(matrix_);

    std::sort(population.begin(), population.end());
    this->bestOne = this->population[0];

    while((algorithmTime / 1000.0) < stopTime)
    {
        timer.startTimer();

        std::vector<Individual> newPopulation;

        generateNewPopulation(newPopulation);

        this->population = newPopulation;

        calculatePopulationFitness(matrix_);

        std::sort(this->population.begin(), this->population.end());

        if(this->bestOne.getFitness() > this->population[0].getFitness())
        {
            this->bestOne = this->population[0];
            
            algorithmTime += timer.stopTimer();

            writter_.writeGAIntoFile(fileName_, mutationType, mutationProbability, crossoverType, crossoverProbability, (algorithmTime / 1000.0), bestOne.getFitness());
            continue;
        }

        algorithmTime += timer.stopTimer();
    }

    auto returnPath = new Path(this->bestOne.getFitness(), this->bestOne.getChromosome());

    returnPath->addCityAtFront(this->sourceCity);
    returnPath->addCityAtEnd(this->sourceCity);

    clearVariables();

    return returnPath;
}

Path * GeneticAlgorithm::solveTSP(size_t  diff_, std::string fileName_, FileWritter &writter_, const AdjacencyMatrix & matrix_)
{
    double algorithmTime{0.0};

    setupVariables(matrix_, 0);

    generateFirstPopulation(matrix_);

    std::sort(population.begin(), population.end());
    this->bestOne = this->population[0];
    while((algorithmTime / 1000.0) < stopTime)
    {
        timer.startTimer();

        std::vector<Individual> newPopulation;

        generateNewPopulation(newPopulation);
 
        this->population = newPopulation;

        calculatePopulationFitness(matrix_);

        std::sort(this->population.begin(), this->population.end());

        if(this->bestOne.getFitness() > this->population[0].getFitness())
        {
            this->bestOne = this->population[0];
            
            algorithmTime += timer.stopTimer();

            writter_.writeErrorsRelativeToPopulation(fileName_, populationSize, mutationType, crossoverType, (algorithmTime / 1000.0), bestOne.getFitness());
            continue;
        }

        algorithmTime += timer.stopTimer();
    }

    auto returnPath = new Path(this->bestOne.getFitness(), this->bestOne.getChromosome());

    returnPath->addCityAtFront(this->sourceCity);
    returnPath->addCityAtEnd(this->sourceCity);

    clearVariables();

    return returnPath;
}