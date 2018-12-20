#pragma once
#include <iostream>
#include <string>
#include <iostream>
#include <GL/glew.h>
#include <glimac/Geometry.hpp>
#include <glimac/FilePath.hpp>

using namespace glimac;

/// \class Model
/// \brief Class that defines a model 3D
class Model{

public:
    /// \brief Constructor
    /// \param obj : string of an obj file
    /// \param applicationPath
    Model(const std::string obj, const FilePath &applicationPath);

    ///\brief Default constructor
    Model();

    //getter
    Geometry getGeometry();
    GLuint getVao();
    GLuint getIbo();
    GLuint getVbo();


    //setter
    void setVbo();
    void setIbo();
    void setVao();

    //destructor
    ~Model();

private:
	GLuint _vao;
	GLuint _vbo;
	GLuint _ibo;

	Geometry _geometry;
	std::string _obj;
};
