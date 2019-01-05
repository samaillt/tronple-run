#pragma once

#include <string>
#include <fstream>
#include <vector>
#include "project_classes/Coin.hpp"
#include "project_classes/Cell.hpp"
#include "project_classes/Player.hpp"
#include "project_classes/Arrival.hpp"
#include "project_classes/Ground.hpp"
#include "project_classes/Hole.hpp"
#include "project_classes/Block.hpp"
#include "project_classes/Arch.hpp"


/// \class Level
/// \brief Class that defines a Level
class Level {

private:
    int _sizeX; /*!<  */
    int _sizeY; /*!<  */
    int _sizeZ;  /*!<  */

    Player _mainCharacter; /*!< Main character of the level */
    std::vector<Cell*> _cells; /*!< Vertor of cells */
    std::vector<Coin*> _coins; /*!< Vertor of coins */
    std::vector<Block*> _blocks; /*!< Vector of blocks */
    std::vector<Arch*> _arches; /*!< Vector of arches */
    std::vector<Arrival*> _arrivals; /*!< Vector of arrivals */
    std::vector<Hole*> _holes; /*!< Vector of holes */
    std::vector<Cell*> _leftTurns; /*!< Vector of leftTurns */
    std::vector<Cell*> _rightTurns; /*!< Vector of rightTurns */
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

    /// \brief Get coin
    /// \return Vectors of coin
    std::vector<Coin*> getCoins() const;

    /// \brief Get blocks
    /// \return Vectors of blocks
    std::vector<Block*> getBlocks() const;

    /// \brief Get arches
    /// \return Vectors of arches
    std::vector<Arch*> getArches() const;

    /// \brief Get arrivals
    /// \return Vectors of arrivals
    std::vector<Arrival*> getArrivals() const;

    /// \brief Get holes
    /// \return Vectors of holes
    std::vector<Hole*> getHoles() const;

    /// \brief Get leftTurns
    /// \return Vectors of leftTurns
    std::vector<Cell*> getLeftTurns() const;

    /// \brief Get rightTurns
    /// \return Vectors of rightTurns
    std::vector<Cell*> getRightTurns() const;

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

     /// \brief Set coins
    /// \param Vectors of coins
    void setCoins(std::vector<Coin*> &coins);

    /// \brief Set blocks
    /// \param Vectors of blocks
    void setBlocks(std::vector<Block*> &blocks);

    /// \brief Set arches
    /// \param Vectors of arches
    void setArches(std::vector<Arch*> &arches);

    /// \brief Set arrivals
    /// \param Vectors of arrivals
    void setArrivals(std::vector<Arrival*> &arrivals);

    /// \brief Set holes
    /// \param Vectors of holes
    void setHoles(std::vector<Hole*> &holes);

    /// \brief Set leftTurns
    /// \return Vectors of leftTurns
    void setLeftTurns(std::vector<Cell*> &leftTurns);

    /// \brief Set rightTurns
    /// \return Vectors of rightTurns
    void setRightTurns(std::vector<Cell*> &rightTurns);

    /// \brief Set file source of the level
    /// \param Source string of the file level
    void setSourceFile(std::string &sourceFile);
};