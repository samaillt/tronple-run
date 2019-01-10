#include "project_classes/Texture.hpp"

using namespace glimac;

Texture::Texture():
  _textureID(0), _textureFile("")
{};

Texture::Texture(const Texture& texture):
  _textureID(0), _textureFile(texture._textureFile) 
{
  loadTexture();
};

Texture::Texture(const std::string &textureFile):
  _textureID(0), 
  _textureFile(textureFile) 
{
  loadTexture();
}

GLuint Texture::getTextureID() const { 
  return _textureID; 
}

bool Texture::loadTexture() {
  _textureImage = loadImage(_textureFile);

  try {
    if (_textureImage == NULL){
      Exception err1(1,2,"Image couldn't be loaded");
      throw err1;
    }
  } catch(const Exception &err){
    std::cerr << "Exception lancée : " << std::endl << "Niveau : " << err.getLevel() << std::endl << "Code : " << err.getCode() << std::endl << err.what() << std::endl;
  }

  glGenTextures(1, &_textureID);
  glBindTexture(GL_TEXTURE_2D, _textureID);
  glTexImage2D(GL_TEXTURE_2D,
            0,
            GL_RGBA,
            _textureImage->getWidth(),
            _textureImage->getHeight(),
            0,
            GL_RGBA,
            GL_FLOAT,
            _textureImage->getPixels());
  glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);

  glBindTexture(GL_TEXTURE_2D, 0);
  return true;
}