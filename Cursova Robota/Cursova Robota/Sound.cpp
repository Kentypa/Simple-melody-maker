#include "Sound.h"

Sound::Sound(string note, string currectDuration) {
    this->currentNote = Note(note);
    this->currentDuration = currectDuration;
}

// Повертає ноту
Note Sound::GetNote() {
    return this->currentNote;
}
// Повертає тривалість ноти
string Sound::GetDuration() {
    return this->currentDuration;
}

// Перевод ноти у строку в форматі по типу C2 1/8
string Sound::GetSoundInString() {
    string tempStr = currentNote.GetNote() + " " + currentDuration + "\n";
    return tempStr;
}