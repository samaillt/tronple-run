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
    _cells.clear();
    _coins.clear();
    _blocks.clear();
    _arches.clear();
    _arrivals.clear();
    _leftTurns.clear();
    _rightTurns.clear();
    _sourceFile.clear();

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
std::vector<Block*> Level::getBlocks() const {
	return _blocks;
}
std::vector<Arch*> Level::getArches() const {
	return _arches;
}
std::vector<Arrival*> Level::getArrivals() const {
	return _arrivals;
}
std::vector<Cell*> Level::getLeftTurns() const {
	return _leftTurns;
}
std::vector<Cell*> Level::getRightTurns() const {
	return _rightTurns;
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
void Level::setPlayer(const Player &player) {
	_mainCharacter = player;
}
void Level::setCells(const std::vector<Cell*> &cells) {
	_cells = cells;
}
void Level::setCoins(const std::vector<Coin*> &coins) {
	_coins = coins;
}
void Level::setBlocks(const std::vector<Block*> &blocks) {
	_blocks = blocks;
}
void Level::setArches(const std::vector<Arch*> &arches) {
	_arches = arches;
}
void Level::setArrivals(const std::vector<Arrival*> &arrivals) {
	_arrivals = arrivals;
}
void Level::setLeftTurns(const std::vector<Cell*> &leftTurns) {
	_leftTurns = leftTurns;
}
void Level::setRightTurns(const std::vector<Cell*> &rightTurns) {
	_rightTurns = rightTurns;
}
void Level::setSourceFile(const std::string &sourceFile) {
	_sourceFile = "../src/assets/levels/"+sourceFile;
}