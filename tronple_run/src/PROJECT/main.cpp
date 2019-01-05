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

/* FPS */
static const Uint32 FRAMERATE_MILLISECONDS = 1000 / 60;

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
    Camera *camera = &trackball_cam;

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
  bool jump = false;
  bool down = false;
  bool right = false;
  bool left = false;
  while(!done) {

    // Menu display

    /*********************************
     * GAME APPLICATION LOOP
     *********************************/

    while(game) {

      Uint32 startTime = SDL_GetTicks();

      // Event loop:

      SDL_Event e;
      while(windowManager.pollEvent(e)) {
        switch (e.type) {
          case SDL_QUIT:
            game = false; // Leave the loop after this iteration
            done = true; // Leave the main loop after this iteration
            break;
          default:
            break;
        }
        /* Traitement d'evenements liés à la caméra : */
        if (!lock_camera){
          switch(e.type) {
            /* Touche clavier */
            case SDL_KEYDOWN:{
              float zoom = 1.f;
              switch (e.key.keysym.sym){
                case SDLK_PAGEDOWN:
                  camera->moveFront(-zoom);
                  break;
                case SDLK_PAGEUP:
                  camera->moveFront(zoom);
                  break;
                default:
                  break;
              }
              break;
            }
            case SDL_MOUSEMOTION:{
              float rotation_angle = 0.02f;
              if (e.motion.xrel != 0 )
                camera->rotateLeft(float(-e.motion.xrel) * rotation_angle);
              if (e.motion.yrel != 0 )
                camera->rotateUp(float(-e.motion.yrel) * rotation_angle);
              break;
            }
            default:
              break;
          }
        }
        else {
          // Possibility to unlock camera
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

      /* Traitement d'evenements liés au personnage : */
      switch(e.type) {
        /* Touche clavier */
        case SDL_KEYDOWN:{
          switch (e.key.keysym.sym){
            case SDLK_z:
              jump = true;
              break;
            case SDLK_q:
              left = true;
              break;
            case SDLK_s:
              down = true;
              break;
            case SDLK_d:
              right = true;
              break;
            default:
              break;
          }
          break;
        }
        case SDL_KEYUP:{
          switch (e.key.keysym.sym){
            case SDLK_z:
              jump = false;
              break;
            case SDLK_q:
              left = false;
              break;
            case SDLK_s:
              down = false;
              break;
            case SDLK_d:
              right = false;
              break;
            default:
              break;
          }
          break;
        }
        default:
          break;
      }

      // Player automatic forward movement
      player.moveForward(player.getSpeed());

      // Specific movement actions
      if (jump)
        player.jump();
      else 
        player.resetVerticalPosition();
      if (right)
        player.moveRight();
      if (left)
        player.moveLeft();
      if (!right && !left)
        player.resetHorizontalPosition();
      if (down)
        player.scaleDown();
      else 
        player.resetScale();

      // Collision check

      // COINS

      for (auto it = levelCoins.begin(); it != levelCoins.end();) {
        if (game_controller.checkAABBCollision(player,**it)) {
          player.inscrementScore(10);
          std::cout << player.getScore() << std::endl;
          it = levelCoins.erase(it);
        }
        else
          ++it;
      }

      // OBSTACLES (ARCHES AND BLOCKS);

      for (auto it = levelArches.begin(); it != levelArches.end(); ++it) {
        if (game_controller.checkAABBCollision(player,**it)) {
          std::cout << "Oh l'erreur, vous avez foncé dans une arche :o" << std::endl;
          game = false; // Leave the loop after this iteration
          done = true; // Leave the main loop after this iteration
        }
      }

      for (auto it = levelBlocks.begin(); it != levelBlocks.end(); ++it) {
        if (game_controller.checkAABBCollision(player,**it)) {
          std::cout << "Oh l'erreur, vous avez foncé dans un obstacle :o" << std::endl;
          game = false; // Leave the loop after this iteration
          done = true; // Leave the main loop after this iteration
        }
      }

      // HOLES AND ARRIVALS

      for (auto it = levelArrivals.begin(); it != levelArrivals.end(); ++it) {
        if (game_controller.checkArrivalsAABBCollision(player,**it)) {
          std::cout << "Bravo ! Vous avez réussi ce niveau. Votre score : " << player.getScore() << std::endl;
          game = false; // Leave the loop after this iteration
          done = true; // Leave the main loop after this iteration
        }
      }

      // Updtate player score

      /*********************************
      * GAME RENDERING
      *********************************/

      // ViewMatrix / Map / User Interface

      // Pause menu if game is paused

      glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

      /* Calcul de la caméra */
      if (camera == &trackball_cam)
        renderController.setGlobalMVMatrix(glm::translate(camera->getViewMatrix(), glm::vec3(-(player.getPosX()), -(player.getPosZ()), -(player.getPosY()))));
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

      /* Computes time spent during iteration */
      Uint32 elapsedTime = SDL_GetTicks() - startTime;

      /* If too few, pause program */
      if(elapsedTime < FRAMERATE_MILLISECONDS) {
        SDL_Delay(FRAMERATE_MILLISECONDS - elapsedTime);
      }
    }
  }
  return EXIT_SUCCESS;
}