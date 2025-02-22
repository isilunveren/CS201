// Işıl Ünveren
// Section 1
// 22202444
//
//  SpaceCraft.h
//  SpaceMissionManagementSystem
//
//
#ifndef SpaceCraft_h
#define SpaceCraft_h
#include <iostream>
#include <string>
using namespace std;
class SpaceCraft {
public:
    
    //constructors
    SpaceCraft (const string name, const string type);
    SpaceCraft();
    SpaceCraft(const SpaceCraft& other);
    
    //functions
    void assignItToMission(const string missionName);
    void dropItFromMission();
    
    //getter functions
    string getName() const;
    string getType() const;
    string getMissionName() const;
    string getAvailibility () const;
    bool getIsAssigned() const;
    
    
    
private:
    
    //private instance variables
    string spaceCraftName;
    string spaceCraftType;
    string missionName;
    string availibility;
    bool isAssigned;
};
#endif /* SpaceCraft_h */
