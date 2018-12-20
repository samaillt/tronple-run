#pragma once

#include <string>
#include <fstream>
#include <vector>
#include "project_classes/Coin.hpp"
#include "project_classes/Cell.hpp"
#include "project_classes/Player.hpp"

class Level {

private:
    int _sizeX;
    int _sizeY;
    int _sizeZ; // Normalement toujours 3

    Player _mainCharacter;
    std::vector<Cell*> _cells;
    std::string _sourceFile;

public:
    Level();
    Level(std::string sourceFile);

    ~Level();

    int getSizeX() const;
    int getSizeY() const;
    int getSizeZ() const;
    Player getPlayer() const;
    std::vector<Cell*> getCells() const;
    std::string getSourceFile() const;

    void setSizeX(int n);
    void setSizeY(int n);
    void setSizeZ(int n);
    void setPlayer(Player &player);
    void setCells(std::vector<Cell*> &cells);
    void setSourceFile(std::string &sourceFile);
};