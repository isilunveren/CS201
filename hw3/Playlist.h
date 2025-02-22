// Isil Unveren
// Section 1
// 22202444

#ifndef Playlist_h
#define Playlist_h
#include "Playlist.h"
#include "LinkedList.h"
#include "Song.h"
#include <iostream>
#include <cstddef>
class Playlist{
public:
    //constructors
    Playlist(const int playlistID);
    Playlist();
    Playlist(const Playlist& playlistToCopy);
    
    //destructor
    ~Playlist();
    
    int getID() ;
    bool getIsAssigned();
    void assign();
    void dropAssignment();
    LinkedList<Song>& getSongList();
    
    //operator overloading
    bool operator<(const Playlist& right) const;
    bool operator>(const Playlist& right) const;
    bool operator==(const Playlist& right) const;
    bool operator!=(const Playlist& right) const;
    bool operator<=(const Playlist& right) const;
    
private:
    
    //private data members
    int ID;
    LinkedList<Song> songList;
    bool isAssigned;
};
#endif /*Playlist_h*/
