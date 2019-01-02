#pragma once


// \class Camera
/// \brief Class that defines the Camera
class Camera {
public:
    virtual void moveFront(float delta) = 0;
    virtual void rotateLeft(float degrees) = 0;
    virtual void rotateUp(float degrees) = 0;

	virtual glm::mat4 getViewMatrix() const = 0;
	virtual glm::mat4 getViewMatrix(Player &player) const = 0;
};