#ifndef __FREEFLYCAMERA__HPP
#define __FREEFLYCAMERA__HPP

#pragma once

#include "glimac/glm.hpp"
#include "project_classes/Camera.hpp"

// \class FreeflyCamera
/// \brief Class that defines the FreeflyCamera
class FreeflyCamera : public Camera {

private:
	glm::vec3 m_Position; /*!< vector 3D : position x, y, z */
	float m_fPhi; /*!< Phi : spherical coordinates */
	float m_fTheta; /*!< Theta : spherical coordinates */
	glm::vec3 m_FrontVector; /*!< vector pointing in front of the camera */
	glm::vec3 m_LeftVector; /*!< vector pointing on the left of the camera */
	glm::vec3 m_UpVector; /*!< vector pointing up of the camera */

	/// \brief computes vectors m_FrontVector, m_LeftVector and m_UpVector from spherical coordinates m_fPhi and m_fTheta
	void computeDirectionVectors();

public:

	/// \brief Default constructor
	FreeflyCamera();

	/// \brief Default constructor
	FreeflyCamera(const glm::vec3 position, const float phi, const float theta);

	//// \brief Lateral movement
    /// \param translation
	void moveLeft(const float &delta);

	//// \brief Move forward / Backward 
    /// \param translation
	void moveFront(const float &delta);

	//// \brief Lateral rotation around view point
    /// \param degrees
	void rotateLeft(const float &degrees);

	//// \brief Vertical rotation around view point
    /// \param degrees
	void rotateUp(const float &degrees);

	//// \brief computes and returns the View matrix associated with the camera
    /// \return Matrix 4D
	glm::mat4 getViewMatrix() const;

	//// \brief computes and returns the View matrix associated with the camera with player set
    /// \return Matrix 4D
	glm::mat4 getViewMatrix(Player &player) const;

	void setCameraOnPlayer(Player &player);
};

#endif