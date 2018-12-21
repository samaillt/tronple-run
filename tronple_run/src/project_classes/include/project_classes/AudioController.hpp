#pragma once
#include <SDL/SDL_mixer.h>
#include <vector>
#include <iostream>

/// \class AudioController
/// \brief Class that set music (AudioController)
class AudioController {

private:
    std::vector<Mix_Music*> _music; /*!< Vectors of musics */

public:
    /// \brief Constructor
    AudioController();

    /// \brief Create music
    /// \param Takes a filename music
    /// \return Music data
    Mix_Music* createMusic(const char* filename);

    /// \brief Add music to the playlist
    /// \param Takes a filename music
    void addMusic(Mix_Music* music);

    /// \brief Play music
    /// \param Takes music index
    void playMusic(unsigned int i);

    /// \brief Free music
    /// \param Music data
    void freeMusic(Mix_Music* music);

    /// \brief Destructor
    ~AudioController();
};