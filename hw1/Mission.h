// Işıl Ünveren
// Section 1
// 22202444
//
//  Mission.h
//  SpaceMissionManagementSystem
//
//
#ifndef Mission_h
#define Mission_h
#include <iostream>
#include <string>
#include "SpaceCraft.h"
using namespace std;

class Mission{
public:
    
    //constructors
    Mission(const string name, const string launchDate, const string destination);
    Mission ();
    
    // copy constructor
    Mission(const Mission& other);
    
    //destructor
    ~Mission();
    
    //initializing the assignment operator
    Mission& operator=( const Mission& other);
    
    
    //functions
    string getName() const;
    string getLaunchDate() const;
    string getDestination() const;
    SpaceCraft* getSpaceCrafts() const;
    int getNumOfSC() const;
    void assignSpaceCraft(SpaceCraft* spaceCraft);
    void setNumOfSpaceCrafts(const int number);
    void dropSpaceCraft(SpaceCraft* newArrOfSpaceCrafts);
    
private:
    
    //instance variables
    string missionName;
    string missionLaunchDate;
    string missionDestination;
    SpaceCraft* spaceCrafts;
    int numOfSpaceCrafts;
    
};

#endif /* Mission_h */
