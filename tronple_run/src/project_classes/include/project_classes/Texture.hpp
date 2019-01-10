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

class Texture {

private:
  GLuint _textureID;
  std::string _textureFile;
  std::unique_ptr<glimac::Image> _textureImage;

public:

    Texture();
    Texture(const std::string &textureFile);
    Texture(const Texture& texture);

    ~Texture();

    GLuint getTextureID() const;

    bool loadTexture();
};

#endif