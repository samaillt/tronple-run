#pragma once
#include "Cell.hpp"

/// \class Block
/// \brief Class that defines a Block
class Block : public Cell {

public:

    //// \brief Constructor
    /// \param type : type to define the block -> 'b'
    /// \param width : width of the requested block
    /// \param height : height of the requested block
    /// \param posX : X position of the block
    /// \param posY : Y position of the block
    /// \param posZ : Z position of the block
    Block(const char type, const float width, const float height, const float posX, const float posY, const float posZ);
    
    /// \brief Default constructor
    Block();

    /// \brief Destructor
    ~Block();
};