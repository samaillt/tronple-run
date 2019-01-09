#include "project_classes/Texture.hpp"

Texture::Texture()
: _textId(0), _imgFile("")
{

}

Texture::Texture(std::string imgFile)
: _textId(0), _imgFile(imgFile)
{

}

GLuint Texture::getID() const {
  return _textId;
}

void Texture::setImgFile(const std::string &imgFile) {
  _imgFile = imgFile;
}

bool Texture::loadTexture() {
  _imgTexture = glimac::loadImage(_imgFile);

  if(_imgTexture == 0)
    {
        std::cout << "Error : cannot load texture image" << std::endl;
        return false;
    }

  glGenTextures(1, &_textId);
  glBindTexture(GL_TEXTURE_2D, _textId);

  glTexImage2D(GL_TEXTURE_2D,
                    0,
                    GL_RGBA,
                    _imgTexture->getWidth(),
                    _imgTexture->getHeight(),
                    0,
                    GL_RGBA,
                    GL_FLOAT,
                    _imgTexture->getPixels()
                    );
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

  glBindTexture(GL_TEXTURE_2D, 0);
  return true;
}