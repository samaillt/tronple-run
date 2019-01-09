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
enum FS {COIN};

struct CoinProgram{
    Program m_Program;

    GLint uMVPMatrix;
    GLint uMVMatrix;
    GLint uNormalMatrix;

    CoinProgram(const FilePath& applicationPath):
        m_Program(loadProgram(applicationPath.dirPath() + "shaders/3D.vs.glsl",
                              applicationPath.dirPath() + "shaders/normals.fs.glsl")) {
        uMVPMatrix = glGetUniformLocation(m_Program.getGLId(), "uMVPMatrix");
        uMVMatrix = glGetUniformLocation(m_Program.getGLId(), "uMVMatrix");
        uNormalMatrix = glGetUniformLocation(m_Program.getGLId(), "uNormalMatrix");
    }
};


struct WorldProgram{
    Program m_Program;

    GLint uMVPMatrix;
    GLint uMVMatrix;
    GLint uNormalMatrix;
    GLint uTextureWorld;

    WorldProgram(const FilePath& applicationPath):
        m_Program(loadProgram(applicationPath.dirPath() + "shaders/3D.vs.glsl",
                              applicationPath.dirPath() + "shaders/world.fs.glsl")) {
        uMVPMatrix = glGetUniformLocation(m_Program.getGLId(), "uMVPMatrix");
        uMVMatrix = glGetUniformLocation(m_Program.getGLId(), "uMVMatrix");
        uNormalMatrix = glGetUniformLocation(m_Program.getGLId(), "uNormalMatrix");
        uTextureWorld = glGetUniformLocation(m_Program.getGLId(), "uTextureWorld");
    }
};

struct TextureProgram {
    glimac::Program _program;

    GLint uMVPMatrix;
    GLint uMVMatrix;
    GLint uNormalMatrix;
    GLint uTexture;
    GLint uTime;

    TextureProgram(const FilePath& applicationPath)
        :_program(loadProgram(applicationPath.dirPath() + "shaders/3D.vs.glsl",
                             applicationPath.dirPath() + "shaders/tex3D.fs.glsl"))
    {
        std::cout << "Loading texture program" << std::endl;
        uMVPMatrix = glGetUniformLocation(_program.getGLId(), "uMVPMatrix");
        uMVMatrix = glGetUniformLocation(_program.getGLId(), "uMVMatrix");
        uNormalMatrix = glGetUniformLocation(_program.getGLId(), "uNormalMatrix");
        uTexture = glGetUniformLocation(_program.getGLId(), "uTexture");
        uTime = glGetUniformLocation(_program.getGLId(), "uTime");
    }
};

struct MultiLightProgram{
    glimac::Program _program;

    GLint uMVPMatrix;
    GLint uMVMatrix;
    GLint uNormalMatrix;
    GLint uTexture;

    GLint uLights;
    GLint uNbLights;
    GLint uAmbientLight;

    MultiLightProgram(const FilePath& applicationPath)
        :_program(loadProgram(applicationPath.dirPath() + "shaders/3D.vs.glsl",
                              applicationPath.dirPath() + "shaders/multiLight.fs.glsl"))
    {
        std::cout << "Loading MultiLight program" << std::endl;
        uMVPMatrix = glGetUniformLocation(_program.getGLId(), "uMVPMatrix");
        uMVMatrix = glGetUniformLocation(_program.getGLId(), "uMVMatrix");
        uNormalMatrix = glGetUniformLocation(_program.getGLId(), "uNormalMatrix");
        uTexture = glGetUniformLocation(_program.getGLId(), "uTexture");

        uLights = glGetUniformLocation(_program.getGLId(), "uLights");
        uNbLights = glGetUniformLocation(_program.getGLId(), "uNbLights");
        uAmbientLight = glGetUniformLocation(_program.getGLId(), "uAmbientLight");
    }
};

struct ProgramList {
    CoinProgram* coinProgram;
    WorldProgram* worldProgram;
    TextureProgram* textureProgram;
    MultiLightProgram* multiLightProgram;
};
