#pragma once
#include "project_classes/Object.hpp"

// \class Coin
/// \brief Class that defines an Enemy
class Enemy : public Object {
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
    Enemy(const char type, const float width, const float height, const float posX, const float posY, const float posZ);
    
    /// \brief Default constructor
    Enemy();
    
    /// \brief Destructor
    ~Enemy();
};