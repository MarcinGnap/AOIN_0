#include "../../inc/Structures/Path.h"


void Path::deallocateMemory()
{
    this->cities.clear();
}

Path::Path()
{
    if(this->cities.size() != 0)
        this->cities.clear();
}

Path::Path(float totalCost_, const Array<size_t> & cities_)
    : totalCost(totalCost_), cities(cities_)
{

}

Path::Path(float totalCost_, const std::vector<int> & cities_)
    : totalCost(totalCost_)
{
    for(auto city : cities_)
    {
        this->cities.addEnd(city);
    }
}

Path::~Path()
{
    this->deallocateMemory();
}

void Path::addCityAtEnd(size_t city_, float cost_)
{
    this->cities.addEnd(city_);

    this->totalCost += cost_;
}

void Path::addCityAtFront(size_t city_, float cost_)
{
    this->cities.addFront(city_);

    this->totalCost += cost_;
}

void Path::printPathInfo()
{
    for(int i = 0; i < this->cities.size() - 1; ++i)
    {
        std::cout << "| " << this->cities[i] << " | -> ";
    }

    std::cout << "| " << this->cities[this->cities.size() - 1] << " |\n";

    std::cout << "Total cost: " << this->totalCost << "\n";
}