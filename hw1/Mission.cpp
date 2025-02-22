// Işıl Ünveren
// Section 1
// 22202444
//
//  Mission.cpp
//  SpaceMissionManagementSystem
//
//
#include <iostream>
#include <string>
#include "Mission.h"
#include "SpaceCraft.h"
using namespace std;

//constructor that is provided information
Mission::Mission (const string name, const string launchDate, const string destination){
    missionName = name;
    missionDestination = destination;
    missionLaunchDate = launchDate;
    spaceCrafts = nullptr;
    numOfSpaceCrafts = 0;
}

//default constructor
Mission::Mission(){
    missionName = "";
    missionDestination = "";
    missionLaunchDate = "";
    numOfSpaceCrafts = 0;
    spaceCrafts = nullptr;
    
}

//copy constructor
Mission::Mission (const Mission& other){
    missionName = other.missionName;
    missionDestination = other.missionDestination;
    missionLaunchDate = other.missionLaunchDate;
    delete [] spaceCrafts;
    
    if (numOfSpaceCrafts > 0){
        spaceCrafts = new SpaceCraft[numOfSpaceCrafts];
        for (int i = 0; i < numOfSpaceCrafts; i++){
            spaceCrafts[i] = other.spaceCrafts[i];
        }
    }
    else {
        spaceCrafts = nullptr;
    }
}

//destructor
Mission::~Mission(){
    delete [] spaceCrafts;
}

//assignment operator
Mission& Mission:: operator=( const Mission& other){
    if (this != &other){
        missionName = other.missionName;
        missionDestination = other.missionDestination;
        missionLaunchDate = other.missionLaunchDate;
        numOfSpaceCrafts = other.numOfSpaceCrafts;
        delete [] spaceCrafts;
        
        if (numOfSpaceCrafts > 0){
            spaceCrafts = new SpaceCraft[numOfSpaceCrafts];
            for(int i = 0; i < numOfSpaceCrafts; i++){
                spaceCrafts[i] = other.spaceCrafts[i];
            }
        }
        else {
            spaceCrafts = nullptr;
        }
    }
    return *this;
}

//getters
string Mission::getName() const{
    return missionName;
}
string Mission::getLaunchDate() const{
    return missionLaunchDate;
}
string Mission::getDestination() const{
    return missionDestination;
}
SpaceCraft* Mission:: getSpaceCrafts() const{
    return spaceCrafts;
}
int Mission::getNumOfSC() const{
    return numOfSpaceCrafts;
}

//assigning spacecraft to that mission
void Mission::assignSpaceCraft(SpaceCraft* newArrOfSpaceCrafts){
    spaceCrafts = newArrOfSpaceCrafts;
}

//droping a spacecraft from that mission
void Mission::dropSpaceCraft(SpaceCraft* newArrOfSpaceCrafts){
    spaceCrafts = newArrOfSpaceCrafts;
}

//setting number of spacecrafts
void Mission::setNumOfSpaceCrafts(const int number){
    numOfSpaceCrafts = number;
}

