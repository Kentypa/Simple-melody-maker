#ifndef TRACKLIST_H
#define TRACKLIST_H

#include "TSoundPlayer.h"

class TrackList {
public:
    TrackList() {};

    TrackList(vector<TSoundPlayer> tracks);

    /*
    * ����� ���� ���� �� �������
    */
    void AddTrack(TSoundPlayer newPlayer);

    vector<TSoundPlayer>* GetPlayer();

    /*
    * ����� ������ �������� �� ����� �������� ����� �� � ����� �, ���� ����� ���� � ����������� ����� ����� �� ��� ��
    */
    void Run();
private:
    vector<TSoundPlayer> player;
};
#endif