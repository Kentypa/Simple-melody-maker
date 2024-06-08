#ifndef TRACKLIST_H
#define TRACKLIST_H

#include "TSoundPlayer.h"

class TrackList {
public:
    TrackList() {};

    TrackList(vector<TSoundPlayer> tracks);

    /*
    * Метод додає трек до массива
    */
    void AddTrack(TSoundPlayer newPlayer);

    vector<TSoundPlayer>* GetPlayer();

    /*
    * Метод спершу виводить всі назви поточних треків які в ньому є, після цього питає в користувача назву трека та грає її
    */
    void Run();
private:
    vector<TSoundPlayer> player;
};
#endif