#pragma once
#include "Cell.hpp"

/// \class Hole
/// \brief Class that defines a Hole
class Hole : public Cell {

public:

    //// \brief Constructor
    /// \param type : type to define a hole -> 'g'
    /// \param width : width of the requested hole
    /// \param height : height of the requested hole
    /// \param posX : X position of a hole
    /// \param posY : Y position of a hole
    /// \param posZ : Z position of a hole
    Hole(const char type, const float width, const float height, const float posX, const float posY, const float posZ);
    
    /// \brief Default constructor
    Hole();

    /// \brief Destructor
    ~Hole();
};