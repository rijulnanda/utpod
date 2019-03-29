#include <cstdlib>
#include <iostream>
#include <string>
#include "Song.h"

using namespace std;

    Song::Song() {
        title = "";
        artist = "";
        size = 0;
    }

    //Constructor with artist/title/size
    Song::Song(string artist, string title, int size) {
        this->title = title;
        this->artist = artist;
        this->size = size;;
    }
    
    //get and set for title
    string Song::getTitle() const {
        return title;
    }

    void Song::setTitle(string title) {
        this->title = title;
    }

    //get and set for artist
    string Song::getArtist() const {
        return artist;
    }
    void Song::setArtist(string artist) {
        this->artist = artist; 
    }

    //get and set for size
    int Song::getSize() const {
        return size;
    }
    void Song::setSize(int size) {
        this->size = size;
    }

    //overloading operators
    bool Song::operator ==(Song const &rhs) {
        return (artist == rhs.artist &&
                title == rhs.title &&
                size == rhs.size);
    }
    bool Song::operator >(Song const &rhs) {
        return (size > rhs.size);
    }
    bool Song::operator <(Song const &rhs) {
        return (size < rhs.size);
    }

    //destructor
    Song::~Song() {
        cout << "in destructor - name is:" << title << endl;
    }












}
