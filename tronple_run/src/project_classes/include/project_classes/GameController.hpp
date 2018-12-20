#pragma once

#include "project_classes/Level.hpp"
#include "project_classes/Player.hpp"

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
    /// \return A level number
    int loadLevel();

};
