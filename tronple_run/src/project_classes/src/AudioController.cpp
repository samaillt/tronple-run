#include "project_classes/AudioController.hpp"
#include "project_classes/Exception.hpp"

AudioController::AudioController()
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

Mix_Music *AudioController::createMusic(const char *filename)
{
    Mix_Music *music;
    FILE *f = fopen(filename, "rb");
    // if (f == NULL) { 
    //     std::cout << "error filename music" << std::endl;
    // } 
    // else { 
    //     fclose(f); 
    // }
    try {
        if (f == NULL){
            Exception err1(1,2,"Error filename music");
            throw err1;
        }
        else
            fclose(f);
    } catch(const Exception &err){
        std::cerr << "Exception lancée : " << std::endl << "Niveau : " << err.getLevel() << std::endl << "Code : " << err.getCode() << std::endl << err.what() << std::endl;
    }

    music = Mix_LoadMUS(filename);
    return music;
}

void AudioController::addMusic(Mix_Music* music)
{
    _music.push_back(music);
}

void AudioController::playMusic(uint i)
{
    if (_music.size() >= i+1)
        Mix_PlayMusic(_music[i], -1);
    else
        std::cout << "Playlist is empty." << std::endl;
}

void AudioController::freeMusic(Mix_Music* music)
{
    Mix_FreeMusic(music);
}

AudioController::~AudioController()
{
    for(unsigned int i = 0; i < _music.size(); ++i)
        freeMusic(_music[i]);
    Mix_CloseAudio();
}