#pragma once

#include "project_classes/Object.hpp"

/// \class Player
/// \brief Class that defines the player
class Player : public Object {

public:
    enum Orientation {LEFT = 90, RIGHT = 270, FRONT = 180, BACK = 0};

private:
	std::string _pseudo; /*!< Player pseudo */
	uint _score; /*!< Player score */
	bool _isAlive; /*!< Player, are you alive ? */
    float _speed; /*!< movement speed of the player */
    float _height; /*!< Height of the player */
    float _verticalPos; /*!< Z position Saved */
    float _horizontalPos; /*!<  X or Y position saved */
    Orientation _orientation; /*!<  Orientation of the player */

public:

	//// \brief Constructor
    /// \param type : type to define the player -> p
    /// \param width : width of the requested player
    /// \param height : height of the requested player
    /// \param posX : X position of the player
    /// \param posY : Y position of the player
    /// \param posZ : Z position of the player
    /// \param speed : movement speed of the player
    /// \param pseudo : pseudo of the player
    /// \param score : score of the player
    /// \param isAlive : true or false
    Player(const char type, const float width, const float height, const float posX, const float posY, const float posZ, const float speed, const std::string pseudo, const uint score, const bool isAlive, const float verticalPos, const float horizontalPos, const Orientation orientation = FRONT);
    
    //// \brief Default constructor
    Player();

    //// \brief Get player score
    /// \return Unsigned integer score
    uint getScore() const;

    /// \brief Get if the payer is alive
    /// \return Boolean true or false
    bool isAlive() const;

    /// \brief Get player pseudo
    /// \return String pseudo
    std::string getPseudo() const;

    /// \brief Get player speed
    /// \return String speed
    float getSpeed() const;

    /// \brief Get player Height
    /// \return String Height
    float getHeight() const;

    /// \brief Get player VerticalPos
    /// \return String VerticalPos
    float getVerticalPos() const;

    /// \brief Get player HorizontalPos
    /// \return String HorizontalPos
    float getHorizontalPos() const;

    /// \brief Get player Orientation
    /// \return Orientation
    float getOrientation() const;

    /// \brief Set player score
    /// \param Actual player score
    void setScore(const uint score);

    /// \brief Set player alive or not
    /// \param Boolean true or false
    void setIsAlive(const bool isAlive);

    /// \brief Set player pseudo
    /// \param String player pseudo
    void setPseudo(const std::string &pseudo);

    /// \brief Set player speed
    /// \param String player speed
    void setSpeed(const float &speed);

    /// \brief Set player Height
    /// \param Actual player Height
    void setHeight(const uint height);

    /// \brief Set player VerticalPos
    /// \param Actual player VerticalPos
    void setVerticalPos(const uint verticalPos);

    /// \brief Set player HorizontalPos
    /// \param Actual player HorizontalPos
    void setHorizontalPos(const uint horizontalPos);

    /// \brief Set player Orientation
    /// \param Orientation
    void setOrientation(const Orientation &orientation);

    /// \brief Increment player score
    /// \param Number of points
	void inscrementScore(const uint point);

    /// \brief Increment player X or Y position 
    /// \param Distance
    void moveForward(const float &distance);

    /// \brief Decrement player z position 
    /// \param Distance
    void moveDown(const float &distance);

    /// \brief Increment player Z position
    void jump();

    /// \brief Decrement player height
    void scaleDown();

    /// \brief Restore player Z position
    void resetVerticalPosition();

    /// \brief Decrement player X OR Y position
    void moveRight(); 

    /// \brief Restore player X or Y position
    void resetHorizontalPosition();

    void resetScale();

    /// \brief Increment player X OR Y position
    void moveLeft();
    
    /// \brief Destructor
    ~Player();
};