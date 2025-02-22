// Isil Unveren
// Section 1
// 22202444

#include "Song.h"
#include <cstddef>

//default constructor
Song::Song(){
    ID = 0;
    name = "";
    artistName = "";
}

//constructor
Song::Song (const int songID, const string songName, const string songArtistName){
    ID = songID;
    name = songName;
    artistName = songArtistName;
}

//copy constructor
Song::Song (const Song& songToCopy){
    ID = songToCopy.ID;
    name = songToCopy.name;
    artistName = songToCopy.artistName;
}

int Song::getID() const{
    return ID;
}

string Song::getName() const{
    return name;
}

string Song::getArtistname() const{
    return artistName;
}

//operator overloading
bool Song::operator > (const Song &right) const{
    if(this -> ID > right.ID){
        return true;
    }
    return false;
}
bool Song::operator < (const Song &right) const{
    if(this -> ID < right.ID){
        return true;
    }
    return false;
}
bool Song::operator == (const Song &right) const{
    if(this -> ID == right.ID){
        return true;
    }
    return false;
}
bool Song::operator != (const Song &right) const{
    if(this -> ID != right.ID){
        return true;
    }
    return false;
}
bool Song::operator <= (const Song &right) const{
    if(this -> ID <= right.ID){
        return true;
    }
    return false;
}
