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

    string GetNote();

    DWORD GetFrequency();
private:
    string currectNote;
};
#endif