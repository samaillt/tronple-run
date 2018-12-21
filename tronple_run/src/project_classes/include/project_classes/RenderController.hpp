#pragma once
#include <string>
#include <iostream>
#include <GL/glew.h>

#include <glimac/Program.hpp> 
#include <glimac/FilePath.hpp> 
#include <glimac/glm.hpp> 
#include <glimac/Image.hpp>
#include <glimac/Geometry.hpp>
#include "project_classes/Model.hpp"
#include "project_classes/Program.hpp"
#include <project_classes/TrackballCamera.hpp> 


class RenderController{

private:
    // Model
    Model _model[2];

    //Matrix
    glm::mat4 _ProjMatrix;
    glm::mat4 _MVMatrix;
    glm::mat4 _NormalMatrix;

    //Program    
    ProgramList* _programList;

public:

    // constructor
    RenderController(ProgramList* programList);

    // **** MATRIX ****
    //Getter
    glm::mat4 getProjMatrix() const;
    glm::mat4 getMVMatrix() const;
    glm::mat4 getNormalMatrix() const;

    //Setter
    void setProjMatrix(glm::mat4 ProjMatrix);
    void setMVMatrix(glm::mat4 MVMatrix);
    void setNormalMatrix(glm::mat4 NormalMatrix);

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

    //destructor
    ~RenderController();
};