#include <stdio.h>
#include <string>
#include <string.h>
#include <iostream>
#include "project_classes/Level.hpp"

Level::Level(){}
Level::Level(std::string sourceFile){
	_sourceFile = "../src/assets/levels/"+sourceFile;
}

Level::~Level()
{
    /*for(int i = 0; i < _cells.size(); ++i)
        for (int j = 0; j < _cells[i].size(); ++j)
            delete (_cells[i][j]);*/
}

int Level::getSizeX() const {
	return _sizeX;
}
int Level::getSizeY() const {
	return _sizeY;
}
int Level::getSizeZ() const {
	return _sizeZ;
}
std::string Level::getSourceFile() const {
	return _sourceFile;
}

void Level::setSizeX(const int n) {
	_sizeX = n;
}
void Level::setSizeY(const int n) {
	_sizeY = n;
}
void Level::setSizeZ(const int n) {
	_sizeZ = n;
}
void Level::setSourceFile(std::string &sourceFile){
	_sourceFile = "../src/assets/levels/"+sourceFile;
}