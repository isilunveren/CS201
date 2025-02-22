// Isil Unveren
// Section 1
// 22202444

#include "Playlist.h"

//constructor
Playlist::Playlist(const int playlistID){
    ID = playlistID;
    songList = LinkedList<Song>();
}

//default constructor
Playlist::Playlist(){
    ID = 0;
    songList = LinkedList<Song>();
}

//copy constructor
Playlist::Playlist(const Playlist& playlistToCopy){
    ID = playlistToCopy.ID;
    songList = playlistToCopy.songList;
}

//destructor
Playlist::~Playlist(){
    songList.clear();
}

int Playlist::getID() {
    return ID;
}

bool Playlist::getIsAssigned(){
    return  isAssigned;
}

void Playlist::assign(){
    isAssigned = true;
}

void Playlist::dropAssignment(){
    isAssigned = false;
}

LinkedList<Song>& Playlist::getSongList(){
    return songList;
}

// operator overloading
bool Playlist::operator > (const Playlist &right) const{
    if(this -> ID > right.ID){
        return true;
    }
    return false;
}
bool Playlist::operator < (const Playlist &right) const{
    if(this -> ID < right.ID){
        return true;
    }
    return false;
}
bool Playlist::operator == (const Playlist &right) const{
    if(this -> ID == right.ID){
        return true;
    }
    return false;
}
bool Playlist::operator != (const Playlist &right) const{
    if(this -> ID != right.ID){
        return true;
    }
    return false;
}
bool Playlist::operator <= (const Playlist &right) const{
    if(this -> ID <= right.ID){
        return true;
    }
    return false;
}
