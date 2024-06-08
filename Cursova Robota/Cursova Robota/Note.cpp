#include "Note.h"

// Записуємо у пустому конструкторі пусту ноту
Note::Note() {
    currectNote = "";
}

// Пустий деструктор
Note::~Note() {}


// Конструктор з параметром для ноти, при отримані ноти він запише її
Note::Note(string note) {
    this->currectNote = note;
}

// Повертає копію ноти
string Note::GetNote() {
    return Note::currectNote;
}

// Перевіряє на ноту
bool Note::isNote(string currentNote) {
    // Велика октава
    if (currentNote == "C" || currentNote == "C2") return true;
    if (currentNote == "D" || currentNote == "D2") return true;
    if (currentNote == "E" || currentNote == "E2") return true;
    if (currentNote == "F" || currentNote == "F2") return true;
    if (currentNote == "G" || currentNote == "G2") return true;
    if (currentNote == "A" || currentNote == "A2") return true;
    if (currentNote == "H" || currentNote == "B2") return true;
    // Маленька октава
    if (currentNote == "c" || currentNote == "C3") return true;
    if (currentNote == "d" || currentNote == "D3") return true;
    if (currentNote == "e" || currentNote == "E3") return true;
    if (currentNote == "f" || currentNote == "F3") return true;
    if (currentNote == "a" || currentNote == "A3") return true;
    if (currentNote == "g" || currentNote == "G3") return true;
    if (currentNote == "h" || currentNote == "B3") return true;
    // Перша октава
    if (currentNote == "c1" || currentNote == "C4") return true;
    if (currentNote == "d1" || currentNote == "D4") return true;
    if (currentNote == "e1" || currentNote == "E4") return true;
    if (currentNote == "f1" || currentNote == "F4") return true;
    if (currentNote == "g1" || currentNote == "G4") return true;
    if (currentNote == "a1" || currentNote == "A4") return true;
    if (currentNote == "h1" || currentNote == "B4") return true;
    // Друга октава  	 
    if (currentNote == "c2" || currentNote == "C5") return true;
    if (currentNote == "d2" || currentNote == "D5") return true;
    if (currentNote == "e2" || currentNote == "E5") return true;
    if (currentNote == "f2" || currentNote == "F5") return true;
    if (currentNote == "g2" || currentNote == "G5") return true;
    if (currentNote == "a2" || currentNote == "A5") return true;
    if (currentNote == "h2" || currentNote == "B5") return true;
    // Третя октава
    if (currentNote == "c3" || currentNote == "C6") return true;
    if (currentNote == "d3" || currentNote == "D6") return true;
    if (currentNote == "e3" || currentNote == "E6") return true;
    if (currentNote == "f3" || currentNote == "F6") return true;
    if (currentNote == "g3" || currentNote == "G6") return true;
    if (currentNote == "a3" || currentNote == "A6") return true;
    if (currentNote == "h3" || currentNote == "B6") return true;
    // Четверта октава   
    if (currentNote == "c4" || currentNote == "C7") return true;
    if (currentNote == "d4" || currentNote == "D7") return true;
    if (currentNote == "e4" || currentNote == "E7") return true;
    if (currentNote == "f4" || currentNote == "F7") return true;
    if (currentNote == "g4" || currentNote == "G7") return true;
    if (currentNote == "a4" || currentNote == "A7") return true;
    if (currentNote == "h4" || currentNote == "B7") return true;
    // П'ята октава
    if (currentNote == "c5" || currentNote == "C8") return true;
    if (currentNote == "d5" || currentNote == "D8") return true;
    if (currentNote == "e5" || currentNote == "E8") return true;
    if (currentNote == "f5" || currentNote == "F8") return true;
    if (currentNote == "g5" || currentNote == "G8") return true;
    if (currentNote == "a5" || currentNote == "A8") return true;
    if (currentNote == "h5" || currentNote == "B8") return true;
    // Для ноти без звука
    if (currentNote == "") { return true; }
    else { return false; }

}

