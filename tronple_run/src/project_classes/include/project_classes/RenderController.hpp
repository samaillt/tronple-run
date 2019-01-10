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

#include <project_classes/Light.hpp> 

/// \class RenderController
/// \brief Class that defines the RenderController
class RenderController{

private:  
    ProgramList* _programList; /*!< Program */ 

    SDLWindowManager* _windowManager; /*!< WindowManager */ 

    Model _model[3]; /*!< Model */ 

    glm::mat4 _ProjMatrix; /*!< ProjMatrix */ 
    glm::mat4 _MVMatrix; /*!< MVMatrix */ 
    glm::mat4 _NormalMatrix; /*!< NormalMatrix */ 
    glm::mat4 _GlobalMVMatrix; /*!< GlobalMVMatrix */ 

    std::vector<Light> _lights; /*!< Lights */ 

    unsigned int _lightsCount; /*!< Lights counter */ 

public:
    /// \brief Constructor
    /// \param windowManager
    /// \param programList
    RenderController(SDLWindowManager* windowManager, ProgramList* programList);

    // **** MATRIX ****
    
    /// \brief Get projMatrix
    /// \return matrix4
    glm::mat4 getProjMatrix() const;

    /// \brief Get MVMatrix
    /// \return matrix4
    glm::mat4 getMVMatrix() const;

    /// \brief Get NormalMatrix
    /// \return matrix4
    glm::mat4 getNormalMatrix() const;

    /// \brief Get GlobalMVMatrix
    /// \return matrix4
    glm::mat4 getGlobalMVMatrix() const;
    
    /// \brief Set projMatrix
    /// \param matrix4 projMatrix
    void setProjMatrix(const glm::mat4 ProjMatrix);

    /// \brief Set MVMatrix
    /// \param matrix4 MVMatrix
    void setMVMatrix(const glm::mat4 MVMatrix);

    /// \brief Set NormalMatrix
    /// \param matrix4 NormalMatrix
    void setNormalMatrix(const glm::mat4 NormalMatrix);

    /// \brief Set GlobalMVMatrix
    /// \param matrix4 GlobalMVMatrix
    void setGlobalMVMatrix(const glm::mat4 GlobalMVMatrix);

    /// \brief Use program
    /// \param Fragment shader
    void useProgram(const FS shader);

    // **** MODEL ****

    /// \brief Get Model
    /// \param model number (int)
    /// \return model
    Model getModel(int i) const;

    /// \brief VBO IBO VAO Model
    void VModel(int i);

    /// \brief Bind Model Vertex array object
    /// \param model number (int)
    void bindModelVAO(int i);

    /// \brief Apply transformations
    /// \param Fragment shader and matrix4
    void applyTransformations(FS shader, glm::mat4 MVMatrix);

    /// \brief Draw model
    /// \param model number (int)
    void drawModel(int i);

    /// \brief Debind Model Vertex array object
    void debindVAO();

    /// \brief Use coin matrix
    /// \param float x, y, z
    /// \return matrix4
    glm::mat4 useMatrixCoin(float x, float y, float z);

    /// \brief Use bike matrix
    /// \param float x, y, z, orientation
    /// \return matrix4
    glm::mat4 useMatrixBike(float x, float y, float z, float orientation);

    /// \brief Use cell matrix
    /// \param float x, y, z
    /// \return matrix4
    glm::mat4 useMatrixCell(float x, float y, float z);

    /// \brief Use skybox matrix
    /// \return matrix4
    glm::mat4 useMatrixSkybox();

    /// \brief Activate and bind coin texture
    void enableCoinTexture();

    /// \brief Activate and bind cube texture
    void enableCubeTexture();

    /// \brief Activate and bind bike texture
    void enableBikeTexture();
    
    /// \brief Dectivate and debind texture
    void disableTexture();

    /// \brief Destructor
    ~RenderController();
};