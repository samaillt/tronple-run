#ifndef __FREEFLYCAMERA__HPP
#define __FREEFLYCAMERA__HPP
#pragma once
#include "glimac/glm.hpp"

// \class FreeflyCamera
/// \brief Class that defines the FreeflyCamera
class FreeflyCamera {

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

	//// \brief Move camera on the left/right
    /// \param translation
	void moveLeft(const float &t);

	//// \brief Move camera on the front/back
    /// \param translation
	void moveFront(const float &t);

	//// \brief Rotate camera on the left/right
    /// \param degrees
	void rotateLeft(const float &degrees);

	//// \brief Rotate camera on the up/down
    /// \param degrees
	void rotateUp(const float &degrees);

	//// \brief computes and returns the View matrix associated with the camera
    /// \return Matrix 4D
	glm::mat4 getViewMatrix() const;
};

#endif