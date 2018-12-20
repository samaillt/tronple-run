#pragma once
#include "Cell.hpp"

/// \class Coin
/// \brief Class that defines a coin
class Coin : public Cell {

private:
	int _value; /*!< integer value of the coin */

public:

    //// \brief Constructor
    /// \param type : type to define the coin -> 'c'
    /// \param width : width of the requested coin
    /// \param height : height of the requested coin
    /// \param posX : X position of the coin
    /// \param posY : Y position of the coin
    /// \param posZ : Z position of the coin
    /// \param value : value of the coin
    Coin(char type, float width, float height, float posX, float posY, float posZ, int value);
    
    /// \brief Default constructor
    Coin();

    /// \brief get the value of the coin
    /// \return integer value of the coin
    int getValue() const;

    /// \brief set the value of the coin
    /// \param
    void setValue(int value);

    //destructor
    ~Coin();
};