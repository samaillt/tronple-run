#pragma once
#include "project_classes/Object.hpp"

/// \class Cell
/// \brief Class that defines a Cell
class Cell : public Object {

public:

    //// \brief Constructor
    /// \param type : type to define the cell
	/// \li 'b' : block
	/// \li 'a' : arche
	/// \li 'c' : coin
	/// \li 't' : bonus
	/// \li 'm' : malus
	/// \li 'g' : ground
	/// \li 'h' : hole
	/// \li 'f' : arrival
    /// \param width : width of the requested cell
    /// \param height : height of the requested cell
    /// \param posX : X position of the cell
    /// \param posY : Y position of the cell
    /// \param posZ : Z position of the cell
    Cell(char type, float width, float height, float posX, float posY, float posZ);
    
    /// \brief Default constructor
    Cell();

    /// \brief Destructor
    ~Cell();
};