#ifndef __FREEFLYCAMERA__HPP
#define __FREEFLYCAMERA__HPP

#pragma once

#include "glimac/glm.hpp"

class FreeflyCamera {
private:
	glm::vec3 m_Position;
	float m_fPhi;
	float m_fTheta;
	glm::vec3 m_FrontVector;
	glm::vec3 m_LeftVector;
	glm::vec3 m_UpVector;

	void computeDirectionVectors();

public:
	FreeflyCamera();
	void moveLeft(const float &t);
	void moveFront(const float &t);
	void rotateLeft(const float &degrees);
	void rotateUp(const float &degrees);
	glm::mat4 getViewMatrix() const;
};

#endif