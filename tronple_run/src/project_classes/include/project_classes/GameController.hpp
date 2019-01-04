#pragma once

#include "project_classes/Level.hpp"
#include "project_classes/Player.hpp"
#include "project_classes/Object.hpp"

/// \class GameController
/// \brief Class that defines the GameController
class GameController {

private:
    Level* _level; /*!< game level */

public:
	/// \brief Constructor
    /// \param Game level
    GameController(Level* level);

    /// \brief Load a level
    /// \return Level number
    int loadLevel();

    /// \brief Check collision with AABB method between the player and a cell
    /// \return true if objects collided or false if not
    /// \param Player and Cell
    bool checkAABBCollision(Player &a, Object &b);

};
