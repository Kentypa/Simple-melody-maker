#ifndef SOUND_H
#define SOUND_H

#include "Note.h"
#include <string>
// ��������� ������ ����, ���� �� ���� �� ������������ ����
class Sound {
public:
    Sound() {}
    Sound(string note, string currectDuration);

    // ������� ����
    Note GetNote(); 

    // ������� ��������� ����
    string GetDuration();

    // ������� ���� � ������ �� ���� C2 1/8
    string GetSoundInString();
private:
    Note currentNote;
    string currentDuration;
};
#endif