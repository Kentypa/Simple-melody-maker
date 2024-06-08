#ifndef SOUND_H
#define SOUND_H

#include "Note.h"
#include <string>
// Створення классу Звук, який має ноту та длительность ноти
class Sound {
public:
    Sound() {}
    Sound(string note, string currectDuration);

    // Повертає ноту
    Note GetNote(); 

    // Повертає тривалість ноти
    string GetDuration();

    // Повертає звук в форматі по типу C2 1/8
    string GetSoundInString();
private:
    Note currentNote;
    string currentDuration;
};
#endif