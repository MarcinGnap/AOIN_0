#include "../../inc/Structures/Individual.h"


Individual::Individual(std::vector<int> & chromosome_)
    : chromosome(chromosome_)
{
    
}

void Individual::killIndividual()
{
    this->chromosome.clear();
    this->fitness = FLT_MAX;
}

void Individual::calculateFitness(const AdjacencyMatrix & matrix_, size_t source_)
{
    this->fitness = matrix_.getValue(source_, chromosome[0]);

    for(int i = 0; i < this->chromosome.size() - 1; ++i)
    {
        this->fitness += matrix_.getValue(this->chromosome[i], this->chromosome[i + 1]);
    }

    this->fitness += matrix_.getValue(this->chromosome[this->chromosome.size() - 1], source_);
}

void Individual::mutate(MutationType mutationType_)
{
    int firstIndex{0}, secondIndex{0};

    while(firstIndex == secondIndex)
    {
        firstIndex = RandomGenerator::getInt(0, this->chromosome.size() - 1);
        secondIndex = RandomGenerator::getInt(0, this->chromosome.size() - 1);
    }

    if(firstIndex > secondIndex)
        std::swap(firstIndex, secondIndex);

    switch(mutationType_)
    {
        case MutationType::Swap:
            std::swap(this->chromosome[firstIndex], this->chromosome[secondIndex]);
            break;

        case MutationType::Insert:
            
            auto temp = this->chromosome[secondIndex];

            for(int i = secondIndex; i > firstIndex; --i)
            {
                this->chromosome[i] = this->chromosome[i - 1];
            }

            this->chromosome[firstIndex] = temp;

            break;
    }
}