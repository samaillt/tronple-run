#include <glimac/SDLWindowManager.hpp>
#include <SDL/SDL_mixer.h>
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
#include "project_classes/Camera.hpp"

#include "project_classes/Level.hpp"
#include "project_classes/GameController.hpp"
#include "project_classes/Cell.hpp"

#include <project_classes/Model.hpp>
#include <project_classes/RenderController.hpp>
#include <project_classes/Program.hpp>

#include "project_classes/AudioController.hpp"

using namespace glimac;

void printInfos(const Cell *cell){
      std::cout << "Type : " << cell->getType() << std::endl;
      std::cout << "xCoord : " << cell->getPosX() << std::endl;    
      std::cout << "yCoord : " << cell->getPosY() << std::endl;    
      std::cout << "zCoord : " << cell->getPosZ() << std::endl << std::endl;  
}

int main(int argc, char** argv) {

    /*********************************
   * INITIALIZATION OF WINDOW 
   *********************************/

  // Initialize SDL and open a window
  const int WINDOW_WIDTH = 1000;
  const int WINDOW_HEIGTH = 1000;
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
  std::cout << "OpenGL Version : " << glGetString(GL_VERSION) << std::endl;
  std::cout << "GLEW Version : " << glewGetString(GLEW_VERSION) << std::endl;
  
  CoinProgram coinProgram(applicationPath);

  ProgramList programList;
  programList.coinProgram = &coinProgram;

  /*********************************
   * INITIALIZATION OF LEVEL & GAME
   *********************************/

    Level level("1.ppm");
    GameController game_controller(&level);
    game_controller.loadLevel();

    Player player = level.getPlayer();

    std::vector<Cell*> levelCells = level.getCells();
    std::vector<Coin*> levelCoins = level.getCoins();
    std::vector<Block*> levelBlocks = level.getBlocks();
    std::vector<Arch*> levelArches = level.getArches();
    std::vector<Arrival*> levelArrivals = level.getArrivals();
    std::vector<Hole*> levelHoles = level.getHoles();

    // Loading level test
    // for_each(levelCells.begin(), levelCells.end(), printInfos);

  /*********************************
   * INITIALIZATION OF CAMERAS
   *********************************/

    TrackballCamera trackball_cam(5.f,2.f,0.f,0.f);
    FreeflyCamera freefly_cam;
    trackball_cam.rotateLeft(180);
    freefly_cam.rotateLeft(180);
    Camera *camera = &freefly_cam;

  /*********************************
   * INITIALIZATION OF RENDERING
   *********************************/

    RenderController renderController(&windowManager, &programList);
    renderController.VModel(0);
    renderController.VModel(1);
    renderController.VModel(2);
    std::cout << "OK" << std::endl;

    glEnable(GL_DEPTH_TEST);

    glm::mat4 ProjMatrix, MVMatrix, NormalMatrix, globalMVMatrix;
    ProjMatrix = glm::perspective(glm::radians(70.0f), (float) (WINDOW_WIDTH / WINDOW_HEIGTH), 0.1f, 100.f); 
    renderController.setProjMatrix(ProjMatrix);

  /*********************************
   * INITIALIZATION OF AUDIO
   *********************************/

    AudioController audioController = AudioController();
    audioController.addMusic(audioController.createMusic("../src/assets/audio/derezzed.mp3"));
    audioController.playMusic(0);

  /*********************************
   * MENU 
   *********************************/

  /*********************************
   * MENU APPLICATION LOOP
   *********************************/

  bool done = false;
  bool game = true;
  bool lock_camera = false;
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
          done = true;
        }
        /* Traitement d'evenements liés à la caméra : */
        if (!lock_camera){
          switch(e.type) {
            /* Touche clavier */
            case SDL_KEYDOWN:{
              float zoom = 1.f;
              if (e.key.keysym.sym == SDLK_DOWN)
                camera->moveFront(-zoom);
              if (e.key.keysym.sym == SDLK_UP)
                camera->moveFront(zoom);
              if (e.key.keysym.sym == SDLK_ESCAPE)
                done = true;
              break;
            }
            case SDL_MOUSEMOTION:{
              float rotation_angle = 0.02f;
              if ( e.motion.xrel != 0 )
                camera->rotateLeft(float(-e.motion.xrel) * rotation_angle);
              if ( e.motion.yrel != 0 )
                camera->rotateUp(float(-e.motion.yrel) * rotation_angle);
              break;
            }
            default:
              break;
          }
        }
        else {

        }
      }

      // Pause menu

      /*********************************
       * CAMERA MANAGEMENT
       *********************************/

      freefly_cam.setCameraOnPlayer(player);

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

      glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

      /* Calcul de la caméra */
      if (camera == &trackball_cam)
        renderController.setGlobalMVMatrix(glm::translate(camera->getViewMatrix(), glm::vec3(-(player.getPosX()), 0, -(player.getPosY()))));
      else
        renderController.setGlobalMVMatrix(camera->getViewMatrix());

      /* BIKE */
      renderController.bindModelVAO(1);
      renderController.useProgram(COIN);
      MVMatrix = renderController.getGlobalMVMatrix() * renderController.useMatrixBike(player.getPosX(), player.getPosY(), player.getPosZ());
      renderController.applyTransformations(COIN,MVMatrix);
      renderController.drawModel(1);
      renderController.debindVAO();

      auto displayElement = [&](const Cell *cell){
        switch (cell->getType()) {
          case 'c' :
            MVMatrix = renderController.getGlobalMVMatrix() * renderController.useMatrixCoin(cell->getPosX(), cell->getPosY(), cell->getPosZ());
            renderController.applyTransformations(COIN,MVMatrix);
            break;
          default :
            MVMatrix = renderController.getGlobalMVMatrix() * renderController.useMatrixCell(cell->getPosX(), cell->getPosY(), cell->getPosZ());
            renderController.applyTransformations(COIN,MVMatrix);
            break;
        }
        renderController.drawModel(0);
      };

      /* COIN */
      renderController.bindModelVAO(0);
      renderController.useProgram(COIN);
      // Coins display
      std::for_each(levelCoins.begin(), levelCoins.end(), displayElement);
      renderController.debindVAO();

      /* CUBES */
      renderController.bindModelVAO(2);
      renderController.useProgram(COIN);
      // Cells display
      std::for_each(levelCells.begin(), levelCells.end(), displayElement);
      std::for_each(levelBlocks.begin(), levelBlocks.end(), displayElement);
      std::for_each(levelArches.begin(), levelArches.end(), displayElement);
      std::for_each(levelArrivals.begin(), levelArrivals.end(), displayElement);
      renderController.debindVAO();

      // Update the display
      windowManager.swapBuffers();
    }
  }
  return EXIT_SUCCESS;
}