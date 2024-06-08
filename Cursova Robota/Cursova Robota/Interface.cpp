#include "Interface.h"
#include <iostream>
#include <string>
#include <limits>

using namespace std;

// ������ �� ����������� ������� � ������ ���������� ������
void Interface::TypeCommand() {
    cout << "> "; // ϳ������� ��� ����� �������
    getline(cin, this->currectCommand);
}

// �������� � ������� ������� �� ���������� ����������� ���������� � ����� ��������
void Interface::PrintHelpCommands() {
    print("Help commands: exit - to exit\n");
    print("Help commands: addTrack - add track with taked name\n");
    print("Help commands: addNote - add note to track\n");
    print("Help commands: removeNote - remove last note from track\n");
    print("Help commands: write - write to file\n");
    print("Help commands: openList - open currect track list\n");
}

// �������� ��������� ����������� � ������� ������
void Interface::Init() {
    TrackList list;
    string command;

    // � ���� ���� ����������� � ��� ���� �� �� ����� ������� ��� �������
    do {
        PrintHelpCommands();
        TypeCommand();

        // ��� ����� �������� �� �� �� ������� ���������� � ���� ����� ��� ��������� ����������� �������

        if (currectCommand == "addTrack") {
            print("Say track name to add to list: \n");
            getline(cin, command); // ������� ���� �����
            list.AddTrack(TSoundPlayer(command, vector<Sound> {}));
            print("Track added: " + command + "\n");
        }

        if (currectCommand == "addNote") {
            print("Say track name to which you want add note: \n");
            getline(cin, command); // ������� ���� �����

            for (TSoundPlayer& track : *list.GetPlayer()) {
                if (track.GetSoundName() == command) {
                    print("Say a note name: \n");
                    string noteName;
                    getline(cin, noteName); // ������� ���� ����
                    print("Say a note duration: \n");
                    string noteDuration;
                    getline(cin, noteDuration); // ������� ��������� ����
                    track.AddToTrackSound(noteDuration, noteName);
                }
            }
        }

        if (currectCommand == "removeNote") {
            print("Say track name from want remove note: \n");
            getline(cin, command); // ������� ���� �����

            for (TSoundPlayer& track : *list.GetPlayer()) {
                track.RemoveFromTrackLastSound();
            }
        }

        if (currectCommand == "write") {
            print("Say track name which you want to write to file: \n");
            getline(cin, command); // ������� ���� �����
            for (TSoundPlayer& track : *list.GetPlayer()) {
                if (track.GetSoundName() == command) {
                    track.WriteToFile("", command);
                }
            }
        }

        if (currectCommand == "openList") {
            list.Run();
        }

    } while (currectCommand != "exit");
}
