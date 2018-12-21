#pragma once
#include <SDL/SDL_mixer.h>
#include <vector>
#include <iostream>

class AudioController {

public:
    // Constructor
    AudioController();
    // Destructor
    ~AudioController();

    // Initializer, called in constructor
    void initAudio();
    // Close audio, called in destructor
    void closeAudio();

    // Music Functions
    Mix_Music* createMusic(const char* filename);
    void addMusic(Mix_Music* music);
    //void playMusic(Mix_Music* music);
    void playMusic(unsigned int i);
    void freeMusic(Mix_Music* music);

private:
    std::vector<Mix_Music*> m_music;
};