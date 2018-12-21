#include <glimac/SDLWindowManager.hpp>
#include <GL/glew.h>
#include <iostream>
#include <cstddef>
#include <vector>
#include <math.h>

#include <glimac/Program.hpp> 
#include <glimac/FilePath.hpp> 
#include <glimac/glm.hpp> 
#include <glimac/Image.hpp>

#include <project_classes/Model.hpp>
#include <project_classes/RenderController.hpp>
#include <project_classes/Program.hpp>


using namespace glimac;

int main(int argc, char** argv) {  
  // Initialize SDL and open a window
  const int WINDOW_WIDTH = 800;
  const int WINDOW_HEIGTH = 800;
  SDLWindowManager windowManager(WINDOW_WIDTH, WINDOW_HEIGTH, "GLImac");

  // Initialize glew for OpenGL3+ support
  GLenum glewInitError = glewInit();
  if(GLEW_OK != glewInitError) {
      std::cerr << glewGetErrorString(glewInitError) << std::endl;
      return EXIT_FAILURE;
  }  

  /* Init program */
  FilePath applicationPath(argv[0]);
  CoinProgram coinProgram(applicationPath);
  WorldProgram worldProgram(applicationPath);

  ProgramList programList;
  programList.coinProgram = &coinProgram;
  programList.worldProgram = &worldProgram;
  
  /* Load world texture */
  std::cout << "OpenGL Version : " << glGetString(GL_VERSION) << std::endl;
  std::cout << "GLEW Version : " << glewGetString(GLEW_VERSION) << std::endl;
    
  /*********************************
   * HERE SHOULD COME THE INITIALIZATION CODE
   *********************************/
  /* 1_ Construction de la sphère et de la caméra*/
  RenderController renderController = RenderController(&programList);
  renderController.VModel(0);
  renderController.VModel(1);

  /* 4_ Activation de la detection de la profondeur */
  glEnable(GL_DEPTH_TEST);
  
  /* 5-8_ Création des matrices de Projection, MV et Normales */
  glm::mat4 ProjMatrix, MVMatrix, NormalMatrix, globalMVMatrix;
  ProjMatrix = glm::perspective(glm::radians(70.0f), (float) (WINDOW_WIDTH / WINDOW_HEIGTH), 0.1f, 100.f); 
  renderController.setProjMatrix(ProjMatrix);
  
  // Chargement des textures

  // End Chargement des textures
  // bind vao

  // Application loop:
  bool done = false;
  float time = 0.0f;
  while(!done) {
    // Event loop:
    
    SDL_Event e;
    while(windowManager.pollEvent(e)) {
      if(e.type == SDL_QUIT) {
        done = true; // Leave the loop after this iteration
      }
        // Traitement d'evenements : 
        switch(e.type) {
          // Touche clavier 
          /*case SDL_KEYDOWN:
            if (e.key.keysym.sym == SDLK_DOWN)
              camera.moveFront(-5.f);
            if (e.key.keysym.sym == SDLK_UP)
              camera.moveFront(5.f);   
            if (e.key.keysym.sym == SDLK_LEFT)
              std::cout << "keyleft" << std::endl;
            if (e.key.keysym.sym == SDLK_RIGHT)
              std::cout << "keyright" << std::endl;
            break;
          case SDL_MOUSEMOTION:
            if (e.motion.xrel != 0)
              camera.rotateLeft( float(e.motion.xrel) * -0.1f);
            if (e.motion.yrel != 0)
              camera.rotateUp( float(e.motion.yrel) * -0.1f);
            break;*/
          default:
            break;
        }
    }

    /*********************************
     * HERE SHOULD COME THE RENDERING CODE
     *********************************/
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    /* Calcul de la caméra */
    globalMVMatrix = renderController.getMVMatrix();

    /* COIN */
    renderController.bindModelVAO(0);
    renderController.useProgram(COIN);
    MVMatrix = globalMVMatrix*glm::translate(glm::mat4(1), glm::vec3(0, 0, -5)); 
    MVMatrix = glm::rotate(MVMatrix, windowManager.getTime()/4, glm::vec3(0, 1, 0)); 
    MVMatrix = glm::scale(MVMatrix, glm::vec3(5, 1, 1)); 
    renderController.applyTransformations(COIN,MVMatrix);
    renderController.drawModel(0);

    MVMatrix = glm::translate(glm::mat4(1), glm::vec3(0, 2, -5));
    renderController.applyTransformations(COIN,MVMatrix);
    renderController.drawModel(0);
    renderController.debindVAO();

    /* MOTO */
    renderController.bindModelVAO(1);
    renderController.useProgram(COIN);
    MVMatrix = globalMVMatrix*glm::translate(glm::mat4(1), glm::vec3(0, 0, -5)); 
    MVMatrix = glm::rotate(MVMatrix, windowManager.getTime()/4, glm::vec3(0, 1, 0)); 
    MVMatrix = glm::scale(MVMatrix, glm::vec3(1, 1, 1)); 
    glUniformMatrix4fv(coinProgram.uMVPMatrix, 1, GL_FALSE, glm::value_ptr(ProjMatrix*MVMatrix));
    glUniformMatrix4fv(coinProgram.uMVMatrix, 1, GL_FALSE, glm::value_ptr(MVMatrix));
    glUniformMatrix4fv(coinProgram.uNormalMatrix, 1, GL_FALSE, glm::value_ptr(NormalMatrix));
    renderController.drawModel(1);
    renderController.debindVAO();

    // Update the display
    windowManager.swapBuffers();
  }

  // Liberation des ressources
  return EXIT_SUCCESS;
}