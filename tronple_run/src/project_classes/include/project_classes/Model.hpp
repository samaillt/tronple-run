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
    GLuint _vao; /*!< Vertex array object */ 
    GLuint _vbo; /*!< Vertex buffer object */ 
    GLuint _ibo; /*!< Index buffer object */  

    Geometry _geometry; /*!< Geometry */ 
    std::string _obj; /*!< File */

    GLuint _textureID; /*!< Id of model texture */
    Texture *_texture; /*!< model Texture */

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

    /// \brief Get Geometry
    /// \return Geometry
    Geometry getGeometry();

    /// \brief Get vertex array object
    /// \return Unsigned binary integer
    GLuint getVao();

    /// \brief Get index buffer object
    /// \return Unsigned binary integer
    GLuint getIbo();

    /// \brief Get vertex buffer object
    /// \return Unsigned binary integer
    GLuint getVbo();

    /// \brief Get the obj
    /// \return Obj string
    std::string getObj();

    /// \brief Get the texture ID
    /// \return GLuint textID
    GLuint getTextureID();

    /// \brief set vertex buffer object
    void setVbo();

    /// \brief set index buffer object
    void setIbo();

    /// \brief set vertex array object
    void setVao();

    /// \brief Destructor
    ~Model();
};
