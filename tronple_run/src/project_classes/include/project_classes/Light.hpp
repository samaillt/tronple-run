#pragma once
#ifndef __LIGHT__HPP
#define __LIGHT__HPP

#include <glimac/common.hpp>
#include <glimac/glm.hpp>
#include <glimac/Program.hpp>
#include <glimac/FilePath.hpp>
#include <project_classes/Program.hpp>

/// \struct Properties
/// \brief List light properties
struct Properties
{
	bool _isPoint;
	glm::vec3 _posOrDir;
	glm::vec3 _Kd;
	glm::vec3 _Ks;
	float _shininess;
	glm::vec3 _lightIntensity;
};

/// \class Light
/// \brief Class that defines lights
class Light {

	private	:
		Properties _properties;
		unsigned int _id;

	public:
		/// \brief Default constructor
		Light();

		/// \brief Constructor
		/// \param id : the light id
		/// \param isPoint : Boolean isPoint
		/// \param posOrDir : position or direction
		/// \param Kd :
		/// \param Ks :
		/// \param shininess : chininess float
		/// \param lightIntensity : light intensity vector
		Light(const unsigned int id,
			  const bool isPoint,
			  const glm::vec3 &posOrDir,
			  const glm::vec3 &Kd,
			  const glm::vec3 &Ks,
			  const float &shininess, 
			  const glm::vec3 &lightIntensity);

		/// \brief Copy constructor
		Light(const Light& light);

		/// \brief Destructor
		~Light();

		void sendLightShader(const MultiLightProgram &multiLightProgram, const std::string &uniformArrayName) const;

		/// \brief get positionOrDirection of light
		const glm::vec3& positionOrDirection() const {
			return _properties._posOrDir;
		}

		/// \brief get id
		const unsigned int& id() const {
			return _id;
		}
		
		/// \brief set positionOrDirection of light
		glm::vec3& positionOrDirection() {
			return _properties._posOrDir;
		}
};

#endif