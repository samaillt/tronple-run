#pragma once
#include <iostream>
#include <string>
#include <iostream>
#include <GL/glew.h>
#include <glimac/Geometry.hpp>
#include <glimac/FilePath.hpp>

using namespace glimac;

class Model{

public:
    // constructor
    Model(const std::string obj, const FilePath &applicationPath);
    Model();

    //getter
    Geometry getGeometry();
    GLuint getVao();


    //setter
    void setVbo(Geometry &geometry);
    void setIbo(Geometry &geometry);
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
