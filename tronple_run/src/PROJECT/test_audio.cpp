#include <glimac/SDLWindowManager.hpp>
#include <GL/glew.h>
#include <iostream>
#include <cstddef>
#include <math.h>
#include <algorithm>
#include <vector>
#include <glimac/Program.hpp> 
#include <glimac/FilePath.hpp> 
#include <glimac/glm.hpp>
#include "project_classes/TrackballCamera.hpp"
#include "project_classes/FreeflyCamera.hpp"
#include "project_classes/Level.hpp"
#include "project_classes/GameController.hpp"
#include "project_classes/Cell.hpp"
#include "project_classes/AudioController.hpp"
#include <SDL/SDL_mixer.h>

using namespace glimac;

int main(int argc, char** argv) {

    /*********************************
   * INITIALIZATION OF WINDOW 
   *********************************/

  // Initialize SDL and open a window
  const int WINDOW_WIDTH = 800;
  const int WINDOW_HEIGTH = 800;
  SDLWindowManager windowManager(WINDOW_WIDTH, WINDOW_HEIGTH, "GLImac");


  // Initialize glew for OpenGL3+ support
  GLenum glewInitError = glewInit();
  if(GLEW_OK != glewInitError) {
      std::cerr << glewGetErrorString(glewInitError) << std::endl;
      return EXIT_FAILURE;
  };
    
  /*********************************
   * INITIALIZATION OF PROGRAMS
   *********************************/

  FilePath applicationPath(argv[0]);
  //Programs
  std::cout << "OpenGL Version : " << glGetString(GL_VERSION) << std::endl;
  std::cout << "GLEW Version : " << glewGetString(GLEW_VERSION) << std::endl;

  /*********************************
   * INITIALIZATION OF LEVEL & GAME
   *********************************/

    Level level("test.ppm");
    GameController game_controller(&level);
    game_controller.loadLevel();
    std::cout << level.getCells().size() << std::endl;
    /* Erreur de seg à regler : mauvaise gestion du vector */
    // std::for_each(level.getCells().begin(), level.getCells().end(), printInfos);

  /*********************************
   * INITIALIZATION OF CAMERAS
   *********************************/

  /*********************************
   * INITIALIZATION OF RENDERING
   *********************************/

  /*********************************
   * INITIALIZATION OF AUDIO
   *********************************/

  AudioController audioController = AudioController();
  audioController.addMusic(audioController.createMusic("../src/assets/audio/derezzed.mp3"));
  audioController.playMusic(0);
  //Mix_RewindMusic(); // pour rejouer la musique du début

  /*********************************
   * MENU 
   *********************************/

  /*********************************
   * MENU APPLICATION LOOP
   *********************************/

  bool done = false;
  bool game = false;
  while(!done) {

    // Event loop:

    SDL_Event e;
    while(windowManager.pollEvent(e)) {
      if(e.type == SDL_QUIT) {
        done = true; // Leave the loop after this iteration
      }
    }

    // Menu display

    /*********************************
     * GAME APPLICATION LOOP
     *********************************/

    while(game) {

      // Event loop:

      SDL_Event e;
      while(windowManager.pollEvent(e)) {
        if(e.type == SDL_QUIT) {
          game = false; // Leave the loop after this iteration
        }
      }

      // Pause menu

      /*********************************
       * CAMERA MANAGEMENT
       *********************************/

      /*********************************
       * GAME MANAGEMENT
       *********************************/

       /*********************************
       * GAME MANAGEMENT
       *********************************/

       // Player movement

       // Collision check

       // Updtate player informations

       /*********************************
       * GAME RENDERING
       *********************************/

       // ViewMatrix / Map / User Interface

       // Pause menu if game is paused

    }

  }

  return EXIT_SUCCESS;
}

