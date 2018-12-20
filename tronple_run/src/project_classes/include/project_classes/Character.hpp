#pragma once
#include <iostream>
#include "project_classes/Object.hpp"

/// \class Character
/// \brief Class that defines a character
class Character : public Object {

private:
    float _initX; /*!< initialisation of the X position of the character */
    float _initY; /*!< initialisation of the Y position of the character */
    float _speed; /*!< movement speed of the character */

public:

    //// \brief Constructor
    /// \param type : type to define the character
    /// \li 'p' : player
    /// \li 'e' : enemy
    /// \param width : width of the requested character
    /// \param height : height of the requested character
    /// \param posX : X position of the character
    /// \param posY : Y position of the character
    /// \param posZ : Z position of the character
    /// \param initX : initialisation of the X position of the character
    /// \param initY : initialisation of the Y position of the character
    /// \param speed : movement speed of the character
    Character(char type, float width, float height, float posX, float posY, float posZ, char initX, float initY, float speed);
    
    /// \brief Default constructor
    Character();

    /// \brief get speed
    /// \return float speed value
    float getSpeed() const;

    /// \brief get initialisation of the X position
    /// \return float initialisated X position value
    float getInitX() const;

    /// \brief get initialisation of the Y position
    /// \return float initialisated Y position value
    float getInitY() const;

    /// \brief set speed
    void setSpeed(float &speed);

    /// \brief set initialisation of the X position
    /// \param initX : takes the initialisation of the X position
    void setInitX(float &initX);

    /// \brief set initialisation of the Y position
    /// \param initX : takes the initialisation of the X position
    void setInitY(float &initY);

    /// \brief moves character on the right
    void moveRight();
    /// \brief moves character on the left
    void moveLeft();
    /// \brief moves character up
    void moveUp();
    /// \brief moves character down
    void moveDown();

    /// \brief Destructor
    ~Character();
};