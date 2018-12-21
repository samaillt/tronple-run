#pragma once

#include "project_classes/Character.hpp"

/// \class Player
/// \brief Class that defines the player
class Player : public Character {

private:
	std::string _pseudo; /*!< Player pseudo */
	uint _score; /*!< Player score */
	bool _isAlive; /*!< Player, are you alive ? */

public:

	//// \brief Constructor
    /// \param type : type to define the player -> p
    /// \param width : width of the requested player
    /// \param height : height of the requested player
    /// \param posX : X position of the player
    /// \param posY : Y position of the player
    /// \param posZ : Z position of the player
    /// \param initX : initialisation of the X position of the player
    /// \param initY : initialisation of the Y position of the player
    /// \param speed : movement speed of the player
    /// \param pseudo : pseudo of the player
    /// \param score : score of the player
    /// \param isAlive : true or false
    Player(char type, float width, float height, float posX, float posY, float posZ, char initX, float initY, float speed, 
        std::string pseudo, uint score, bool isAlive);
    
    //// \brief Default constructor
    Player();

    //// \brief Get player score
    /// \return Unsigned integer score
    uint getScore() const;

    /// \brief Get if the payer is alive
    /// \return Boolean true or false
    bool getIsAlive() const;

    /// \brief Get player pseudo
    /// \return String pseudo
    std::string getPseudo() const;

    /// \brief Set player score
    /// \param Actual player score
    void setScore(const uint score);

    /// \brief Set player alive or not
    /// \param Boolean true or false
    void setIsAlive(const bool isAlive);

    /// \brief Set player pseudo
    /// \param String player pseudo
    void setPseudo(const std::string &pseudo);

    /// \brief Increment player score
    /// \param Number of points
	void inscrementScore(const uint point);
    
    /// \brief Destructor
    ~Player();
};