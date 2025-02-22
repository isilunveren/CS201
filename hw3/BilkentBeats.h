// Isil Unveren
// Section 1
// 22202444

#ifndef BilkentBeats_h
#define BilkentBeats_h
#include <iostream>
#include <string>
#include "BilkentBeats.h"
#include "Song.h"
#include "Playlist.h"
#include "User.h"
#include "Node.h"
#include "LinkedList.h"
#include <cstddef>

class BilkentBeats {
public:
    BilkentBeats();
    ~BilkentBeats();

    void addUser( const int userId, const string userName );
    void removeUser( const int userId );
    void printUsers() const;

    void addSong( const int songID, const string songName, const string artists );
    void removeSong( const int songID );
    void printSongs() const;

    void addPlaylist( const int userId, const int playlistId );
    void removePlaylist( const int userId, const int playlistId );
    void addSongToPlaylist( const int playlistId, const int songId );
    void removeSongFromPlaylist( const int playlistId, const int songId );
    void printSongsInPlaylist( const int playlistId ) const;
    
private:
    LinkedList<User> users;
    LinkedList<Song> songs;
};

#endif /* BilkentBeats_h */
