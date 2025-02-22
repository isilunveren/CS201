// Işıl Ünveren
// Section 1
// 22202444
//
//  SpaceMissionManagementSystem.cpp
//  SpaceMissionManagementSystem
//
//
//
#include <iostream>
#include <string>
#include "Mission.h"
#include "SpaceCraft.h"
#include "SpaceMissionManagementSystem.h"
using namespace std;

//constructor
SpaceMissionManagementSystem::SpaceMissionManagementSystem(){
    //initially no mission and no spacecraft
    missions = nullptr;
    spaceCrafts = nullptr;
    numOfMissions = 0;
    numOfSpaceCrafts = 0;
    
}

//destructor
SpaceMissionManagementSystem::~SpaceMissionManagementSystem(){
    delete [] missions;
    delete [] spaceCrafts;
}

//adding mission to the system
void SpaceMissionManagementSystem::addMission( const string name, const string launchDate, const string destination ){
    
    //If it is the first mission added to system, do not need to check its duplication
    if (numOfMissions == 0){
        numOfMissions++;
        missions = new Mission[numOfMissions];
        missions[numOfMissions -1] = Mission(name, launchDate, destination);
        cout << "Added mission " << name << "." << endl;
    }
    
    //if it is not first mission
    else{
        for (int i = 0; i < numOfMissions; i++){
            
            //if mission duplicates it returns a message and terminates the function
            if((missions[i].getName()).compare(name) == 0){
                cout << "Cannot add mission. Mission " << name << " already exists." << endl;
                return;
            }
        }
        numOfMissions++;
        //creating a new array that points to missions to hold old array
        Mission* newArrOfMissions = new Mission[numOfMissions];
        for (int i = 0; i < numOfMissions - 1; i++){
            newArrOfMissions[i] = missions[i];
        }
        
        //last element of that array is new mission
        newArrOfMissions[numOfMissions - 1] = Mission(name, launchDate, destination);
        delete [] missions;
        missions = newArrOfMissions;
        
        //showing message that adding mission is done
        cout << "Added mission " << name << "." << endl;
    }
}

//removing a mission from system
void SpaceMissionManagementSystem::removeMission( const string name ){
    //to seeking mission with that name in missions array
    bool doesExists = false;
    
    //if there is no mission in the system no need to seek it and
    if (numOfMissions == 0){
        cout << "Cannot remove mission. Mission "<< name << " does not exist." << endl;
    }
    
    //if there is at least one mission
    else{
        for (int i = 0; i < numOfMissions && !doesExists; i++){
            
            
            //looking for a mission with same name
            if((missions[i].getName()).compare(name) == 0){
                doesExists = true;
                numOfMissions --;
                //creating a new array to hold missions except wanted to remove one
                Mission* newArrOfMissions = new Mission[numOfMissions];
                for (int j = 0, k = 0; j < numOfMissions; j++, k++){
                    if (j == i){
                        k++;
                    }
                    newArrOfMissions[j] = missions[k];

                }
                
                //setting this mission's spacecrafts as available to be used by other missions
                for (int a = 0; a < numOfSpaceCrafts; a++){
                    for (int b = 0; b < missions[i].getNumOfSC(); b++){
                        if (spaceCrafts[a].getName().compare(missions[i].getSpaceCrafts()[b].getName()) == 0){
                            spaceCrafts[a].dropItFromMission();
                        }
                    }
                }
                delete [] missions;
                missions = newArrOfMissions;
                
                //showing message that removing mission is done
                cout << "Removed mission " << name << "." << endl;
            }
        }
        
        //if there is not such a mission which has that name
        if (!doesExists){
            cout << "Cannot remove mission. Mission "<< name << " does not exist." << endl;
        }
    }
}

//adding a spacecraft to the system
void SpaceMissionManagementSystem::addSpacecraft( const string name, const string type ){
    
    //if it is first spaceCraft added to system no need to duplication check
    if(numOfSpaceCrafts == 0){
        numOfSpaceCrafts++;
        spaceCrafts = new SpaceCraft[numOfSpaceCrafts];
        spaceCrafts[numOfSpaceCrafts - 1] = SpaceCraft(name, type);
        cout << "Added spacecraft " << name << "." << endl;
    }
    
    //if there is at least one spacecraft in the system
    else{
        for(int i = 0; i < numOfSpaceCrafts; i++){
            //if it duplicates terminate the function and show a message
            if(spaceCrafts[i].getName().compare(name) == 0){
                cout << "Cannot add spacecraft. Spacecraft " << name << " already exists." << endl;
                return;
            }
        }
        numOfSpaceCrafts++;
        
        //creating a new array in order for it to hold old spcecrafts
        SpaceCraft* newArrOfSpaceCrafts = new SpaceCraft[numOfSpaceCrafts];
        for (int i = 0; i < numOfSpaceCrafts - 1; i++){
            newArrOfSpaceCrafts[i] = spaceCrafts[i];
        }
        //this arrays last element is the one that is wanted to add
        newArrOfSpaceCrafts[numOfSpaceCrafts - 1] = SpaceCraft(name, type);
        delete [] spaceCrafts;
        spaceCrafts = newArrOfSpaceCrafts;
        
        //showing message that spacecraft addition is done
        cout << "Added spacecraft " << name << "." << endl;
    }
    
}

