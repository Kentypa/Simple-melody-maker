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

void TSoundPlayer::Init(string name, vector<Sound> sounds) {
    this->soundName = name;
    this->soundList = sounds;
}

void TSoundPlayer::WriteToFile(string path, string filename) {
    ofstream musicFile(path + filename);
    for (Sound sound : soundList) {
        musicFile << sound.GetSoundInString();
    }
    musicFile.close();
}

double TSoundPlayer::GetDurationInNum(string duration) {
    if (duration == "1") { return 1024; }
    if (duration == "1/2") { return 512; }
    if (duration == "1/4") { return 256; }
    if (duration == "1/8") { return 128; }
    if (duration == "1/16") { return 64; }
    if (duration == "1/32") { return 32; }
    return 0;
}

void TSoundPlayer::AddToTrackSound(string duration, string note) {
    soundList.push_back(Sound(note, duration));
};

void TSoundPlayer::RemoveFromTrackLastSound() {
    soundList.pop_back();
};

void TSoundPlayer::PlayerStatus() {
    println("Name of sound: " << soundName);
    println("First note: " << soundList.at(0).GetNote().GetNote());
    println("Speed multipler of sound: " << timeSpeed);
    double soundsLength = 0;
    for (Sound sound : soundList) {
        soundsLength += (GetDurationInNum(sound.GetDuration()) * 0.001);
    }
    println("Sound lenght in seconds: " << (soundsLength * 1));
}

void TSoundPlayer::Play(string pathToFile) {
    println("Current sound is: " << soundName);

    if (pathToFile == "") {
        for (Sound sound : soundList) {
            Beep(sound.GetNote().GetFrequency() * timeSpeed, ((GetDurationInNum(sound.GetDuration()) / timeSpeed)));
            Beep(100, 100);
            println("Currect note is: " << sound.GetNote().GetNote());
        }
    }
    else {
        string musicNote;
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