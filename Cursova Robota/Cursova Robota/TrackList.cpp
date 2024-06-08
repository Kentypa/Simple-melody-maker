#include "TrackList.h"
#include <iostream>
#include <string>

using namespace std;

TrackList::TrackList(vector<TSoundPlayer> tracks) {
    this->player = tracks;
}

// Метод додає трек до массива та виводить про це повідомлення
void TrackList::AddTrack(TSoundPlayer newPlayer) {
    player.push_back(newPlayer);
    println("Track " + newPlayer.GetSoundName() + " has been added to the list.");
}

// Повертає посилання на массив з плеєрами
vector<TSoundPlayer>* TrackList::GetPlayer() { return &this->player; }


// Метод спершу виводить всі назви поточних треків які в ньому є, після цього питає в користувача назву трека та грає її
void TrackList::Run() {
    string command;

    // Виводить команди
    println("Help commands: exit - to exit");
    println("Currect songs names:");
    for (TSoundPlayer currectPlayer : player) {
        println(currectPlayer.GetSoundName());
    }
    do {
        // В циклі дивиться що хоче користувач, вивести мелодію через файл або зі списку
        println("This track in list or file?(type list or file): ");
        getline(cin, command);

        // Якщо з листа то тоді отримуємо мелодію та прослуховуємо її
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