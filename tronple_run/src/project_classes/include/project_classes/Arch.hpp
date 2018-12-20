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
/// \brief Class that defines an arch
class Arch : public Cell {

public:

    /// \brief Constructor
	/// \param type : the type to define the arch
	/// \param width : the width of the requested arch
	/// \param height : the height of the requested arch
	/// \param posX : the position X of the arch
	/// \param posZ : the position Z of the arch
	/// \param posZ : the position Z of the arch
    Arch(char type, float width, float height, float posX, float posY, float posZ);

    /// \brief Default constructor
    Arch();

    /// \brief Destructor
    ~Arch();
};