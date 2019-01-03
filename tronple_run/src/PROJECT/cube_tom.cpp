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
#include <project_classes/TrackballCamera.hpp> 
#include <glimac/Cube.hpp>


using namespace glimac;

struct worldProgram{
    Program m_Program;

    GLint uMVPMatrix;
    GLint uMVMatrix;
    GLint uNormalMatrix;
    GLint uTextureWorld;

    worldProgram(const FilePath& applicationPath):
        m_Program(loadProgram(applicationPath.dirPath() + "shaders/3D.vs.glsl",
                              applicationPath.dirPath() + "shaders/world.fs.glsl")) {
        uMVPMatrix = glGetUniformLocation(m_Program.getGLId(), "uMVPMatrix");
        uMVMatrix = glGetUniformLocation(m_Program.getGLId(), "uMVMatrix");
        uNormalMatrix = glGetUniformLocation(m_Program.getGLId(), "uNormalMatrix");
        uTextureWorld = glGetUniformLocation(m_Program.getGLId(), "uTextureWorld");
    }
};

struct cubeProgram{
    Program m_Program;

    GLint uMVPMatrix;
    GLint uMVMatrix;
    GLint uNormalMatrix;
    GLint uTextureWorld;

    cubeProgram(const FilePath& applicationPath):
        m_Program(loadProgram(applicationPath.dirPath() + "shaders/3D.vs.glsl",
                              applicationPath.dirPath() + "shaders/normals.fs.glsl")) {
        uMVPMatrix = glGetUniformLocation(m_Program.getGLId(), "uMVPMatrix");
        uMVMatrix = glGetUniformLocation(m_Program.getGLId(), "uMVMatrix");
        uNormalMatrix = glGetUniformLocation(m_Program.getGLId(), "uNormalMatrix");
    }
};

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
  
  FilePath applicationPath(argv[0]);
  cubeProgram cubeProgram(applicationPath);
  
  /* Load world texture */
  std::unique_ptr<Image> imgWorld = loadImage(applicationPath.dirPath() + "../../src/assets/textures/mapGrid.jpg");
  if ( imgWorld == NULL ) std::cout << "World Image Not Loaded" << std::endl;
  

  std::cout << "OpenGL Version : " << glGetString(GL_VERSION) << std::endl;
  std::cout << "GLEW Version : " << glewGetString(GLEW_VERSION) << std::endl;
    
  /*********************************
   * HERE SHOULD COME THE INITIALIZATION CODE
   *********************************/
  /* 1_ Construction de la sphère et de la caméra*/
  TrackballCamera camera;
  camera.moveFront(-100.f);
  Cube cube(1,1,1);
  
  cube.setVbo();

  cube.setIbo();
  
  cube.setVao();
  
  /* 4_ Activation de la detection de la profondeur */
  glEnable(GL_DEPTH_TEST);
  
  /* 5-8_ Création des matrices de Projection, MV et Normales */
  glm::mat4 ProjMatrix, MVMatrix, NormalMatrix, globalMVMatrix;
  ProjMatrix = glm::perspective(glm::radians(70.0f), // Angle vertical de vue
                   (float) (WINDOW_WIDTH / WINDOW_HEIGTH), // Ratio de la fenetre
                   0.1f, // Near
                   100.f); // Far
  
  // Chargement des textures
  GLuint textureWorld;
  glGenTextures(1, &textureWorld); 
  
  glBindTexture(GL_TEXTURE_2D, textureWorld);
  glTexImage2D(GL_TEXTURE_2D, // Target
               0, // Mipmap level
               GL_RGBA, // Internal Format
               imgWorld->getWidth(), // Width
               imgWorld->getHeight(), // Height
               0, // Border
               GL_RGBA, // Format
               GL_FLOAT, // Type
               imgWorld->getPixels() // Value
              );
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
  glBindTexture(GL_TEXTURE_2D, 0);
  
  // End Chargement des textures
  // bind vao

  // Application loop:
  bool done = false;
  //float time = 0.0f;
  while(!done) {
    // Event loop:
    SDL_Event e;
    while(windowManager.pollEvent(e)) {
      if(e.type == SDL_QUIT) {
        done = true; // Leave the loop after this iteration
      }
        /* Traitement d'evenements : */
        switch(e.type) {
          /* Touche clavier */
          case SDL_KEYDOWN:
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
              camera.rotateLeft( float(e.motion.xrel) * -0.2f);
            if (e.motion.yrel != 0)
              camera.rotateUp( float(e.motion.yrel) * -0.2f);
            break;
          default:
            break;
        }
    }

    /*********************************
     * HERE SHOULD COME THE RENDERING CODE
     *********************************/
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glBindVertexArray(cube.getVao());

    /* Calcul de la caméra */
    globalMVMatrix = camera.getViewMatrix();

    /* 9_ Envoi des matrices au GPU */
    /* DESSIN DU WORLD */
    cubeProgram.m_Program.use();
    
    glUniform1i(cubeProgram.uTextureWorld, 0);

    MVMatrix = globalMVMatrix*glm::translate(glm::mat4(1), glm::vec3(0, 0, 0)); // Translation
    MVMatrix = glm::scale(MVMatrix, glm::vec3(10, 10, 10)); // Translation * Rotation * Translation * Scale

    glUniformMatrix4fv(cubeProgram.uMVPMatrix, 1, GL_FALSE, glm::value_ptr(ProjMatrix*MVMatrix));
    glUniformMatrix4fv(cubeProgram.uMVMatrix, 1, GL_FALSE, glm::value_ptr(MVMatrix));
    glUniformMatrix4fv(cubeProgram.uNormalMatrix, 1, GL_FALSE, glm::value_ptr(NormalMatrix));

    /* 10_ Dessin du World */
    // Erreur de seg au drawArray
    glDrawElements(GL_TRIANGLES, cube.getIndexCount(), GL_UNSIGNED_INT, 0);

    glBindVertexArray(0);
    // Update the display
    windowManager.swapBuffers();
  }

  // Liberation des ressources
  // glDeleteBuffers(1, &vbo);
  // glDeleteVertexArrays(1, &vao);
  glDeleteTextures(0, &textureWorld);
  return EXIT_SUCCESS;
}