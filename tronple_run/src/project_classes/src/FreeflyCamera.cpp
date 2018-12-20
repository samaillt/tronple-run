#include "project_classes/FreeflyCamera.hpp"
#include <math.h>

using namespace glm;

void FreeflyCamera::computeDirectionVectors(){
	m_FrontVector = vec3(cos(m_fTheta)*sin(m_fPhi), sin(m_fTheta), cos(m_fTheta)*cos(m_fPhi));
	m_LeftVector = vec3(sin(m_fPhi+M_PI/2), 0, cos(m_fPhi+M_PI/2));
	m_UpVector = m_FrontVector * m_LeftVector;
}

FreeflyCamera::FreeflyCamera()
:m_fPhi(M_PI), m_fTheta(0)
{
	m_Position = vec3(0,0,0);
	computeDirectionVectors();
}

void FreeflyCamera::moveLeft(const float &t){
	m_Position += t * m_LeftVector;
}

void FreeflyCamera::moveFront(const float &t){
	m_Position += t * m_FrontVector;
}

void FreeflyCamera::rotateLeft(const float &degrees){
	m_fPhi += radians(degrees);
    m_FrontVector = vec3(cos(m_fTheta) * sin(m_fPhi), sin(m_fTheta), cos(m_fTheta) * cos(m_fPhi));
    m_LeftVector = vec3(sin(m_fPhi + M_PI / 2), 0, cos(m_fPhi + M_PI / 2));
}

void FreeflyCamera::rotateUp(const float &degrees){
	m_fTheta += radians(degrees);
    m_FrontVector = vec3(cos(m_fTheta) * sin(m_fPhi), sin(m_fTheta), cos(m_fTheta) * cos(m_fPhi));
    m_UpVector = m_FrontVector * m_LeftVector;
}

glm::mat4 FreeflyCamera::getViewMatrix() const {
    return glm::lookAt(m_Position, m_Position + m_FrontVector, m_UpVector);
}