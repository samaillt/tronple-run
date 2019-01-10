#pragma once
#include <iostream>
#include <string>
#include <iostream>
#include <GL/glew.h>
#include <glimac/Geometry.hpp>
#include <glimac/FilePath.hpp>
#include <project_classes/Texture.hpp>

using namespace glimac;

/// \class Model
/// \brief Class that defines a Model 3D
class Model{

private:
    GLuint _vao; /*!<  */ 
    GLuint _vbo; /*!<  */ 
    GLuint _ibo; /*!<  */ 

    Geometry _geometry; /*!<  */ 
    std::string _obj; /*!<  */

public:
    /// \brief Constructor
    /// \param obj : string of an obj file
    /// \param applicationPath
    Model(const std::string &obj, const FilePath &applicationPath);

    ///\brief Default constructor
    Model();

    /// \brief Model Copy constructor
    /// \param model : Model to copy
    Model(const Model &model);

    Geometry getGeometry();
    GLuint getVao();
    GLuint getIbo();
    GLuint getVbo();

    std::string getObj();

    //setter
    void setVbo();
    void setIbo();
    void setVao();

    //destructor
    ~Model();
};
