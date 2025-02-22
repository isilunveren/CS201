// Isil Unveren
// Section 1
// 22202444

#ifndef Song_h
#define Song_h
#include <iostream>
#include <string>
#include <cstddef>
using namespace std;

class Song {
    
public:
    //constructors
    Song (const int songID, const string songName, const string songArtistName);
    Song ();
    Song (const Song& songToCopy);
    
    
    int getID() const;
    string getName() const;
    string getArtistname() const;
    
    //operator overloading
    bool operator<(const Song& right) const;
    bool operator>(const Song& right) const;
    bool operator==(const Song& right) const;
    bool operator!=(const Song& right) const;
    bool operator <= (const Song& right) const;
    
private:
    
    //private data members
    string name;
    string artistName;
    int ID;
};

#endif /* Song_h */
