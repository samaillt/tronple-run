#pragma once
#ifndef __TEXTURE__HPP
#define __TEXTURE__HPP
#include <iostream>
#include <string>
#include <iostream>
#include <GL/glew.h>
#include "glimac/glm.hpp"
#include "glimac/Image.hpp"
#include <glimac/FilePath.hpp>
#include "project_classes/Exception.hpp"


/// \class Texture
/// \brief Class that defines a Texture
class Texture {

private:
  GLuint _textureID; /*!< Texture id */ 
  std::string _textureFile; /*!< Texture file */ 
  std::unique_ptr<glimac::Image> _textureImage; /*!< Texture image */ 

public:
	/// \brief Default contructor
    Texture();

    /// \brief Constructor
    /// \param textureFile : File of the texture
    Texture(const std::string &textureFile);

    /// \brief Constructor
    /// \param texture
    Texture(const Texture& texture);

    /// \brief Get the texture id
    /// \return Unsigned binary integer
    GLuint getTextureID() const;

    /// \brief Load texture
    /// \return boolean
    bool loadTexture();

    /// \brief Destructor
    ~Texture();
};

#endif