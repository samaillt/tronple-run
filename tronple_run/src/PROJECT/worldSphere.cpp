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
#include <glimac/Sphere.hpp>
#include <project_classes/TrackballCamera.hpp> 
#include <project_classes/Model.hpp>


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
  worldProgram worldProgram(applicationPath);
  
  /* Load world texture */
  std::unique_ptr<Image> imgWorld = loadImage(applicationPath.dirPath() + "../../src/assets/textures/mapGrid.jpg");
  if ( imgWorld == NULL ) std::cout << "World Image Not Loaded" << std::endl;
  

  std::cout << "OpenGL Version : " << glGetString(GL_VERSION) << std::endl;
  std::cout << "GLEW Version : " << glewGetString(GLEW_VERSION) << std::endl;
    
  /*********************************
   * HERE SHOULD COME THE INITIALIZATION CODE
   *********************************/
  /* 1_ Construction des sphères et de la caméra*/
  Sphere sphere(1, 64, 32);
  TrackballCamera camera;
  Model coin("coin", "coin");
  
  /* 2_ Création du VBO et du VAO */
  GLuint vbo, vao;
  glGenBuffers(1, &vbo);
  glGenVertexArrays(1, &vao);
  
  glBindBuffer(GL_ARRAY_BUFFER, vbo);
  glBufferData(GL_ARRAY_BUFFER,
               sphere.getVertexCount() * sizeof(ShapeVertex),
               sphere.getDataPointer(),
               GL_STATIC_DRAW);
  glBindBuffer(GL_ARRAY_BUFFER, 0);
  
  glBindVertexArray(vao);
  const GLuint VERTEX_ATTR_POSITION = 0;
  const GLuint VERTEX_ATTR_NORMAL = 1;
  const GLuint VERTEX_ATTR_COORDS = 2;
  glEnableVertexAttribArray(VERTEX_ATTR_POSITION);
  glEnableVertexAttribArray(VERTEX_ATTR_NORMAL);
  glEnableVertexAttribArray(VERTEX_ATTR_COORDS);  
  glBindBuffer(GL_ARRAY_BUFFER, vbo);
  
  glVertexAttribPointer(
    VERTEX_ATTR_POSITION, // index
    3, // size
    GL_FLOAT, // type
    GL_FALSE, // normalized
    sizeof(ShapeVertex), // stride
    (const GLvoid*) offsetof(ShapeVertex, position) // pointer
  );
  
  glVertexAttribPointer(
    VERTEX_ATTR_NORMAL, // index
    3, // size
    GL_FLOAT, // type
    GL_FALSE, // normalized
    sizeof(ShapeVertex), // stride
    (const GLvoid*) offsetof(ShapeVertex, normal) // pointer
  );
  
  glVertexAttribPointer(
    VERTEX_ATTR_COORDS, // index
    2, // size
    GL_FLOAT, // type
    GL_FALSE, // normalized
    sizeof(ShapeVertex), // stride
    (const GLvoid*) offsetof(ShapeVertex, texCoords) // pointer
  );
  
  glBindBuffer(GL_ARRAY_BUFFER, 0);  
  glBindVertexArray(0);
  
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
              camera.rotateLeft( float(e.motion.xrel) * -0.1f);
            if (e.motion.yrel != 0)
              camera.rotateUp( float(e.motion.yrel) * -0.1f);
            break;
          default:
            break;
        }
    }

    /*********************************
     * HERE SHOULD COME THE RENDERING CODE
     *********************************/
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glBindVertexArray(vao);

    /* Calcul de la caméra */
    globalMVMatrix = camera.getViewMatrix();

    /* 9_ Envoi des matrices au GPU */
    /* DESSIN DU WORLD */
    worldProgram.m_Program.use();
    
    glUniform1i(worldProgram.uTextureWorld, 0);

    MVMatrix = globalMVMatrix*glm::translate(glm::mat4(1), glm::vec3(0, 0, 0)); // Translation
    MVMatrix = glm::rotate(MVMatrix, windowManager.getTime()/32, glm::vec3(0, 1, 0)); // Translation * Rotation
    MVMatrix = glm::scale(MVMatrix, glm::vec3(50, 50, 50)); // Translation * Rotation * Translation * Scale

    glUniformMatrix4fv(worldProgram.uMVPMatrix, 1, GL_FALSE, glm::value_ptr(ProjMatrix*MVMatrix));
    glUniformMatrix4fv(worldProgram.uMVMatrix, 1, GL_FALSE, glm::value_ptr(MVMatrix));
    glUniformMatrix4fv(worldProgram.uNormalMatrix, 1, GL_FALSE, glm::value_ptr(NormalMatrix));

    /* 10_ Dessin du World */
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, textureWorld);
      glDrawArrays(GL_TRIANGLES, 0, sphere.getVertexCount());

    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, 0);

    glBindVertexArray(0);
    // Update the display
    windowManager.swapBuffers();
  }

  // Liberation des ressources
  glDeleteBuffers(1, &vbo);
  glDeleteVertexArrays(1, &vao);
  glDeleteTextures(0, &textureWorld);
  return EXIT_SUCCESS;
}