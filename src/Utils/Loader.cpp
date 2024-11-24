#include "../../inc/Utils/Loader.h"
#include <iostream>
#include <fstream>
#include <time.h>
#include <stdlib.h>
#include <windows.h>
#include <math.h>

using namespace std;

Loader::Loader()
{
}

Loader::~Loader()
{
	if (verticesNumber != 0)
	{
		deleteGraph();
	}
}

void Loader::deleteGraph()
{
	for (int i = 0; i < verticesNumber; i++)
	{
		delete verticesGraph[i];
	}
	delete verticesGraph;
	verticesGraph = NULL;
	verticesNumber = 0;
}

void Loader::printGraph()
{
	cout << "File: " << fileName << "\nNumber of vertices: " << verticesNumber << "\nVertices: \n";
	for (int i = 0; i < verticesNumber; i++) {
		cout << "\t" << i << " - \t";
		for (size_t j = 0; j < 2; j++)
		{
			if (j == 0) {
				cout << "X: ";
			}
			else {
				cout << "Y: ";
			}
			cout << " " << verticesGraph[i][j] << "  \t";
		}
		cout << "\n";
	}
}

bool Loader::createRandomGraph(int generatedVertices, int maxValue)
{
	cout << "Creating random graph with " << generatedVertices << " vertices and max value of singular path of " << maxValue << " ...\n";
	if (verticesNumber != 0)
	{
		deleteGraph();
	}

	fileName = "Generated-graph";
	verticesNumber = generatedVertices;
	verticesGraph = new float* [generatedVertices];
	for (int i = 0; i < generatedVertices; i++) {
		verticesGraph[i] = new float[2];
	}
	srand(GetTickCount64());
	for (int i = 0; i < generatedVertices; i++)
	{
		for (int j = 0; j < 2; j++) {
			verticesGraph[i][j] = rand() % maxValue;
		}
	}
	return true;
}

const float* Loader::convertToAM()
{
	float* matrix = new float [verticesNumber * verticesNumber];
	int tempIterator = 0;

	for (int i = 0; i < verticesNumber; i++)
	{
		for (int ii = 0; ii < verticesNumber; ii++) {
			matrix[tempIterator] = calculateDistance(verticesGraph[i][0], verticesGraph[i][1], verticesGraph[ii][0], verticesGraph[ii][1]);
			tempIterator++;
		}
	}
	// for (int i = 0; i < verticesNumber*verticesNumber; i++)
	// {
	// 		cout << " " << matrix[i];
	// }
	return matrix;
}

float Loader::calculateDistance(float firstX, float firstY, float secondX, float secondY)
{
	float fullDistance, xDistance, yDistance;
	xDistance = secondX - firstX;
	yDistance = secondY - firstY;
	xDistance = xDistance * xDistance;
	yDistance = yDistance * yDistance;
	fullDistance = xDistance + yDistance;
	fullDistance = sqrt(fullDistance);
	return fullDistance;
}

bool Loader::openIni()
{
	cout << "Opening .ini file...\n";
	ifstream iniFile("config.ini", std::ios::in);
	if (iniFile.good())
	{
		iniFile >> fileName;
		iniFile >> plannedVerticiesNumber;
		iniFile >> optCost;

		iniFile.close();
		cout << ".ini file opened properly.\n";
		return true;
	}
	cout << ".ini file failed to open.\n";
	return false;
}

bool Loader::openTSPFile(std::string& fileName)
{
	cout << "Opening TSP file...\n";
	ifstream tspFile(fileName, ios::in);
	if (!tspFile.good())
	{
		this->fileName = "Brak pliku";
		cout << "This file does not exist...\n";
		return false;
	}

	// if (verticesNumber != 0)
	// {
	// 	deleteGraph();
	// }
	cout << "TSP file opened properly...\n";

	string tempLine;


	while (getline(tspFile, tempLine))
	{
		if (tempLine.find("DIMENSION") != string::npos)
		{
			verticesNumber = stoi(tempLine.substr(tempLine.find(":") + 1));
			verticesGraph = new float* [verticesNumber];
			for (int i = 0; i < verticesNumber; i++) {
				verticesGraph[i] = new float[2];
			}
		}
		if (tempLine.find("NODE_COORD_SECTION") != string::npos)
		{
			cout << "Printing coords...\n\n";
			for (int i = 0; i < verticesNumber; i++) {
				int vertice, x, y;
				string ttline;
				tspFile >> vertice;
				tspFile >> verticesGraph[i][0];
				tspFile >> verticesGraph[i][1];
			}
		}
	}

	tspFile.close();
	return true;
}
