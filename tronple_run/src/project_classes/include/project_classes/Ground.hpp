#pragma once
#include "Cell.hpp"

/// \class Ground
/// \brief Class that defines the Ground
class Ground : public Cell {

public:

    //// \brief Constructor
    /// \param type : type to define the ground -> 'g'
    /// \param width : width of the requested ground
    /// \param height : height of the requested ground
    /// \param posX : X position of the ground
    /// \param posY : Y position of the ground
    /// \param posZ : Z position of the ground
    Ground(const char type, const float width, const float height, const float posX, const float posY, const float posZ);
    
	/// \brief Default constructor
    Ground();

    /// \brief Destructor
    ~Ground();
};