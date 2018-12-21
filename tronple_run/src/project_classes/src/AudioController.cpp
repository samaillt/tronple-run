#include "project_classes/AudioController.hpp"

// --- CONSTRUCTOR | DESTRUCTOR --- //

// CONSTRUCTOR
AudioController::AudioController()
{
    initAudio();

}
// DESTRUCTOR
AudioController::~AudioController()
{
    for(unsigned int i = 0; i < m_music.size(); ++i)
        freeMusic(m_music[i]);
    closeAudio();
}
// INITIALIZE AUDIO
void AudioController::initAudio()
{
    if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1) //Initialisation de l'API Mixer
    {
        printf("%s", Mix_GetError());
    }
    else
    {
        Mix_VolumeMusic(MIX_MAX_VOLUME / 8);
        Mix_AllocateChannels(9);
    }
}
// CLOSE AUDIO
void AudioController::closeAudio()
{
    Mix_CloseAudio();
}

// --- MUSIC --- //

// CREATE MUSIC
Mix_Music * AudioController::createMusic(const char* filename)
{
    Mix_Music *music;
    if (!filename) {
        std::cout << "music filename error" << std::endl;
    }
    music = Mix_LoadMUS(filename);
    return music;
}

// ADD MUSIC ON THE MUSIC LIST
void AudioController::addMusic(Mix_Music* music)
{
    m_music.push_back(music);
}
// PLAY A MUSIC
// void AudioController::playMusic(Mix_Music* music)
// {
//     Mix_PlayMusic(music, -1);
// }
void AudioController::playMusic(unsigned int i)
{
    if (m_music.size() >= i+1)
        Mix_PlayMusic(m_music[i], -1);//playMusic(m_music[i]);
    else
        std::cout << "There's not enough music" << std::endl;
}
// FREE MUSIC
void AudioController::freeMusic(Mix_Music* music)
{
    Mix_FreeMusic(music);
}