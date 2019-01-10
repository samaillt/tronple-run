#pragma once
#include "Cell.hpp"

/// \class Malus
/// \brief Class that defines a Malus
class Malus : public Cell {

public:

    //// \brief Constructor
    /// \param type : type to define a malus -> 'm'
    /// \param width : width of the requested malus
    /// \param height : height of the requested malus
    /// \param posX : X position of a malus
    /// \param posY : Y position of a malus
    /// \param posZ : Z position of a malus
    Malus(const char type, const float width, const float height, const float posX, const float posY, const float posZ);
    
	/// \brief Default constructor
    Malus();

	/// \brief Destructor
    ~Malus();
};