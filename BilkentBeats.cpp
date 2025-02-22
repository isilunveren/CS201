// Isil Unveren
// Section 1
// 22202444


#include "BilkentBeats.h"
#include <iostream>
#include <string>
#include "Song.h"
#include "Playlist.h"
#include "User.h"
#include "Node.h"
#include "LinkedList.h"
#include <cstddef>

using namespace std;

//default constructor
BilkentBeats::BilkentBeats(){
    users = LinkedList<User>();
    songs = LinkedList<Song>();
}

//destructor
BilkentBeats::~BilkentBeats(){
    users.clear();
    songs.clear();
}

//this method adds a new user to the sorted users linked list of the system
void BilkentBeats::addUser( const int userId, const string userName ){
    User newUser(userId, userName);

    //checks if users linked list have a user with same id if not inserts that user
    if (users.insertSorted(newUser)){
        cout << "Added user " << userId << "." << endl;
    }
    else{
        cout << "Cannot add user. There is already a user with ID " << userId << "." << endl;
    }
}

//this method removes a user from the sorted users linked list of the system
void BilkentBeats::removeUser( const int userId ){
    
    //finding user in users list
    Node<User>* curUser = users.getHeadPtr();
    while (curUser != nullptr) {
        
        if (curUser->getItem().getID() == userId) {
            break;
        }
        curUser = curUser->getNext();
    }
    
    //checks if that user exists
    if (curUser != nullptr){
        
        //remove each playlist of that user first
        if (curUser -> getItem().getPlaylists().getLength() != 0){
            for (int i = 1; i <= curUser -> getItem().getPlaylists().getLength(); i++){
                curUser -> getItem().getPlaylists().remove(curUser -> getItem().getPlaylists().getNodeAt(1)->getItem());
            }
        }
        //then remove user
        users.remove(curUser->getItem());
                cout << "Removed user " << userId << "." << endl;
        
        
    }
    else{
        cout << "Cannot remove user. There is no user with ID " << userId << "." << endl;
    }
}

//this method prints user and their playlists
void BilkentBeats::printUsers() const {
    if (users.isEmpty()) {
        cout << "There are no users to show." << endl;
    }
    else {
        cout << "Users in the system:" << endl;
        for(int i = 1; i <= users.getLength(); i++){
            
            cout << "User ID : " << ((users.getNodeAt(i))->getItem()).getID() << ", Name : " << ((users.getNodeAt(i))->getItem()).getName()<< ", Playlist IDs : " ;
            if((((users.getNodeAt(i))->getItem()).getPlaylists()).isEmpty()){
                cout << "None" << endl;
            }
            else{
                cout << "[";
                for(int j = 1; j <= (((users.getNodeAt(i))->getItem()).getPlaylists()).getLength(); j++){
                    
                    cout << (((((users.getNodeAt(i))->getItem()).getPlaylists()).getNodeAt(j))->getItem()).getID();
                    if(j != (((users.getNodeAt(i))->getItem()).getPlaylists()).getLength()){
                        
                        cout << ",";
                    }
                }
                cout << "]" << endl;
            }
            
        }
    }
}

//this method adds a new song to the system
void BilkentBeats::addSong( const int songID, const string songName, const string artists ) {
    Song newSong(songID, songName, artists);
    
    //checks whether a song with that information exists in the songs list of the system, if not inserts new song
    if(songs.insertSorted(newSong)){
        cout << "Added song " << songID << "." << endl;
    }
    else{
        cout << "Cannot add song. BilkentBeats already contains song " << songID << "." << endl;
    }
}

//this method removes song from the system
void BilkentBeats::removeSong( const int songID ){
    Node<Song>* curSong = songs.getHeadPtr();
    
    //finds that song in the songs list of the system
    while (curSong != nullptr) {
        if (curSong->getItem().getID() == songID) {
            break;
        }
        curSong = curSong->getNext();
    }
    
    if(curSong != nullptr){ //if that song exists
        
        //find that song in playlists of users
        for(int i = 1; i <= users.getLength(); i++){
            
            for(int j = 1; j <= users.getNodeAt(i)->getItem().getPlaylists().getLength(); j++){
                
                if(users.getNodeAt(i)->getItem().getPlaylists().getNodeAt(j)->getItem().getSongList().doesExist(curSong->getItem())){
                    
                    //remove that song if it exists in any one of the playlists
                    users.getNodeAt(i)->getItem().getPlaylists().getNodeAt(j)->getItem().getSongList().remove(curSong->getItem());
                }
            }
        }
        //then remove that song from the systems songs list
        songs.remove(curSong->getItem());
        cout << "Removed song " << songID << "."<< endl;
    }
    else{ //if there is not such a song in the system
        cout << "Cannot remove song. There is no song with ID " << songID << "."<< endl;
    }
}

