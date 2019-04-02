#include <iostream>
#include "UtPod.h"
#include "Song.h"
#include <cstdlib>

using namespace std;


UtPod::UtPod() {
    songs = NULL;
    podMemSize = MAX_MEMORY;

    unsigned int currentTime = (unsigned)time(0);
    srand(currentTime);

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

    unsigned int currentTime = (unsigned)time(0);
    srand(currentTime);

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

    //check if two or more songs
    if (songs != NULL && songs->next != NULL) {

        SongNode* head = songs;
        SongNode* traverse = songs->next;

        while (head->next != NULL) {
            traverse = head->next;

            while (traverse != NULL) {

                //if one node is less
                if (traverse->s < head->s) {
                    //swap them
                    Song s1(head->s.getArtist(), head->s.getTitle(), head->s.getSize());
                    head->s.setArtist(traverse->s.getArtist());
                    head->s.setTitle(traverse->s.getTitle());
                    head->s.setSize(traverse->s.getSize());
                    traverse->s.setArtist(s1.getArtist());
                    traverse->s.setTitle(s1.getTitle());
                    traverse->s.setSize(s1.getSize());
                }
                traverse = traverse->next;
            }
            head = head->next;
        }
    }

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
            cout << first->s.getTitle() << " - " << first->s.getArtist() << " - " << first->s.getSize() << "MB" << endl;
            first = first->next;
        }
    }

}

void UtPod::shuffle() {

    int rand1;
    int rand2;

    SongNode *first = songs;
    SongNode *second = songs;

    int number = numSongs();

    //cout << "before" << endl;
    // loop and "shuffle" as many times as there are songs
    for (int i = 0; i < number; i++) {
        // get 2 pointers
        rand1 = rand() % numSongs();
        rand2 = rand() % numSongs();

        for (int j = 0; j < rand1; j++) {
            first = first->next;
        }

        for (int k = 0; k < rand2; k++) {
            second = second->next;
        }

        // swap them

        first->s.swap(second->s);
        first = songs;
        second = songs;
        //cout << "FUCK" << endl;
    }

}

UtPod::~UtPod() {
    // same exact thing as clear memory

    clearMemory();

}

int UtPod::numSongs() {

    SongNode *first = songs;
    int total = 0;

    while (first != NULL) {
        total++;
        first = first->next;
    }

    return total;
}



