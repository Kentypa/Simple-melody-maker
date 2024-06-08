#include "TSoundPlayer.h"

// Функція для розділення строчки на елементи розділенні за допомогою роздільника
vector<string> Split(string text, char by) {
    vector<string> tempArray;
    string tempStr = "";

    for (int i = 0; i < text.size(); i++) {
        if (text[i] != by) {
            tempStr += text[i];
        }
        else {
            tempArray.push_back(tempStr);
            tempStr = "";
        }
    }

    if (!tempStr.empty()) {
        tempArray.push_back(tempStr);
    }

    return tempArray;
}


TSoundPlayer::TSoundPlayer() {

}

TSoundPlayer::TSoundPlayer(string name, vector<Sound> list) {
    this->soundName = name;
    this->soundList = list;
}

// Заповнюємо об'єкт классу вхідними данними
void TSoundPlayer::Init(string name, vector<Sound> sounds) {
    this->soundName = name;
    this->soundList = sounds;
}

// Записуємо у файл
void TSoundPlayer::WriteToFile(string path, string filename) {
    ofstream musicFile(path + filename);

    // Пробігаємось в циклі по массиву звуків і записуємо всі звуки до файлу
    for (Sound sound : soundList) {
        musicFile << sound.GetSoundInString();
    }
    musicFile.close();
}

// Повертає тривалість ноти
double TSoundPlayer::GetDurationInNum(string duration) {
    if (duration == "1") { return 1024; }
    if (duration == "1/2") { return 512; }
    if (duration == "1/4") { return 256; }
    if (duration == "1/8") { return 128; }
    if (duration == "1/16") { return 64; }
    if (duration == "1/32") { return 32; }
    return 0;
}

// Додає до массиву звуків ще один звук
void TSoundPlayer::AddToTrackSound(string duration, string note) {
    soundList.push_back(Sound(note, duration));
};

// Вилучає останній звук з массиву
void TSoundPlayer::RemoveFromTrackLastSound() {
    soundList.pop_back();
};

// Виводить статус мелодії та плеєра
void TSoundPlayer::PlayerStatus() {
    println("Name of sound: " << soundName);
    println("First note: " << soundList.at(0).GetNote().GetNote());
    println("Speed multipler of sound: " << timeSpeed);
    double soundsLength = 0;

    // Рахує довжину мелодії у секундах
    for (Sound sound : soundList) {
        soundsLength += (GetDurationInNum(sound.GetDuration()) * 0.001);
    }
    println("Sound lenght in seconds: " << (soundsLength * 1));
}

// Грає мелодію
void TSoundPlayer::Play(string pathToFile) {
    println("Current sound is: " << soundName);

    // Перевіряє чи це з файлу мелодія чи ні
    if (pathToFile == "") {
        for (Sound sound : soundList) {
            Beep(sound.GetNote().GetFrequency() * timeSpeed, ((GetDurationInNum(sound.GetDuration()) / timeSpeed)));
            Beep(100, 100);
            println("Currect note is: " << sound.GetNote().GetNote());
        }
    }
    else {
        string musicNote;
        // Зчитує файл
        ifstream musicFile(pathToFile);

        while (getline(musicFile, musicNote)) {
            vector<string> splitted = Split(musicNote, ' ');
            Sound tempSound = Sound(splitted.at(0), splitted.at(1));
            Beep(tempSound.GetNote().GetFrequency() * timeSpeed, ((GetDurationInNum(tempSound.GetDuration()) / timeSpeed)));
            println("Currect note is: " << tempSound.GetNote().GetNote());
        }

        musicFile.close();
    }
}

// Змінює тональність
void TSoundPlayer::ChangeTonality(double newTonality) {
    this->timeSpeed = newTonality;
}

// Повертає ссилку на всі звуки у треці
vector<Sound>* TSoundPlayer::GetSoundList() {
    return &this->soundList;
}

// Повертає ссилку на назву треку
string& TSoundPlayer::GetSoundName() {
    return this->soundName;
}