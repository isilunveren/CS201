//Isil Unveren
//Section 1
//22202444
//
//
#ifndef PANDEMICSIMULATOR_H
#define PANDEMICSIMULATOR_H
#include "CityBlock.h"
#include "Queue.h"
#include <string>
#include <iostream>
using namespace std;

class PandemicSimulator {
private:
    int rows, cols;
    CityBlock** cityGrid;

public:
    PandemicSimulator(const string cityGridFile);
    ~PandemicSimulator();

    void displayCityState(const int time);
    void simulateBlock(const int row, const int col);
    void simulatePandemic();
    CityBlock** Pandemic();
    CityBlock** Pandemic(int time);
};
#endif


