#pragma once

#include <iostream>

class AdjacencyMatrix
{
    
    float **matrix = nullptr;
    
    void allocateMemory();
    void insertValues(const float* data_);
    void copyValues(float** dataFromOrigin_);

    void deallocateMemory();

public:

    const size_t citiesNumber;

    AdjacencyMatrix(size_t citiesNumber_, const float* data_);
    AdjacencyMatrix(const AdjacencyMatrix & origin_);
    ~AdjacencyMatrix();

    float** getMatrix() const
    {
        return this->matrix;
    }

    float getValue(size_t source_, size_t destination_) const
    {
        return this->matrix[source_][destination_];
    }

    void printMatrix();
};