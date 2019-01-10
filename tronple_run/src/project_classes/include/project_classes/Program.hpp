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

/// \brief Enumeration of fragments chaders
enum FS {COIN, WORLD, TEXTURE, MULTILIGHT};

/// \struct Coin Program
struct CoinProgram{
    Program _program;

    GLint uMVPMatrix;
    GLint uMVMatrix;
    GLint uNormalMatrix;
    GLint uTexture;

    CoinProgram(const FilePath& applicationPath):
        
        _program(loadProgram(applicationPath.dirPath() + "shaders/3D.vs.glsl",
                              applicationPath.dirPath() + "shaders/tex3D.fs.glsl")) {
        uMVPMatrix = glGetUniformLocation(_program.getGLId(), "uMVPMatrix");
        uMVMatrix = glGetUniformLocation(_program.getGLId(), "uMVMatrix");
        uNormalMatrix = glGetUniformLocation(_program.getGLId(), "uNormalMatrix");
        uTexture = glGetUniformLocation(_program.getGLId(), "uTexture");
    }
};

/// \struct World Program
struct WorldProgram{
    Program _program;

    GLint uMVPMatrix;
    GLint uMVMatrix;
    GLint uNormalMatrix;
    GLint uTextureWorld;

    WorldProgram(const FilePath& applicationPath):
        _program(loadProgram(applicationPath.dirPath() + "shaders/3D.vs.glsl",
                              applicationPath.dirPath() + "shaders/world.fs.glsl")) {
        uMVPMatrix = glGetUniformLocation(_program.getGLId(), "uMVPMatrix");
        uMVMatrix = glGetUniformLocation(_program.getGLId(), "uMVMatrix");
        uNormalMatrix = glGetUniformLocation(_program.getGLId(), "uNormalMatrix");
        uTextureWorld = glGetUniformLocation(_program.getGLId(), "uTextureWorld");
    }
};

/// \struct Texture Program
struct TextureProgram {
    glimac::Program _program;

    GLint uMVPMatrix;
    GLint uMVMatrix;
    GLint uNormalMatrix;
    GLint uTexture;
    GLint uTime;

    TextureProgram(const FilePath& applicationPath):
        _program(loadProgram(applicationPath.dirPath() + "shaders/3D.vs.glsl",
                             applicationPath.dirPath() + "shaders/tex3D.fs.glsl"))
    {
        uMVPMatrix = glGetUniformLocation(_program.getGLId(), "uMVPMatrix");
        uMVMatrix = glGetUniformLocation(_program.getGLId(), "uMVMatrix");
        uNormalMatrix = glGetUniformLocation(_program.getGLId(), "uNormalMatrix");
        uTexture = glGetUniformLocation(_program.getGLId(), "uTexture");
        uTime = glGetUniformLocation(_program.getGLId(), "uTime");
    }
};

/// \struct Multilight Program
struct MultiLightProgram{
    glimac::Program _program;

    GLint uMVPMatrix;
    GLint uMVMatrix;
    GLint uNormalMatrix;
    GLint uTexture;

    GLint uLights;
    GLint uNbLights;
    GLint uAmbientLight;

    MultiLightProgram(const FilePath& applicationPath):
        _program(loadProgram(applicationPath.dirPath() + "shaders/3D.vs.glsl",
                              applicationPath.dirPath() + "shaders/multiLight.fs.glsl"))
    {
        uMVPMatrix = glGetUniformLocation(_program.getGLId(), "uMVPMatrix");
        uMVMatrix = glGetUniformLocation(_program.getGLId(), "uMVMatrix");
        uNormalMatrix = glGetUniformLocation(_program.getGLId(), "uNormalMatrix");
        uTexture = glGetUniformLocation(_program.getGLId(), "uTexture");

        uLights = glGetUniformLocation(_program.getGLId(), "uLights");
        uNbLights = glGetUniformLocation(_program.getGLId(), "uNbLights");
        uAmbientLight = glGetUniformLocation(_program.getGLId(), "uAmbientLight");
    }
};

/// \struct Program list
struct ProgramList {
    CoinProgram* coinProgram;
    WorldProgram* worldProgram;
    TextureProgram* textureProgram;
    MultiLightProgram* multiLightProgram;
};
