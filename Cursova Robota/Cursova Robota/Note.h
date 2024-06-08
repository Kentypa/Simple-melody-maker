#ifndef NOTE_H
#define NOTE_H

#include <string>
#include <Windows.h>
using namespace std;

class Note {
public:
    Note();

    ~Note();

    Note(string note);

    string GetNote(); // Повертає ноту

    static bool isNote(string currentNote); // Перевіряє на ноту

    static bool isDuration(string currentDuration); // Перевіряє на правильну тривалість ноти

    DWORD GetFrequency(); // Повертає частоту у форматі Double Word
private:
    string currectNote;
};
#endif