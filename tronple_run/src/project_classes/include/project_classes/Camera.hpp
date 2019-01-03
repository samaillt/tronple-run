#pragma once

#include "project_classes/Player.hpp"

// \class Camera
/// \brief Class that defines the Camera
class Camera {
public:
    virtual void moveFront(const float &delta) = 0;
    virtual void rotateLeft(const float &degrees) = 0;
    virtual void rotateUp(const float &degrees) = 0;

	virtual glm::mat4 getViewMatrix() const = 0;
	virtual glm::mat4 getViewMatrix(Player &player) const = 0;
};