// Перевіряє на тривалість ноти
bool Note::isDuration(string currentDuration) {
    if (currentDuration == "1") { return true; }
    if (currentDuration == "1/2") { return true; }
    if (currentDuration == "1/4") { return true; }
    if (currentDuration == "1/8") { return true; }
    if (currentDuration == "1/16") { return true; }
    if (currentDuration == "1/32") { return true; }
    else {
        return false;
    }
};

// Повертає частоту ноти
DWORD Note::GetFrequency() {
    // Велика октава
    if (currectNote == "C" || currectNote == "C2") return 65.406;
    if (currectNote == "D" || currectNote == "D2") return 73.416;
    if (currectNote == "E" || currectNote == "E2") return 82.406;
    if (currectNote == "F" || currectNote == "F2") return 87.307;
    if (currectNote == "G" || currectNote == "G2") return 97.999;
    if (currectNote == "A" || currectNote == "A2") return 110.00;
    if (currectNote == "H" || currectNote == "B2") return 123.47;
    // Маленька октава
    if (currectNote == "c" || currectNote == "C3") return 130.81;
    if (currectNote == "d" || currectNote == "D3") return 146.83;
    if (currectNote == "e" || currectNote == "E3") return 164.81;
    if (currectNote == "f" || currectNote == "F3") return 174.61;
    if (currectNote == "g" || currectNote == "G3") return 196.00;
    if (currectNote == "a" || currectNote == "A3") return 220.00;
    if (currectNote == "h" || currectNote == "B3") return 246.94;
    // Перша октава
    if (currectNote == "c1" || currectNote == "C4") return 261.63;
    if (currectNote == "d1" || currectNote == "D4") return 293.67;
    if (currectNote == "e1" || currectNote == "E4") return 329.63;
    if (currectNote == "f1" || currectNote == "F4") return 349.23;
    if (currectNote == "g1" || currectNote == "G4") return 392.00;
    if (currectNote == "a1" || currectNote == "A4") return 440.00;
    if (currectNote == "h1" || currectNote == "B4") return 493.88;
    // Друга октава  	 
    if (currectNote == "c2" || currectNote == "C5") return 523.25;
    if (currectNote == "d2" || currectNote == "D5") return 587.33;
    if (currectNote == "e2" || currectNote == "E5") return 659.26;
    if (currectNote == "f2" || currectNote == "F5") return 698.46;
    if (currectNote == "g2" || currectNote == "G5") return 783.99;
    if (currectNote == "a2" || currectNote == "A5") return 880.00;
    if (currectNote == "h2" || currectNote == "B5") return 987.77;
    // Третя октава
    if (currectNote == "c3" || currectNote == "C6") return 1046.5;
    if (currectNote == "d3" || currectNote == "D6") return 1174.7;
    if (currectNote == "e3" || currectNote == "E6") return 1318.5;
    if (currectNote == "f3" || currectNote == "F6") return 1396.9;
    if (currectNote == "g3" || currectNote == "G6") return 1568.0;
    if (currectNote == "a3" || currectNote == "A6") return 1760.0;
    if (currectNote == "h3" || currectNote == "B6") return 1975.5;
    // Четверта октава   
    if (currectNote == "c4" || currectNote == "C7") return 2093.0;
    if (currectNote == "d4" || currectNote == "D7") return 2349.3;
    if (currectNote == "e4" || currectNote == "E7") return 2637.0;
    if (currectNote == "f4" || currectNote == "F7") return 2793.8;
    if (currectNote == "g4" || currectNote == "G7") return 3136.0;
    if (currectNote == "a4" || currectNote == "A7") return 3520.0;
    if (currectNote == "h4" || currectNote == "B7") return 3951.1;
    // П'ята октава
    if (currectNote == "c5" || currectNote == "C8") return 4186.0;
    if (currectNote == "d5" || currectNote == "D8") return 4698.6;
    if (currectNote == "e5" || currectNote == "E8") return 5274.0;
    if (currectNote == "f5" || currectNote == "F8") return 5587.7;
    if (currectNote == "g5" || currectNote == "G8") return 6271.9;
    if (currectNote == "a5" || currectNote == "A8") return 7040.0;
    if (currectNote == "h5" || currectNote == "B8") return 7902.1;
    // Для ноти без звука
    if (currectNote == "") return 0;
}
