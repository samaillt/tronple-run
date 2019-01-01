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
Player Level::getPlayer() const {
	return _mainCharacter;
}
std::vector<Cell*> Level::getCells() const {
	return _cells;
}
std::vector<Coin*> Level::getCoins() const {
	return _coins;
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
void Level::setPlayer(Player &player) {
	_mainCharacter = player;
}
void Level::setCells(std::vector<Cell*> &cells) {
	_cells = cells;
}
void Level::setCoins(std::vector<Coin*> &coins) {
	_coins = coins;
}
void Level::setSourceFile(std::string &sourceFile) {
	_sourceFile = "../src/assets/levels/"+sourceFile;
}