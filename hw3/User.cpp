// Isil Unveren
// Section 1
// 22202444

#include "User.h"

//default constructor
User::User(){
    ID = 0;
    name = "";
    playlists = LinkedList<Playlist>();
}

//constructor
User::User(int userID, string userName){
    ID = userID;
    name = userName;
    playlists = LinkedList<Playlist>();
}

//copy constructor
User::User(const User& userToCopy){
    ID = userToCopy.ID;
    name = userToCopy.name;
    playlists = userToCopy.playlists;
}

//destructor
User::~User(){
    playlists.clear();
}

string User::getName() {
    return name;
}

int User::getID(){
    return ID;
}

LinkedList<Playlist>& User::getPlaylists(){
    return playlists;
}

//operator overloading
bool User::operator > (const User &right) const{
    if(this -> ID > right.ID){
        return true;
    }
    return false;
}
bool User::operator < (const User &right) const{
    if(this -> ID < right.ID){
        return true;
    }
    return false;
}
bool User::operator == (const User &right) const{
    if(this -> ID == right.ID){
        return true;
    }
    return false;
}
bool User::operator != (const User &right) const{
    if(this -> ID != right.ID){
        return true;
    }
    return false;
}
bool User::operator <= (const User &right) const{
    if(this -> ID <= right.ID){
        return true;
    }
    return false;
}