//removing a spaceraft from the system
void SpaceMissionManagementSystem::removeSpacecraft( const string name ){
    //to look for its existence in the system
    bool doesExist = false;
    
    //if there is not any spacecraft in the system no need to seek spacecraft with that name
    if (numOfSpaceCrafts == 0){
        cout << "Cannot remove spacecraft. " << name << "does not exist." << endl;
    }
    
    //if there is at least one spacecraft in the system
    else {
        for (int i = 0; i < numOfSpaceCrafts && !doesExist; i++){
            //if any spacecraft matches with that name
            if ((spaceCrafts[i].getName()).compare(name) == 0){
                doesExist = true;
                
                //if it is assigned to any mission it cannot be removed, function terminates
                if(spaceCrafts[i].getIsAssigned()){
                    cout << "Cannot remove spacecraft. Spacecraft " << name << " is assigned to a mission." << endl;
                    return;
                }
                
                //if it is available, continue
                numOfSpaceCrafts --;
                
                //creating a new array to hold spacecrafts except that one
                SpaceCraft* newArrOfSpaceCrafts = new SpaceCraft[numOfSpaceCrafts];
                for (int j = 0, k = 0; j < numOfSpaceCrafts; j++, k++){
                    if (j == i){
                        k++;
                    }
                    newArrOfSpaceCrafts[j] = spaceCrafts[k];
                }
                delete [] spaceCrafts;
                spaceCrafts = newArrOfSpaceCrafts;
                
                //displaying message that removing spacecraft is done
                cout << "Removed spacecraft " << name << "." << endl;
                
            }
        }
    }
    //after seeking all spacecrafts, if there is no with such name, display message
    if (!doesExist){
        cout << "Cannot remove spacecraft. Spacecraft " << name << " does not exist." << endl;
    }
}

//assigning a spacecraft to a mission
void SpaceMissionManagementSystem::assignSpacecraftToMission( const string spacecraftName, const string missionName ){
    
    //to seeking for both spacecraft and mission with these names
    bool doesSpaceCraftExist = false;
    bool doesMissionExist = false;
    
    //first look for spacecraft existence
    for (int i = 0; i < numOfSpaceCrafts && !doesSpaceCraftExist; i++){
        if ((spaceCrafts[i].getName()).compare(spacecraftName) == 0){
            doesSpaceCraftExist = true;
            
            //check its availibility, if it is assigned function terminates
            if (spaceCrafts[i].getIsAssigned()){
                cout << "Cannot assign spacecraft. Spacecraft " << spacecraftName <<  " is already assigned to mission "<< spaceCrafts[i].getMissionName() << "." << endl;
                return;
            }
            
            //if it available
            else{
                
                //look for mission with that name
                for(int j = 0; j < numOfMissions && !doesMissionExist; j++){
                    
                    //if any mission's name matches with that mission name
                    if ((missions[j].getName()).compare(missionName) == 0){
                        doesMissionExist = true;
                        //change that spacecrafts availibility as assigned
                        spaceCrafts[i].assignItToMission(missionName);
                        
                        //create a new array to hold that missions spacecrafts
                        SpaceCraft* newArrOfSpaceCrafts = new SpaceCraft[missions[j].getNumOfSC() + 1];
                        for (int a = 0; a < missions[j].getNumOfSC(); a++){
                            newArrOfSpaceCrafts[a] = (missions[j].getSpaceCrafts())[a];
                        }
                        
                        
                        //the last element of that array must be that spacecraft
                        newArrOfSpaceCrafts[missions[j].getNumOfSC()] = spaceCrafts[i];
                        delete [] missions[j].getSpaceCrafts();
                        missions[j].assignSpaceCraft(newArrOfSpaceCrafts);
                        //set number of spacecrafts of that mission
                        missions[j].setNumOfSpaceCrafts(missions[j].getNumOfSC() + 1);
                        
                        //display a message about work's done
                        cout << "Assigned spacecraft " << spacecraftName << " to mission " << missionName << "." << endl;
                    }
                }
               
            }
        }
    }
    
    //if spacecraft name does not match with any of the spacecrafts, display a negative message
    if (!doesSpaceCraftExist){
        cout << "Cannot assign spacecraft. Spacecraft " << spacecraftName << " does not exist." << endl;
        return;
    }
    //if mission name does not match with any of the missions, display a negative message
    if(!doesMissionExist) {
        cout << "Cannot assign spacecraft. Mission " << missionName << " does not exist." << endl;
    }
}

