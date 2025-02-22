// Isil Unveren
// Section 1
// 22202444

#ifndef User_h
#define User_h
#include "User.h"
#include "Playlist.h"
#include "LinkedList.h"
#include <iostream>
#include <string>
using namespace std;

class User {
public:
    //constructor
    User();
    User(int userID, string userName);
    User(const User& userToCopy);
    //desturctor
    ~User();
    
    string getName() ;
    int getID() ;
    LinkedList<Playlist>& getPlaylists();
    
    //operator overloading
    bool operator<(const User& right) const;
    bool operator>(const User& right) const;
    bool operator==(const User& right) const;
    bool operator!=(const User& right) const;
    bool operator<=(const User& right) const;
    
private:
    
    //private data members
    int ID;
    string name;
    LinkedList<Playlist> playlists;
};
#endif /* User_h */
