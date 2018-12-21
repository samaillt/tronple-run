#pragma once
#include <string>
#include <iostream>
#include <GL/glew.h>

#include <glimac/Program.hpp> 
#include <glimac/FilePath.hpp> 
#include <glimac/glm.hpp> 
#include <glimac/Image.hpp>
#include <glimac/Geometry.hpp>
#include <glimac/SDLWindowManager.hpp>

#include "project_classes/Model.hpp"
#include "project_classes/Program.hpp"
#include <project_classes/TrackballCamera.hpp> 


class RenderController{

private:
    //Program    
    ProgramList* _programList;

    //WindowManager
    SDLWindowManager* _windowManager;

    // Model
    Model _model[2];

    //Matrix
    glm::mat4 _ProjMatrix;
    glm::mat4 _MVMatrix;
    glm::mat4 _NormalMatrix;
    glm::mat4 _GlobalMVMatrix;

public:
    // constructor
    RenderController(SDLWindowManager* windowManager, ProgramList* programList);

    // **** MATRIX ****
    //Getter
    glm::mat4 getProjMatrix() const;
    glm::mat4 getMVMatrix() const;
    glm::mat4 getNormalMatrix() const;
    glm::mat4 getGlobalMVMatrix() const;
    
    //Setter
    void setProjMatrix(glm::mat4 ProjMatrix);
    void setMVMatrix(glm::mat4 MVMatrix);
    void setNormalMatrix(glm::mat4 NormalMatrix);
    void setGlobalMVMatrix(glm::mat4 GlobalMVMatrix);

    // **** PROGRAM **** //
    void useProgram(FS shader);

    // **** MODEL ****
    //Getter
    Model getModel(int i) const;

    //VBO IBO VAO Model
    void VModel(int i);

    //Method
    void bindModelVAO(int i);
    void applyTransformations(FS shader, glm::mat4 MVMatrix);
    void drawModel(int i);
    void debindVAO();

    glm::mat4 useMatrixCoin(int i);
    glm::mat4 useMatrixBike();

    glm::mat4 useMatrixUp();
    glm::mat4 useMatrixDown();

    //destructor
    ~RenderController();
};