//this method prints the ids, names, artists' names of the songs of the system
void BilkentBeats::printSongs() const{
    if(songs.isEmpty()){
        cout << "Cannot print songs. There is no song in the music library." << endl;
    }
    else{
        cout << "Music Library:" << endl;
        for (int i = 1; i <= songs.getLength(); i++){
            cout << "Song " << ((songs.getNodeAt(i))->getItem()).getID() << " : " << ((songs.getNodeAt(i))->getItem()).getName() << " - " << ((songs.getNodeAt(i))->getItem()).getArtistname() << endl;
        }
    }
}

//this method adds a new playlist to a user
void BilkentBeats::addPlaylist( const int userId, const int playlistId ){
    
    //find the user with that id in the system
    Node<User>* curUser = users.getHeadPtr();
    while(curUser != nullptr){
        if(curUser->getItem().getID()== userId){
            break;
        }
        curUser = curUser->getNext();
    }

    //if user could not be found
    Playlist aPlaylist(playlistId);
    if(curUser == nullptr){
        cout << "Cannot add playlist. There is no user with ID " << userId << "." << endl;
        return;
    }
    
    //check every user if any one of them have a playlist with given id
    Node<User>* userToSearch = users.getNodeAt(1);
    for (int i = 1; i <= users.getLength(); i++){
        Node <Playlist>* curPL = userToSearch->getItem().getPlaylists().getNodeAt(1);
        
        for (int j = 1; j <= userToSearch->getItem().getPlaylists().getLength(); j++){
            
            //if there is a user who have playlist with that id method is ended
            if(curPL->getItem().getID() == playlistId){
                cout << "Cannot add playlist. There is a user having a playlist with ID " << playlistId << "."<< endl;
                return;
            }
            curPL = userToSearch->getItem().getPlaylists().getNodeAt(j);
        }
        userToSearch = users.getNodeAt(i+1);
    }
    
    //insert it to the user's playlists linked list
    curUser->getItem().getPlaylists().insertSorted(aPlaylist);
    cout << "Added playlist " << playlistId << " to user " << userId << "." << endl;

    

}

//this method removes a playlist from a user's playlists
void BilkentBeats::removePlaylist( const int userId, const int playlistId ){
    bool userFound = false;
    Node<Playlist>* curPlaylist = nullptr;

    //find the playlist with that id in the system
    for (int i = 1; i <= users.getLength(); i++){
        for (int j = 1; j <= users.getNodeAt(i)->getItem().getPlaylists().getLength(); j++){
            if(users.getNodeAt(i)->getItem().getPlaylists().getNodeAt(j)->getItem().getID() == playlistId){
                curPlaylist = users.getNodeAt(i)->getItem().getPlaylists().getNodeAt(j);
            }
        }
    }

    //find the user with that id in the system
    Node<User>* curUser = users.getHeadPtr();
    while(curUser != nullptr){
        if(curUser->getItem().getID()== userId){
            userFound = true;
            break;
        }
        curUser = curUser->getNext();
    }
    if(!userFound){ //if user with that id does not exist
        cout << "Cannot remove playlist. There is no user with ID " << userId << "." << endl;
        return;
    }

    if (curPlaylist != nullptr && curUser->getItem().getPlaylists().remove(curPlaylist->getItem())) {
        cout << "Removed playlist " << playlistId << " from user " << userId << "." << endl;
    }
    else { //if user does not have a playlist with that id
        cout << "Cannot remove playlist. User " << userId << " does not have a playlist with ID " << playlistId << "." << endl;
    }
}

