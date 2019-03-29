#ifndef SONG_H
#define SONG_H

#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

class Song {

    private:
        //song size
        int size;

        //song title
        string title;

        //song artist
        string artist;

    public:
        //Default Constructor
        Song();

        //Constructor with artist/title/size
        Song(string artist, string title, int size);
        
        //get and set for title
        string getTitle() const;
        void setTitle(string title);

        //get and set for artist
        string getArtist() const;
        void setArtist(string artist);

        //get and set for size
        int getSize() const;
        void setSize(int size);

        //overloading operators
        bool operator ==(Song const &rhs);
        bool operator >(Song const &rhs);
        bool operator <(Song const &rhs);

        //destructor
        ~Song();
};

#endif