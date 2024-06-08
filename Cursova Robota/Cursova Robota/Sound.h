#ifndef SOUND_H
#define SOUND_H

#include "Note.h"
#include <string>
// Створення классу Звук, який має ноту та длительность ноти
class Sound {
public:
    Sound() {}
    Sound(string note, string currectDuration);

    Note GetNote();

    string GetDuration();

    string GetSoundInString();
private:
    Note currentNote;
    string currentDuration;
};
#endif