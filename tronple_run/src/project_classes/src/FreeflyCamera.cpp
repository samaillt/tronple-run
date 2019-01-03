#include "project_classes/FreeflyCamera.hpp"
#include <math.h>

using namespace glm;

void FreeflyCamera::computeDirectionVectors(){
	//F⃗ =(cos(θ)sin(ϕ), sin(θ), cos(θ)cos(ϕ));
	m_FrontVector = glm::vec3( glm::cos(m_fTheta)*glm::sin(m_fPhi), glm::sin(m_fTheta), glm::cos(m_fTheta)*glm::cos(m_fPhi) );

	//L⃗ =(sin(ϕ+π/2), 0, cos(ϕ+π2))
	m_LeftVector = glm::vec3( glm::sin(m_fPhi + glm::pi<float>()/2), 0, glm::cos(m_fPhi + glm::pi<float>()/2) );

	//U⃗ =F⃗ × L⃗ 
	m_UpVector = glm::cross(m_FrontVector, m_LeftVector);
}

FreeflyCamera::FreeflyCamera()
{
	m_Position = glm::vec3(0,0,0);
	m_fPhi = glm::pi<float>();
	m_fTheta = 0.f;
	computeDirectionVectors();
}

FreeflyCamera::FreeflyCamera(const glm::vec3 position = glm::vec3(0), const float phi = glm::pi<float>(), const float theta = 0.f)
{
	m_Position = position;
	m_fPhi = phi;
	m_fTheta = theta;
	computeDirectionVectors();
}

void FreeflyCamera::moveLeft(const float &t){
	m_Position += t * m_LeftVector;
}

void FreeflyCamera::moveFront(const float &t){
	m_Position += t * m_FrontVector;
}

void FreeflyCamera::rotateLeft(const float &degrees){
	m_fPhi += glm::radians(degrees);
	computeDirectionVectors();}

void FreeflyCamera::rotateUp(const float &degrees){
	m_fTheta += glm::radians(degrees);
	computeDirectionVectors();
}

glm::mat4 FreeflyCamera::getViewMatrix() const {
    return glm::lookAt(m_Position, m_Position + m_FrontVector, m_UpVector);
}

glm::mat4 FreeflyCamera::getViewMatrix(Player &player) const {
    return glm::lookAt(m_Position, m_Position + m_FrontVector, m_UpVector);
}

void FreeflyCamera::setCameraOnPlayer(Player &player)
{
	m_Position = glm::vec3(player.getPosX(), player.getPosZ(), player.getPosY() + 0.5);
	computeDirectionVectors();
}