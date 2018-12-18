#pragma once
#include "Cell.hpp"

class Coin : public Cell {

private:
	int _point;

public:

    // constructor
    Coin(char type, float width, float height, float posX, float posY, int point);
    Coin();

    //getter
    int getPoint() const;

    //setter
    void setPoint(int point);

    //destructor
    ~Coin();
};