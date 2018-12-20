#pragma once

#include <string>
#include <fstream>
#include <vector>
#include "project_classes/Coin.hpp"
#include "project_classes/Cell.hpp"
#include "project_classes/Player.hpp"

/// \class Level
/// \brief Class that defines a level
class Level {

private:
    int _sizeX; /*!<  */
    int _sizeY; /*!<  */
    int _sizeZ;  /*!<  */

    Player _mainCharacter; /*!< Main character of the level */
    std::vector<Cell*> _cells; /*!< Vortors of cells */
    std::string _sourceFile; /*!< Source of the file level */

public:
    /// \brief Constructor
    /// \param Source string of the file level
    Level(std::string sourceFile);

    /// \brief Default constructor
    Level();

    /// \brief Destructor
    ~Level();

    /// \brief Get the X size
    /// \return Integer size
    int getSizeX() const;

    /// \brief Get the Y size
    /// \return Integer size
    int getSizeY() const;

    /// \brief Get the Z size
    /// \return Integer size
    int getSizeZ() const;

    /// \brief Get the player
    /// \return Player informations
    Player getPlayer() const;

    /// \brief Get cells
    /// \return Vectors of cells
    std::vector<Cell*> getCells() const;

    /// \brief Get file source of a level
    /// \return Source string of the file level
    std::string getSourceFile() const;

    /// \brief Set the X size
    /// \param Takes an integer n
    void setSizeX(int n);

    /// \brief Set the Y size
    /// \param Takes an integer n
    void setSizeY(int n);

    /// \brief Set the Z size
    /// \param Takes an integer n
    void setSizeZ(int n);

    /// \brief Set a player
    /// \param Player
    void setPlayer(Player &player);

    /// \brief Set cells
    /// \param Vectors of cells
    void setCells(std::vector<Cell*> &cells);

    /// \brief Set file source of the level
    /// \param Source string of the file level
    void setSourceFile(std::string &sourceFile);
};