#pragma once

#include "project_classes/Player.hpp"

// \class Camera
/// \brief Class that defines the Camera
class Camera {
public:
	/// \brief Move front
	/// \param Delta (float)
    virtual void moveFront(const float &delta) = 0;

    /// \brief Rotate left
	/// \param Degrees (float)
    virtual void rotateLeft(const float &degrees) = 0;

    /// \brief Rotate up
	/// \param Degrees (float)
    virtual void rotateUp(const float &degrees) = 0;

    /// \brief Get viex matrix
    /// \return matrix4
	virtual glm::mat4 getViewMatrix() const = 0;

	/// \brief Get view matrix
	/// \param player
	/// \return matrix4
	virtual glm::mat4 getViewMatrix(Player &player) const = 0;
};