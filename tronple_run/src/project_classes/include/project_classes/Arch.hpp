#pragma once
#include "Cell.hpp"

// Doxygen menu
/// \version 0.1
/// \mainpage
/// \image html myImage.jpg
/// \tableofcontents
/// \section instroduction_sec What for?
/// Tron'ple Run created by Noélie Bravo, Hédi Hamadache et Tom Samaille.
/// \section install_bigsec How to install
/// \subsection dependencies_sec Dependecies
/// \li C++
/// \li SDL
/// \li OpenGL 3
/// \li Doxygen
/// \subsection install_sec Install with cmake (Linux)
/// \li cd tronple_run
/// \li mkdir build
/// \li cd build
/// \li cmake ..
/// \li make
/// \li make html
/// \li The documentation is located in tronple_run/build/doc/doc-doxygen/html/index.html


/// \class Arch
/// \brief Class that defines an Arch
class Arch : public Cell {

public:

    /// \brief Constructor
	/// \param type : type to define the arch -> 'a'
	/// \param width : width of the requested arch
	/// \param height : height of the requested arch
	/// \param posX : X position of the arch
	/// \param posY : Y position of the arch
	/// \param posZ : Z position of the arch
    Arch(const char type, const float width, const float height, const float posX, const float posY, const float posZ);

    /// \brief Default constructor
    Arch();

    /// \brief Destructor
    ~Arch();
};