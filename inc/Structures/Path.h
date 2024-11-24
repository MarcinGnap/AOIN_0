#pragma once

#include <vector>
#include <iostream>

#include "Array.hpp"
#include "../../src/Structures/Array.tpp"

class Path
{
    float totalCost{0};
    Array<size_t> cities;

    void allocateMemory();
    void deallocateMemory();

public:

    Path();
    Path(float totalCost_, const Array<size_t> & cities_);
    Path(float totalCost_, const std::vector<int> & cities_);
    ~Path();

    void addCityAtFront(size_t city_, float cost_ = 0);
    void addCityAtEnd(size_t city_, float cost_ = 0);
    void printPathInfo();
    
    void setTotalCost(float totalCost_)
    {
        this->totalCost = totalCost_;
    }

    float getTotalCost() const
    {
        return this->totalCost;
    }
    
    Array<size_t>& getCities()
    {
        return this->cities;
    }

};