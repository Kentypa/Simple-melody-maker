#include "Sound.h"

Sound::Sound(string note, string currectDuration) {
    this->currentNote = Note(note);
    this->currentDuration = currectDuration;
}

Note Sound::GetNote() {
    return this->currentNote;
}

string Sound::GetDuration() {
    return this->currentDuration;
}

// ������� ���� � ������ ��� �������
string Sound::GetSoundInString() {
    string tempStr = currentNote.GetNote() + " " + currentDuration + "\n";
    return tempStr;
}