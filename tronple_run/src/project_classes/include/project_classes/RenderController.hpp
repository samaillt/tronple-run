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

/// \class RenderController
/// \brief Class that defines the RenderController
class RenderController{

private:
    Model _model[2]; /*!<  */ 

    glm::mat4 _ProjMatrix; /*!<  */ 
    glm::mat4 _MVMatrix; /*!<  */ 
    glm::mat4 _NormalMatrix; /*!<  */ 
    glm::mat4 _GlobalMVMatrix; /*!<  */ 
 
    ProgramList* _programList;  /*!< All programs list */ 

public:

    //// \brief Constructor
    /// \param programList : all programs
    RenderController(ProgramList* programList);

    // **** MATRIX ****
    /// \brief Get projection matrix
    /// \return Matrix 4D
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

    glm::mat4 useMatrixCoin();
    glm::mat4 useMatrixBike();

    glm::mat4 useMatrixUp();
    glm::mat4 useMatrixDown();

    //destructor
    ~RenderController();
};