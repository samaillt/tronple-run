#pragma once
#include <iostream>

/// \class Object
/// \brief Class that defines an object
class Object {

private:
    char _type; /*!<  type that defines the object
    /// \li 'p' : player
    /// \li 'e' : enemy
    /// \li 'b' : block
    /// \li 'a' : arche
    /// \li 'c' : coin
    /// \li 't' : bonus
    /// \li 'm' : malus
    /// \li 'g' : ground
    /// \li 'h' : hole
    /// \li 'f' : arrival*/ 
    float _width; /*!< object width */ 
    float _height; /*!< object height */ 
    float _posX; /*!< object X position */ 
    float _posY; /*!< object Y position */ 
    float _posZ; /*!< object Z position */ 

public:

    //// \brief Constructor
    /// \param type : type to define the object
    /// \li 'p' : player
    /// \li 'e' : enemy
    /// \li 'b' : block
    /// \li 'a' : arche
    /// \li 'c' : coin
    /// \li 't' : bonus
    /// \li 'm' : malus
    /// \li 'g' : ground
    /// \li 'h' : hole
    /// \li 'f' : arrival
    /// \param width : width of the requested object
    /// \param height : height of the requested object
    /// \param posX : X position of the object
    /// \param posY : Y position of the object
    /// \param posZ : Z position of the object
    Object(char type, float width, float height, float posX, float posY, float posZ);
    
    /// \brief Default constructor
    Object();

    // getter
    char getType() const;
    float getWidth() const;
    float getHeight() const;
    float getPosX() const;
    float getPosY() const;
    float getPosZ() const;

    // setter
    void setType(char type);
    void setWidth(float &width);
    void setHeight(float &height);
    void setPosX(float &posX);
    void setPosY(float &posY);
    void setPosZ(float &posZ);

    // collision
    bool collision(Object*);

    //destructor
    ~Object();
};