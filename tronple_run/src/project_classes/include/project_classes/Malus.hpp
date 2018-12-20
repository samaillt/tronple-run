#pragma once
#include "Cell.hpp"

/// \class Malus
/// \brief Class that defines a malus
class Malus : public Cell {

public:

    //// \brief Constructor
    /// \param type : type to define a malus -> 'm'
    /// \param width : width of the requested malus
    /// \param height : height of the requested malus
    /// \param posX : X position of a malus
    /// \param posY : Y position of a malus
    /// \param posZ : Z position of a malus
    Malus(char type, float width, float height, float posX, float posY, float posZ);
    
	/// \brief Default constructor
    Malus();

	/// \brief Destructor
    ~Malus();
};