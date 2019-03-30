#include <iostream>
#include "UtPod.h"

using namespace std;


UtPod::UtPod() {
    songs = NULL;
    podMemSize = MAX_MEMORY;
}

UtPod::UtPod(int size) {

    if (size > MAX_MEMORY) {
        podMemSize = MAX_MEMORY;
    }
    else if (size < 0) {
        podMemSize = MAX_MEMORY;
    }
    else
        podMemSize = size;
}

int UtPod::addSong(Song const &s) {

    // check to see if there's enough memory to add the song
    if (s.getSize() > getRemainingMemory()) {
        return NO_MEMORY;           // NO_MEM = -1;
    }

    else {
        // add song to top of list
        SongNode *node = new SongNode;
        node->s = s;
        node->next = songs;
        songs = node;

        return SUCCESS;             // SUCCESS = 0;
    }
}

int UtPod::removeSong(Song const &s) {

    // check to see if song s is even in UtPod
    // traverse linked list, check if song is equal (bool == overwritten)
    // if it is, then remove

    SongNode *ptr = songs;      // 2 pointers to traverse
    SongNode *prev = songs;

    Song temp = s;              // to compare

    while (ptr != NULL) {       // to check if s is in the middle of the linked list
        if(ptr->s == temp) {
            if (ptr == songs) {         // check to see if its the top of the list
                delete(prev);
                songs = ptr->next;
                return SUCCESS;
            }
            else if (ptr != songs) {
                delete(ptr);
                prev->next = prev->next->next;
                return SUCCESS;
            }
        }
        prev = ptr;
        ptr = ptr->next;
    }

    return NO_MEMORY;
}

int UtPod::getRemainingMemory() {

    int sum = 0;
    int total = 0;
    SongNode *temp = songs;

    while (temp != NULL) {
        sum += temp->s.getSize();
        temp = temp->next;
    }

    total = podMemSize - sum;
    return total;
}

void UtPod::clearMemory() {
    // just gotta traverse with two pointers and delete

    SongNode *first = songs;
    SongNode *second = first;

    while (first != NULL) {
        second = first->next;
        delete(first);
        first = second;
    }

}

void UtPod::sortSongList() {

}

void UtPod::showSongList() {

    if (songs == NULL) {
        cout << "NO SONGS IN UTPOD" << endl;
        return;
    }
    else {
        SongNode *first = songs;
        //SongNode *second = songs;

        while (first != NULL) {
            cout << first->s.getTitle() << '.' << first->s.getArtist() << '.' << first->s.getSize() << "MB" << endl;
            first = first->next;
        }
    }

}

void UtPod::shuffle() {

    unsigned int currentTime = (unsigned)time(0);
    srand(currentTime);

}

UtPod::~UtPod() {
    // same exact thing as clear memory

    clearMemory();

}

