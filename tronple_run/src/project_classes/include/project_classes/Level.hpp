#pragma once

#include <string>
#include <fstream>
/* #include "Coin.hpp"
#include "Cell.hpp" */

class Level {

private:
    int _sizeX;
    int _sizeY;
    int _sizeZ; // Normalement toujours 3

    /*std::vector<Coins> _coins;
    std::vector<std::vector<Cell*>> _cells;*/
    std::string _sourceFile;

public:
    Level();
    Level(std::string sourceFile);

    ~Level();

    int getSizeX() const;
    int getSizeY() const;
    int getSizeZ() const;
    std::string getSourceFile() const;

    void setSizeX(int n);
    void setSizeY(int n);
    void setSizeZ(int n);
    void setSourceFile(std::string &sourceFile);

    void init();
};