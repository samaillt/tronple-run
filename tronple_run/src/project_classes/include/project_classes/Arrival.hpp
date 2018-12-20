#pragma once
#include "Cell.hpp"

class Arrival : public Cell {

private:
	bool _victory;

public:

    // constructor
    Arrival(char type, float width, float height, float posX, float posY, float posZ);
    Arrival();

    //getter
    bool getVictory() const;

    //setter
    void setVictory(bool vitory);

    //destructor
    ~Arrival();
};