//this method adds a song to specified playlist
void BilkentBeats::addSongToPlaylist( const int playlistId, const int songId ){
    
    //find the playlist in a user's playlists
    Node<Playlist>* curPlaylist = nullptr;

    for (int i = 1; i <= users.getLength(); i++){
        for (int j = 1; j <= users.getNodeAt(i)->getItem().getPlaylists().getLength(); j++){
            if(users.getNodeAt(i)->getItem().getPlaylists().getNodeAt(j)->getItem().getID() == playlistId){
                curPlaylist = users.getNodeAt(i)->getItem().getPlaylists().getNodeAt(j);
            }
        }
    }
    if (curPlaylist == nullptr) {//if playlist with that id could not be found
        cout << "Cannot add song. There is no playlist with ID " << playlistId << "." << endl;
        return;
    }
    
    //search for song with that id in the songs list of the system
    Node<Song>* curSong = songs.getHeadPtr();
    while (curSong != nullptr) {
        if (curSong->getItem().getID() == songId) {
            break;
        }
        curSong = curSong->getNext();
    }
    
    if (curSong == nullptr) {//if song with that id could not be found
        cout << "Cannot add song. There is no song with ID " << songId << "." << endl;
        return;
    }
    
    if(curPlaylist->getItem().getSongList().doesExist(curSong->getItem())){
        cout << "Cannot add song. The playlist already contains song " << songId <<"." << endl;
        return;
    }
    //insert the song to the unsorted songs linked list of that playlist
    curPlaylist->getItem().getSongList().insertUnsorted(curSong->getItem());
    cout << "Added song " << songId << " to playlist " << playlistId << "." << endl;
    
}

//this method removes specified song from specified playlist
void BilkentBeats::removeSongFromPlaylist( const int playlistId, const int songId ){
    
    //checks whether that playlist exists if it exists holds it
    Node<Playlist>* curPlaylist = nullptr;
    for (int i = 1; i <= users.getLength(); i++){
        
        for (int j = 1; j <= users.getNodeAt(i)->getItem().getPlaylists().getLength(); j++){
            
            if(users.getNodeAt(i)->getItem().getPlaylists().getNodeAt(j)->getItem().getID() == playlistId){
                curPlaylist = users.getNodeAt(i)->getItem().getPlaylists().getNodeAt(j);
            }
        }
    }
    
    if (curPlaylist == nullptr) {//if playlist with that id could not be found
        cout << "Cannot remove song. There is no playlist with ID " << playlistId << "." << endl;
        return;
    }
    
    //checks whether that song exists if it exists holds it
    Node<Song>* curSong = songs.getHeadPtr();
    while (curSong != nullptr) {
        if (curSong->getItem().getID() == songId) {
            break;
        }
        curSong = curSong->getNext();
    }
    
    //checks if that playlist has that song
    if(!(curPlaylist ->getItem().getSongList().doesExist(curSong->getItem()))){
        cout << "Cannot remove song. There is no song " << songId << " in playlist " << playlistId << "." << endl;
        return;
    }

    curPlaylist->getItem().getSongList().remove(curSong->getItem());
    cout << "Removed song " << songId << " from playlist " << playlistId << "." << endl;
    
}

//this method displays songs in a specified playlist with their id, name, artist info
void BilkentBeats::printSongsInPlaylist( const int playlistId ) const{
    
    //checks whether that playlist exists if it exists holds it
    Node<Playlist>* curPlaylist = nullptr;
    for (int i = 1; i <= users.getLength(); i++){
        
        for (int j = 1; j <= users.getNodeAt(i)->getItem().getPlaylists().getLength(); j++){
            
            if(users.getNodeAt(i)->getItem().getPlaylists().getNodeAt(j)->getItem().getID() == playlistId){
                curPlaylist = users.getNodeAt(i)->getItem().getPlaylists().getNodeAt(j);
            }
        }
    }
    if (curPlaylist == nullptr) {//if playlist with that id could not be found
        cout << "Cannot print songs. There is no playlist with ID " << playlistId << "." << endl;
        return;
    }
    if(curPlaylist -> getItem().getSongList().getLength() == 0){//if that playlist is empty
        cout << "There are no songs to show in playlist " << playlistId << "." << endl;
        return;
    }
    cout << "Songs in playlist " << playlistId << ":" << endl;
    for (int i = 1; i <= curPlaylist -> getItem().getSongList().getLength(); i++){
        
        cout <<"Song "<< curPlaylist -> getItem().getSongList().getNodeAt(i)->getItem().getID() << " : " << curPlaylist -> getItem().getSongList().getNodeAt(i)->getItem().getName() << " - " << curPlaylist -> getItem().getSongList().getNodeAt(i)->getItem().getArtistname() << endl;
    }
}
