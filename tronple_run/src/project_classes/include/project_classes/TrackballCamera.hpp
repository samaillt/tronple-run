#ifndef __TRACKBALLCAMERA__HPP
#define __TRACKBALLCAMERA__HPP

#pragma once

#include "glimac/glm.hpp"
#include "project_classes/Player.hpp"
#include "project_classes/Camera.hpp"

/// \class TrackballCamera
/// \brief Class that defines the TrackballCamera
class TrackballCamera : public Camera{
private:
	float m_fDistance; /*!< Distance with the character */ 
	float m_fHeight; /*!< tracball camera height */ 
	float m_fAngleX; /*!< tracball camera x angle */ 
	float m_fAngleY; /*!< tracball camera y angle */ 

public:
	/// \brief Constructor
	/// \param distance : distance with the character
	/// \param height : tracball camera height 
	/// \param angleX : tracball camera x angle 
	/// \param angleX : tracball camera y angle 
	TrackballCamera(float distance = 15.f, float height = 5.f, float angleX = 0.f, float angleY = 0.f)
	: m_fDistance(distance), m_fHeight(height), m_fAngleX(angleX), m_fAngleY(angleY) {}
	
	/// \brief Move front
	/// \param delta (float)
	void moveFront(const float &delta);

	/// \brief Rotate left
	/// \param degress (float)
	void rotateLeft(const float &degrees);

	/// \brief Rotate up
	/// \param degress (float)
	void rotateUp(const float &degrees);

	/// \brief Get view matrix
	/// \return matrix4
	glm::mat4 getViewMatrix() const;

	/// \brief Get view matrix
	/// \param player
	/// \return matrix4
	glm::mat4 getViewMatrix(Player &player) const;

	/// \brief Destructor
	~TrackballCamera() {}
};

#endif