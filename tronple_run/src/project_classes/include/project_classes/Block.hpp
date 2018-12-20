#pragma once
#include "Cell.hpp"

/// \class Block
/// \brief Class that defines a block
class Block : public Cell {

public:

    //// \brief Constructor
    /// \param type : type to define the arrival -> 'b'
    /// \param width : width of the requested arrival
    /// \param height : height of the requested arrival
    /// \param posX : X position of the arrival
    /// \param posY : Y position of the arrival
    /// \param posZ : Z position of the arrival
    Block(char type, float width, float height, float posX, float posY, float posZ);
    
    /// \brief Default constructor
    Block();

    /// \brief Destructor
    ~Block();
};