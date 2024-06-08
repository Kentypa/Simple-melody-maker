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

    string GetNote(); // ������� ����

    static bool isNote(string currentNote); // �������� �� ����

    static bool isDuration(string currentDuration); // �������� �� ��������� ��������� ����

    DWORD GetFrequency(); // ������� ������� � ������ Double Word
private:
    string currectNote;
};
#endif