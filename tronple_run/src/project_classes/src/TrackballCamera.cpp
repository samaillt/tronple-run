#include "project_classes/TrackballCamera.hpp"

void TrackballCamera::moveFront(const float &delta){
	m_fDistance += delta;
}

void TrackballCamera::rotateLeft(const float &degrees){
	m_fAngleY += degrees;
}

void TrackballCamera::rotateUp(const float &degrees){
	m_fAngleX += degrees;
}

glm::mat4 TrackballCamera::getViewMatrix() const{
	glm::mat4 ViewMatrix = glm::mat4(1.f);
    ViewMatrix = glm::translate(ViewMatrix, glm::vec3(0.0f, - m_fHeight, - m_fDistance));
    ViewMatrix = glm::rotate(ViewMatrix, glm::radians(m_fAngleX), glm::vec3(1.0f, 0.0f, 0.0f));
    ViewMatrix = glm::rotate(ViewMatrix, glm::radians(m_fAngleY), glm::vec3(0.0f, 1.0f, 0.0f));
    return ViewMatrix;
}

glm::mat4 TrackballCamera::getViewMatrix(Player &player) const{
	glm::mat4 ViewMatrix = glm::mat4(1.f);
    switch ((int)player.getOrientation()){
        case (int)Player::FRONT :
            ViewMatrix = glm::translate(ViewMatrix, glm::vec3(0.0f, m_fHeight, m_fDistance));
            break;
        case (int)Player::LEFT :
            ViewMatrix = glm::translate(ViewMatrix, glm::vec3(m_fDistance, m_fHeight, 0.0f));
            break;
        case (int)Player::BACK :
            ViewMatrix = glm::translate(ViewMatrix, glm::vec3(0.0f, m_fHeight, - m_fDistance));
            break;
        case (int)Player::RIGHT :
            ViewMatrix = glm::translate(ViewMatrix, glm::vec3(-m_fDistance, m_fHeight, 0.0f));
            break;
        default:
            break;
      }
    ViewMatrix = glm::rotate(ViewMatrix, glm::radians(m_fAngleX), glm::vec3(1.0f, 0.0f, 0.0f));
    ViewMatrix = glm::rotate(ViewMatrix, glm::radians(m_fAngleY), glm::vec3(0.0f, 1.0f, 0.0f));
    return ViewMatrix;
}