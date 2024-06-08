#include "TrackList.h"
#include <iostream>
#include <string>

using namespace std;

TrackList::TrackList(vector<TSoundPlayer> tracks) {
    this->player = tracks;
}

// ����� ���� ���� �� ������� �� �������� ��� �� �����������
void TrackList::AddTrack(TSoundPlayer newPlayer) {
    player.push_back(newPlayer);
    println("Track " + newPlayer.GetSoundName() + " has been added to the list.");
}

// ������� ��������� �� ������ � �������
vector<TSoundPlayer>* TrackList::GetPlayer() { return &this->player; }


// ����� ������ �������� �� ����� �������� ����� �� � ����� �, ���� ����� ���� � ����������� ����� ����� �� ��� ��
void TrackList::Run() {
    string command;

    // �������� �������
    println("Help commands: exit - to exit");
    println("Currect songs names:");
    for (TSoundPlayer currectPlayer : player) {
        println(currectPlayer.GetSoundName());
    }
    do {
        // � ���� �������� �� ���� ����������, ������� ������ ����� ���� ��� � ������
        println("This track in list or file?(type list or file): ");
        getline(cin, command);

        // ���� � ����� �� ��� �������� ������ �� ������������ ��
        if (command == "list") {
            println("Write track name to play: ");
            getline(cin, command);

            for (TSoundPlayer newPlayer : player) {
                if (command == newPlayer.GetSoundName()) {
                    println("write changing melody tonality\n");
                    getline(cin, command);

                    newPlayer.ChangeTonality(stod(command));
                    newPlayer.Play("");
                }
            }
        }
        else {
            println("Write path to file name: ");
            getline(cin, command);
            TSoundPlayer tempPlayer;
            tempPlayer.Play(command);
            }
    } while (command != "exit");
}