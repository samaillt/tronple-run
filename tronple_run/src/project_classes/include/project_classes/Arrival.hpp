#pragma once
#include "Cell.hpp"

/// \class Arrival
/// \brief Class that defines the arrival
class Arrival : public Cell {

public:

    /// \brief Constructor
    /// \param type : type to define the arrival -> 'f'
    /// \param width : width of the requested arrival
    /// \param height : height of the requested arrival
    /// \param posX : X position of the arrival
    /// \param posY : Y position of the arrival
    /// \param posZ : Z position of the arrival
    Arrival(char type, float width, float height, float posX, float posY, float posZ);
    
    /// \brief Default constructor
    Arrival();

    /// \brief Destructor
    ~Arrival();
};