#pragma once

#include "project_classes/Level.hpp"
#include "project_classes/Player.hpp"

class GameController {

private:
    Level* _level;

public:
    GameController(Level* level);

    int loadLevel();

};
