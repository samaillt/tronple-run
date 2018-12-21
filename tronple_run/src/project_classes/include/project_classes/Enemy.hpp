#pragma once
#include "project_classes/Character.hpp"

// \class Coin
/// \brief Class that defines an Enemy
class Enemy : public Character {

public:
    //// \brief Constructor
    /// \param type : type to define the enemy -> e
    /// \param width : width of the requested enemy
    /// \param height : height of the requested enemy
    /// \param posX : X position of the enemy
    /// \param posY : Y position of the enemy
    /// \param posZ : Z position of the enemy
    /// \param initX : initialisation of the X position of the enemy
    /// \param initY : initialisation of the Y position of the enemy
    /// \param speed : movement speed of the enemy
    Enemy(char type, float width, float height, float posX, float posY, float posZ, char initX, float initY, float speed);
    
    /// \brief Default constructor
    Enemy();
    
    /// \brief Destructor
    ~Enemy();
};

