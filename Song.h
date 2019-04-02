//
// Created by Rijul Nanda on 2019-03-13.
//

#ifndef ASSIGNMENT5_SONG_H
#define ASSIGNMENT5_SONG_H

#include <iostream>
#include <string.h>

using namespace std;

class Song
{
private:

    string title;
    string artist;
    int size;

public:

    Song();                 // constructor

    Song(string artist, string title, int size);        // constructor

    int getSize() const;
    void setSize(int size);

    string getTitle() const;
    void setTitle(string title);

    string getArtist() const;
    void setArtist(string artist);

    void swap(Song &s);

    //~Song();                // destructor


    bool operator ==(Song const &rhs);
    bool operator >(Song const &rhs);
    bool operator <(Song const &rhs);

};


#endif //ASSIGNMENT5_SONG_H
