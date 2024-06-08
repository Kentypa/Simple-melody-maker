#include "Interface.h"
#include <iostream>
#include <string>
#include <limits>

using namespace std;

// Отримує від користувача команду у вигляді введенного тексту
void Interface::TypeCommand() {
    cout << "> "; // Підсказка для вводу команди
    getline(cin, this->currectCommand);
}

// Виводить в консоль команди які допоможуть користувачу розібратись у роботі програми
void Interface::PrintHelpCommands() {
    print("Help commands: exit - to exit\n");
    print("Help commands: addTrack - add track with taked name\n");
    print("Help commands: addNote - add note to track\n");
    print("Help commands: removeNote - remove last note from track\n");
    print("Help commands: write - write to file\n");
    print("Help commands: openList - open currect track list\n");
}

// Ініціалізує інтерфейс користувача у поточній консолі
void Interface::Init() {
    TrackList list;
    string command;

    // У циклі питає користувача о діях доки він не введе команду для зупинки
    do {
        PrintHelpCommands();
        TypeCommand();

        // Далі йдуть перевірки на те що вводить користувач і після цього йде виконання поставленної команди

        if (currectCommand == "addTrack") {
            print("Say track name to add to list: \n");
            getline(cin, command); // Читання імені трека
            list.AddTrack(TSoundPlayer(command, vector<Sound> {}));
            print("Track added: " + command + "\n");
        }

        if (currectCommand == "addNote") {
            print("Say track name to which you want add note: \n");
            getline(cin, command); // Читання імені трека

            for (TSoundPlayer& track : *list.GetPlayer()) {
                if (track.GetSoundName() == command) {
                    print("Say a note name: \n");
                    string noteName;
                    getline(cin, noteName); // Читання імені ноти
                    print("Say a note duration: \n");
                    string noteDuration;
                    getline(cin, noteDuration); // Читання тривалості ноти
                    track.AddToTrackSound(noteDuration, noteName);
                }
            }
        }

        if (currectCommand == "removeNote") {
            print("Say track name from want remove note: \n");
            getline(cin, command); // Читання імені трека

            for (TSoundPlayer& track : *list.GetPlayer()) {
                track.RemoveFromTrackLastSound();
            }
        }

        if (currectCommand == "write") {
            print("Say track name which you want to write to file: \n");
            getline(cin, command); // Читання імені трека
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