//dropping a spacecraft from a mission
void SpaceMissionManagementSystem::dropSpacecraftFromMission( const string spacecraftName ){
    
    //looking for that spacecraft's existence
    bool doesSpaceCraftExist = false;
    
    for (int i = 0; i < numOfSpaceCrafts && !doesSpaceCraftExist; i++){
        
        //if its name matces with any of the spacecrafts
        if ((spaceCrafts[i].getName()).compare(spacecraftName) == 0){
            doesSpaceCraftExist = true;
            
            //if it is not assigned to a mission there is nothing to drop
            if (!(spaceCrafts[i].getIsAssigned())){
                cout << "Cannot drop spacecraft. Spacecraft " << spacecraftName <<  " is not assigned to any mission."<< endl;
            }
            
            //if it is assigned
            else {
                for (int j = 0; j < numOfMissions; j++){
                    
                    //find this spacecraft's assigned mission from missions array of system
                    if((missions[j].getName()).compare(spaceCrafts[i].getMissionName()) == 0){
                        
                        //creating a new array to hold that missions other spacecrafts except that one
                        SpaceCraft* newArrOfSpaceCrafts = new SpaceCraft[missions[j].getNumOfSC() - 1];
                        for (int a = 0, b = 0; a < missions[j].getNumOfSC() - 1; a++, b++){
                            if ((missions[j].getSpaceCrafts()[b].getName()).compare(spacecraftName) == 0){
                                b++;
                            }
                            newArrOfSpaceCrafts[a] = missions[j].getSpaceCrafts()[b];
                        }
                        
                        //displaying a message that spacecraft drop is done
                        cout << "Dropped spacecraft " << spacecraftName << " from mission " << missions[j].getName() << "." << endl;
                        delete [] missions[j].getSpaceCrafts();
                        missions[j].dropSpaceCraft(newArrOfSpaceCrafts);
                        //setting number of spacecrafts of that mission
                        missions[j].setNumOfSpaceCrafts(missions[j].getNumOfSC() - 1);
                        spaceCrafts[i].dropItFromMission();
                    }
                }
                
            }
        }
    }
    
    //if there is not such a spacecraft, display a negative message
    if(!doesSpaceCraftExist){
        cout << "Cannot drop spacecraft. Spacecraft " << spacecraftName << " does not exist." << endl;
    }
}

//showing all missions with their name, launch date, destination, and spacecraft count
void SpaceMissionManagementSystem::showAllMissions() const{
    cout << "Missions in the space mission management system:" << endl;
    if (numOfMissions == 0){
        cout << "None" << endl;
        return;
    }
    for (int i = 0; i < numOfMissions; i++){
        cout << "Mission: " << missions[i].getName() << ", Launch Date: " << missions[i].getLaunchDate() << ", Destination: " << missions[i].getDestination() << ", Assigned Spacecraft Count: " << missions[i].getNumOfSC() << endl;
    }
}

//showing all spacecrafts with their name, type, and assignment status
void SpaceMissionManagementSystem::showAllSpacecrafts() const{
    cout << "Spacecrafts in the space mission management system:" << endl;
    if (numOfSpaceCrafts == 0){
        cout << "None" << endl;
    }
    for (int i = 0; i < numOfSpaceCrafts; i++){
        cout << "Spacecraft: " << spaceCrafts[i].getName() << ", Type: " << spaceCrafts[i].getType() << ", Status: " << spaceCrafts[i].getAvailibility() << endl;
    }
}

//showing a specific mission with detailed information about it
void SpaceMissionManagementSystem::showMission( const string name ) const{
    bool doesExist = false;
    for (int i = 0; i < numOfMissions && !doesExist; i++){
        if ((missions[i].getName()).compare(name) == 0){
            doesExist = true;
            cout << "Mission:" << endl;
            cout << "  Name: " << missions[i].getName() << endl;
            cout << "  Launch Date: " << missions[i].getLaunchDate() << endl;
            cout << "  Destination: " << missions[i].getDestination() << endl;
            cout << "  Assigned Spacecrafts:" << endl;
            if (missions[i].getNumOfSC() == 0){
                cout << "    None" << endl;
                return;
            }
            for (int j = 0; j < missions[i].getNumOfSC(); j++){
                cout << "  - " << missions[i].getSpaceCrafts()[j].getName() << endl;
            }
            
        }
    }
    
    //if there is not such a mission
    if (!doesExist) {
        cout << "Cannot show mission. Mission " << name << " does not exist." << endl;
    }
}

//showing a specific spacecraft
void SpaceMissionManagementSystem::showSpacecraft( const string name ) const{
    bool doesExist = false;
    for (int i = 0; i < numOfSpaceCrafts && !doesExist; i++){
        if ((spaceCrafts[i].getName()).compare(name) == 0){
            doesExist = true;
            cout << "Spacecraft: " << spaceCrafts[i].getName() << ", Type: " << spaceCrafts[i].getType() << ", Status: " << spaceCrafts[i].getAvailibility() << endl;
            
        }
    }
    
    //if there is not such a spacecraft
    if (!doesExist) {
        cout << "Cannot show spacecraft. Spacecraft " << name << " does not exist." << endl;
    }
}
