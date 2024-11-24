//
// Created by mdgna on 27.10.2024.
//

#ifndef LOADER_H
#define LOADER_H
#pragma once
#include <string>

class Loader
{
public:

    std::string fileName;
    int plannedVerticiesNumber;
    int optCost;
    size_t verticesNumber;
    int* bestPath;
    float** verticesGraph;

    Loader();
    ~Loader();

    void deleteGraph();
    void printGraph();
    bool createRandomGraph(int generatedVertices, int maxValue);
    const float* convertToAM();
    float calculateDistance(float firstX, float firstY, float secondX, float secondY);

    bool openIni();
    bool openTSPFile(std::string& fileName);

};

#endif //LOADER_H
