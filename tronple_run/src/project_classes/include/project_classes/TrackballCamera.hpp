#ifndef __TRACKBALLCAMERA__HPP
#define __TRACKBALLCAMERA__HPP

#pragma once

#include "glimac/glm.hpp"
#include "project_classes/Player.hpp"
#include "project_classes/Camera.hpp"

class TrackballCamera : public Camera{
private:
	float m_fDistance;
	float m_fHeight;
	float m_fAngleX;
	float m_fAngleY;
public:
	TrackballCamera(float distance = 15.f, float height = 5.f, float angleX = 0.f, float angleY = 0.f)
	: m_fDistance(distance), m_fHeight(height), m_fAngleX(angleX), m_fAngleY(angleY) {}
	~TrackballCamera() {}
	void moveFront(float delta);
	void rotateLeft(float degrees);
	void rotateUp(float degrees);
	glm::mat4 getViewMatrix() const;
	glm::mat4 getViewMatrix(Player &player) const;
};

#endif