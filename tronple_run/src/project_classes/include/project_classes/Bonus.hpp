#pragma once
#include "Cell.hpp"

/// \class Bonus
/// \brief Class that defines a Bonus
class Bonus : public Cell {

public:

    //// \brief Constructor
    /// \param type : type to define the bonus -> 't'
    /// \param width : width of the requested bonus
    /// \param height : height of the requested bonus
    /// \param posX : X position of the bonus
    /// \param posY : Y position of the bonus
    /// \param posZ : Z position of the bonus
    Bonus(const char type, const float width, const float height, const float posX, const float posY, const float posZ);
    
    /// \brief Default constructor
    Bonus();

    /// \brief Destructor
    ~Bonus();
};