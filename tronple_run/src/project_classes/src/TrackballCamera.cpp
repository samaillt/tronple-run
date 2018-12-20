#include "project_classes/TrackballCamera.hpp"

TrackballCamera::TrackballCamera()
:m_fDistance(5.f), m_fAngleX(0.f), m_fAngleY(0.f)
{

}

void TrackballCamera::moveFront(float delta){
	m_fDistance += delta;
}

void TrackballCamera::rotateLeft(float degrees){
	m_fAngleY += degrees;
}

void TrackballCamera::rotateUp(float degrees){
	m_fAngleX += degrees;
}

glm::mat4 TrackballCamera::getViewMatrix() const{
	glm::mat4 ViewMatrix = glm::mat4(1.f);
    ViewMatrix = glm::translate(ViewMatrix, glm::vec3(0.0f, 0.0f, m_fDistance));
    ViewMatrix = glm::rotate(ViewMatrix, glm::radians(m_fAngleX), glm::vec3(1.0f, 0.0f, 0.0f));
    ViewMatrix = glm::rotate(ViewMatrix, glm::radians(m_fAngleY), glm::vec3(0.0f, 1.0f, 0.0f));
    return ViewMatrix;
}