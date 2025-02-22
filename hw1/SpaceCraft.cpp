// Işıl Ünveren
// Section 1
// 22202444
//
//  SpaceCraft.cpp
//  SpaceMissionManagementSystem
//
//
#include <iostream>
#include <string>
#include "SpaceCraft.h"
using namespace std;

//constructor that is provided variables
SpaceCraft::SpaceCraft (const string name, const string type){
    spaceCraftName = name;
    spaceCraftType = type;
    missionName = "";
    isAssigned = false;
    availibility = "Available";
}

//default constructor
SpaceCraft::SpaceCraft(){
    spaceCraftName = "";
    spaceCraftType = "";
    missionName = "";
    availibility = "Available";
    isAssigned = false;
}

//copy constructor
SpaceCraft::SpaceCraft(const SpaceCraft& other){
    spaceCraftName = other.spaceCraftName;
    spaceCraftType = other.spaceCraftType;
    missionName = other.missionName;
    isAssigned = other.isAssigned;
    availibility = other.availibility;
}

//assigning that spacecraft to a mission
void SpaceCraft::assignItToMission(const string mission){
    missionName = mission;
    isAssigned = true;
    availibility = "Assigned";
}

//dropping that spacecraft from its mission
void SpaceCraft::dropItFromMission(){
    isAssigned = false;
    missionName = "";
    availibility = "Available";
}

//getters
string SpaceCraft::getName() const{
    return spaceCraftName;
}

string SpaceCraft::getType() const{
    return spaceCraftType;
}

bool SpaceCraft::getIsAssigned() const{
    return isAssigned;
}

string SpaceCraft::getMissionName() const{
    return missionName;
}

string SpaceCraft::getAvailibility() const {
    return availibility;
}
