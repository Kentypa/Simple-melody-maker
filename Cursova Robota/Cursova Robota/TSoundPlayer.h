#ifndef TSOUNDPLAYER_H
#define TSOUNDPLAYER_H

#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
#include <random>
#include "Note.h"
#include "Sound.h"

using namespace std;

#define println(text) cout << text << endl;

// Основний класс TSoundPlayer який має поля з ім'ям пісні, та самою массивом звук з якого збирається пісня
class TSoundPlayer {
public:
    TSoundPlayer();

    TSoundPlayer(string name, vector<Sound> list);

    void Init(string name, vector<Sound> sounds);

    void WriteToFile(string path, string filename);

    static double GetDurationInNum(string duration);

    void PlayerStatus();

    void Play(string pathToFile);

    void ChangeTonality(double newTonality);

    void AddToTrackSound(string duration, string note);

    void RemoveFromTrackLastSound();

    vector<Sound>* GetSoundList();
    
    // Повертає ссилку на назву треку
    string& GetSoundName();
    
private:
    string soundName;
    vector<Sound> soundList;
    double timeSpeed = 1;
};

static vector<string> allNotes{
    "C", "C2", "D", "D2", "E", "E2", "F", "F2", "G", "G2", "A", "A2", "B2", "c", "C3", "d", "D3"
    , "e", "E3", "f", "F3", "g", "G3", "a", "A3", "h", "B3", "c1", "C4", "d1", "D4", "e1", "E4",
    "f1", "F4", "g1", "G4", "a1", "A4", "h1", "B4", "c2", "C5", "d2", "D5", "e2", "E5", "f2", "F5",
    "g2", "G5", "a2", "A5", "h2", "B5", "c3", "C6", "d3", "D6", "e3", "E6", "f3", "F6", "g3", "G6", "a3",
    "A6", "h3", "B6", "c4", "C7", "d4", "D7", "e4", "E7", "f4", "F7", "g4", "G7", "a4", "A7", "h4", "B7",
    "c5", "C8", "d5", "D8", "e5", "E8", "f5", "F8", "g5", "G8", "a5", "A8", "h5", "B8" };

static vector<string> allDurations{ "1", "1/2", "1/4", "1/8", "1/16", "1/32" };
#endif