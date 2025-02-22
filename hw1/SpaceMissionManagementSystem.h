// Işıl Ünveren
// Section 1
// 22202444
//
//  SpaceMissionManagementSystem.h
//  SpaceMissionManagementSystem
//
//
#ifndef SpaceMissionManagementSystem_h
#define SpaceMissionManagementSystem_h
#include <iostream>
#include <string>
#include "Mission.h"
#include "SpaceCraft.h"

using namespace std;
class SpaceMissionManagementSystem {
public:
    //constructor
    SpaceMissionManagementSystem();
    
    //destructor
    ~SpaceMissionManagementSystem();
    
    //functions
    void addMission( const string name, const string launchDate, const string destination );
    void removeMission( const string name );
    void addSpacecraft( const string name, const string type );
    void removeSpacecraft( const string name );
    void assignSpacecraftToMission( const string spacecraftName, const string missionName );
    void dropSpacecraftFromMission( const string spacecraftName );
    void showAllMissions() const;
    void showAllSpacecrafts() const;
    void showMission( const string name ) const;
    void showSpacecraft( const string name ) const;

private:
    
    //instance variables
    Mission* missions;
    SpaceCraft* spaceCrafts;
    int numOfMissions;
    int numOfSpaceCrafts;
};

#endif /* SpaceMissionManagementSystem_h */
