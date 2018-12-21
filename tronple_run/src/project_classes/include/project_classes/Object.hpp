#pragma once
#include <iostream>

/// \class Object
/// \brief Class that defines an Object
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

    /// \brief Get object type :
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
    char getType() const;

    /// \brief Get object width
    /// \return Float
    float getWidth() const;

    /// \brief Get object height
    /// \return Float
    float getHeight() const;

    /// \brief Get object X position
    /// \return Float
    float getPosX() const;

    /// \brief Get object Y position
    /// \return Float
    float getPosY() const;

    /// \brief Get object Z position
    /// \return Float
    float getPosZ() const;

    /// \brief Set object type
    /// \param Type
    void setType(char type);
    
    /// \brief Set object width
    /// \param Width
    void setWidth(float &width);

    /// \brief Set object height
    /// \param Height
    void setHeight(float &height);

    /// \brief Set object X position
    /// \param X position
    void setPosX(float &posX);
    
    /// \brief Set object Y position
    /// \param X position
    void setPosY(float &posY);

    /// \brief Set object Z position
    /// \param X position
    void setPosZ(float &posZ);

    /// \brief Destructor
    ~Object();
};