#pragma once
#ifndef __TEXTURE__HPP
#define __TEXTURE__HPP
#include <iostream>
#include <GL/glew.h>
#include "glimac/glm.hpp"
#include "glimac/Image.hpp"

class Texture {

private:
  GLuint _textId;
  std::string _imgFile;
  std::unique_ptr<glimac::Image> _imgTexture;

public:

    Texture();
    Texture(std::string ImgFile);

    GLuint getID() const;

    void setImgFile(const std::string &ImgFile);

    bool loadTexture();
};

#endif