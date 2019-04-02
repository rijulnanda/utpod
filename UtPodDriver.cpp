/* utPod_driver.cpp
Demo Driver for the UtPod.
Roger Priebe
EE 312 10/16/18
This is a basic driver for the UtPod.
You will want to do more complete testing.
*/

#include <cstdlib>
#include <iostream>
#include "Song.h"
#include "UtPod.h"

using namespace std;

int main(int argc, char *argv[])
{
    UtPod t;

    Song s1("A", "Hey Jude", 150);
    int result = t.addSong(s1);
    cout << "result = " << result << endl;

    t.showSongList();

    Song s2("A", "RIP", 29);
    result = t.addSong(s2);
    cout << "result = " << result << endl;

    t.showSongList();

    Song s3("C", "Brotha Man", 21);
    result = t.addSong(s3);
    cout << "result = " << result << endl;

    Song s4("D", "Patience", 32);
    result = t.addSong(s4);
    cout << "result = " << result << endl;

    Song s5("E", "Dance Yrself Clean", 24);
    result = t.addSong(s5);
    cout << "add result = " << result << endl;

    Song s6("F", "Flatbed Freestyle", 247);
    result = t.addSong(s6);
    cout << "add result = " << result << endl;

    cout << "\n";
    t.showSongList();
    t.removeSong(s6);
    cout << "\n";
    //t.showSongList();


    t.showSongList();
    cout << "\n";
    cout << "SORTED LIST::::::\n\n";
    t.sortSongList();
    t.showSongList();
    cout << "\n";

    cout << "SHUFFLED:::: \n\n";
    t.shuffle();
    t.showSongList();

}