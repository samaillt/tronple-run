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

    // Loading level test
    // for_each(levelCells.begin(), levelCells.end(), printInfos);

  /*********************************
   * INITIALIZATION OF RENDERING
   *********************************/

    RenderController renderController(&windowManager, &programList);
    renderController.VModel(0);
    renderController.VModel(1);
    renderController.VModel(2);

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

  uint chosen_level = 0;
  bool done = false;
  bool game = false;
  bool lock_camera = false;
  bool switch_camera = false;
  bool jump = false;
  bool down = false;
  bool right = false;
  bool orientateRight = false;
  bool left = false;
  bool orientateLeft = false;
  bool fall = true;
  bool pause = false;
  SDL_Event e;

  std::cout << "WELCOME IN TRONPLE RUN" << std::endl << std::endl;

  while(!done) {

    // Menu display
      std::cout << "MAIN MENU" << std::endl << std::endl;
      std::cout << "ESC : Quit" << std::endl;
      std::cout << "SPACE : Level choice" << std::endl;

      while(!game){
        while(windowManager.pollEvent(e)) {
          switch (e.type) {
            case SDL_QUIT:
              return EXIT_SUCCESS;
              break;
            case SDL_KEYDOWN:
              switch (e.key.keysym.sym){
                case SDLK_ESCAPE:
                  return EXIT_SUCCESS;
                  break;
                case SDLK_SPACE:
                  game = true;
                  break;
                default:
                  break;
              }
              break;
            default:
              break;
          }
        }
      }

      std::cout << "Please choose a level (between 1 & 5)" << std::endl;
      while(chosen_level == 0){
        while(windowManager.pollEvent(e)) {
          switch (e.type) {
            case SDL_QUIT:
              return EXIT_SUCCESS;
              break;
            case SDL_KEYDOWN:
              switch (e.key.keysym.sym){
                case SDLK_F1:
                    chosen_level = 1;
                  break;
                case SDLK_F2:
                    chosen_level = 2;
                  break;
                case SDLK_F3:
                    chosen_level = 3;
                  break;
                case SDLK_F4:
                    chosen_level = 4;
                  break;
                case SDLK_F5:
                    chosen_level = 5;
                  break;
                default:
                  break;
              }
              break;
            default:
              break;
          }
        }
      }

    /*********************************
     * INITIALIZATION OF LEVEL & GAME
     *********************************/

      Level level(std::to_string(chosen_level)+ ".ppm");
      GameController game_controller(&level);
      game_controller.loadLevel();

      Player player = level.getPlayer();

      std::vector<Cell*> levelCells = level.getCells();
      std::vector<Coin*> levelCoins = level.getCoins();
      std::vector<Block*> levelBlocks = level.getBlocks();
      std::vector<Arch*> levelArches = level.getArches();
      std::vector<Arrival*> levelArrivals = level.getArrivals();
      std::vector<Hole*> levelHoles = level.getHoles();
      std::vector<Cell*> levelLeftTurns = level.getLeftTurns();
      std::vector<Cell*> levelRightTurns = level.getRightTurns();

    /*********************************
     * INITIALIZATION OF CAMERAS
     *********************************/

      TrackballCamera trackball_cam(5.f,2.f,0.f,0.f);
      FreeflyCamera freefly_cam;
      trackball_cam.rotateLeft(player.getOrientation());
      freefly_cam.rotateLeft(player.getOrientation());
      Camera *camera = &trackball_cam;

      game = true;

    while(game) {

      // Event loop:

      while(windowManager.pollEvent(e)) {
        switch (e.type) {
          case SDL_QUIT:
            game = false; // Leave the loop after this iteration
            done = true; // Leave the main loop after this iteration
            break;
          default:
            break;
        }
        /* Events for camera and pause: */
        switch(e.type){
          case SDL_KEYDOWN:{
            switch (e.key.keysym.sym){
              case SDLK_l:
                if (lock_camera == true){
                  lock_camera = false;
                } else
                  lock_camera = true;
                break;
              case SDLK_c:
                switch_camera = true;
                break;
              case SDLK_ESCAPE:
                if (pause == true){
                  game = false;
                  chosen_level = 0;
                  pause = false;
                }
                else
                  pause = true;
                break;
              case SDLK_SPACE:
                if (pause == true)
                  pause = false;
                break;
              default:
                break;
            }
            break;
          }
          case SDL_KEYUP:{
            switch (e.key.keysym.sym){
              case SDLK_c:
                if (switch_camera == true){
                  if (camera == &trackball_cam){
                    camera = &freefly_cam;
                  } else
                    camera = &trackball_cam;
                  switch_camera = false;
                }
                break;
              default:
                break;
            }
            break;
          }
        }
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
      }

      if (!pause){
        /*********************************
         * CAMERA MANAGEMENT
         *********************************/

        freefly_cam.setCameraOnPlayer(player);

        /*********************************
        * GAME MANAGEMENT
        *********************************/

        // Player movement

        /* Events : player */
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

        // Player gravity movement
        // Check first if on a ground then if not get down a little

        // Specific movement actions
        if (jump)
          player.jump();
        else 
          player.resetVerticalPosition();
        if (right){
          if (!orientateRight){
            player.moveRight();
            // Check if on right turn
            for (auto it = levelRightTurns.begin(); it != levelRightTurns.end();) {
              if (game_controller.check2DAABBCollision(player,**it)) {
                if ((player.getOrientation() == Player::FRONT || player.getOrientation() == Player::BACK) && !orientateRight) {
                  player.setHorizontalPos((**it).getPosY());
                }
                if ((player.getOrientation() == Player::LEFT || player.getOrientation() == Player::RIGHT) && !orientateRight) {
                  player.setHorizontalPos((**it).getPosX());
                }
                // std::cout << "Right turn" << std::endl;
                orientateRight = true;
                it = levelRightTurns.erase(it);
                break;
              } else {
                it++;
              }
            }
          } else {
            trackball_cam.rotateLeft(-player.getOrientation());
            freefly_cam.rotateLeft(-player.getOrientation());
            switch ((int)player.getOrientation()){
              case (int)Player::FRONT :
                player.setOrientation(Player::RIGHT);
                break;
              case (int)Player::LEFT :
                player.setOrientation(Player::FRONT);
                break;
              case (int)Player::BACK :
                player.setOrientation(Player::LEFT);
                break;
              case (int)Player::RIGHT :
                player.setOrientation(Player::BACK);
                break;
              default:
                break;
            }
            trackball_cam.rotateLeft(player.getOrientation());
            freefly_cam.rotateLeft(-player.getOrientation());
            orientateRight = false;
          }
        }
        if (left){
          if (!orientateLeft){
            player.moveLeft();
            // Check if on left turn
            for (auto it = levelLeftTurns.begin(); it != levelLeftTurns.end();) {
              if (game_controller.check2DAABBCollision(player,**it)) {
                if ((player.getOrientation() == Player::FRONT || player.getOrientation() == Player::BACK) && !orientateRight) {
                  player.setHorizontalPos((**it).getPosY());
                }
                if ((player.getOrientation() == Player::LEFT || player.getOrientation() == Player::RIGHT) && !orientateRight) {
                  player.setHorizontalPos((**it).getPosX());
                }
                // std::cout << "Left turn" << std::endl;
                orientateLeft = true;
                it = levelLeftTurns.erase(it);
                break;
              } else {
                it++;
              }
            }
          } else {
            trackball_cam.rotateLeft(-player.getOrientation());
            freefly_cam.rotateLeft(player.getOrientation());
            switch ((int)player.getOrientation()){
              case (int)Player::FRONT :
                player.setOrientation(Player::LEFT);
                break;
              case (int)Player::LEFT :
                player.setOrientation(Player::BACK);
                break;
              case (int)Player::BACK :
                player.setOrientation(Player::RIGHT);
                break;
              case (int)Player::RIGHT :
                player.setOrientation(Player::FRONT);
                break;
              default:
                break;
            }
            trackball_cam.rotateLeft(player.getOrientation());
            freefly_cam.rotateLeft(player.getOrientation());
            orientateLeft = false;
          }
        }
        if (!right && !left && !orientateLeft && !orientateRight)
          player.resetHorizontalPosition();
        if (down)
          player.scaleDown();
        else 
          player.resetScale();
            
        // Debug test
        // std::cout << "pos x : "<< player.getPosX()<< "pos y : "<< player.getPosY()<< "horizontal pos: "<< player.getHorizontalPos() << std::endl;

        // Player automatic forward movement
        player.moveForward(player.getSpeed());

        // Collision check

        // COINS

        for (auto it = levelCoins.begin(); it != levelCoins.end();) {
          if (game_controller.checkAABBCollision(player,**it)) {
            player.inscrementScore(50);
            it = levelCoins.erase(it);
          }
          else
            ++it;
        }

        // OBSTACLES (ARCHES AND BLOCKS);

        for (auto it = levelArches.begin(); it != levelArches.end(); ++it) {
          if (game_controller.checkAABBCollision(player,**it)) {
            std::cout << "Oh l'erreur, vous avez foncé dans une arche :o" << std::endl << std::endl;
            game = false;
            chosen_level = 0;
          }
        }

        for (auto it = levelBlocks.begin(); it != levelBlocks.end(); ++it) {
          if (game_controller.checkAABBCollision(player,**it)) {
            std::cout << "Oh l'erreur, vous avez foncé dans un obstacle :o" << std::endl << std::endl;
            game = false;
            chosen_level = 0;
          }
        }

        // HOLES AND ARRIVALS

        // Holes (basical test : without gravity)
        for (auto it = levelCells.begin(); it != levelCells.end(); ++it) {
          if (game_controller.check2DAABBCollision(player,**it)){
            if (fall){
              fall = false;
              chosen_level = 0;
            }
          }
        }
        if (fall && player.getPosZ() <= 1){
          std::cout << "Oh l'erreur, vous avez foncé dans le vide :o" << std::endl << std::endl;
          game = false;
          chosen_level = 0;
        } else {
          fall = true;
        }

        // Arrivals
        for (auto it = levelArrivals.begin(); it != levelArrivals.end(); ++it) {
          if (game_controller.check2DAABBCollision(player,**it)) {
            std::cout << "Bravo ! Vous avez réussi ce niveau. Votre score : " << player.getScore() << std::endl << std::endl;
            game = false;
            chosen_level = 0;
            break;
          }
        }

        // Updtate player score with traveled distance.

        player.inscrementScore(10 * player.getSpeed());
      } else {

        // Pause 
        // std::cout << "Your score : " << player.getScore() << std::endl;
      }

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
      MVMatrix = renderController.getGlobalMVMatrix() * renderController.useMatrixBike(player.getPosX(), player.getPosY(), player.getPosZ(), player.getOrientation());
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
    // Free memory
    levelCells.clear();
    levelCoins.clear();
    levelBlocks.clear();
    levelArches.clear();
    levelArrivals.clear();
    levelHoles.clear();
    levelLeftTurns.clear();
    levelRightTurns.clear();
  }
  return EXIT_SUCCESS;
}