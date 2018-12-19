#include <string>
#include <iostream>
#include "project_classes/Level.hpp"

Level::Level(){}
Level::Level(std::string sourceFile){
	_sourceFile = "../../assets/levels/"+sourceFile;
}

Level::~Level()
{
    /*for(int i = 0; i < _cells.size(); ++i)
        for (int j = 0; j < _cells[i].size(); ++j)
            delete (_cells[i][j]);*/
}

int Level::getSizeX() const {
	return _sizeX;
}
int Level::getSizeY() const {
	return _sizeY;
}
int Level::getSizeZ() const {
	return _sizeZ;
}
std::string Level::getSourceFile() const {
	return _sourceFile;
}

void Level::setSizeX(const int n) {
	_sizeX = n;
}
void Level::setSizeY(const int n) {
	_sizeY = n;
}
void Level::setSizeZ(const int n) {
	_sizeZ = n;
}
void Level::setSourceFile(std::string &sourceFile){
	_sourceFile = "../../assets/levels/"+sourceFile;
}

void Level::loadLevel() {
	// /* Traitement du fichier ppm */
	//   char line[64];
	//   int r, g, b;
	//   int width, height, color_max;

	//   /* 
	//    * Première ligne du fichier 
	//    * <type>
	//   */
	//   if (fgets(line, sizeof line, level) == NULL)
	//     exit(0);

	//   if (strcmp(line, "P3\n") != 0) {
	//     printf("Erreur : Format du fichier non pris en charge.\n");
	//     exit(0);
	//   }

	//   /* 
	//    * Deuxième ligne du fichier 
	//    * <width> <height>
	//   */
	//   if (fgets(line, sizeof line, level) == NULL)
	//     exit(0);
	//   if (line[0] == '#')
	//   {
	//     if (fgets(line, sizeof line, level) == NULL)
	//       exit(0);
	//   }
	//   sscanf(line, "%d %d", &width, &height);

	//   /* 
	//    * Troisième ligne du fichier 
	//    * <color_max>
	//   */
	//   if (fgets(line, sizeof line, level) == NULL)
	//     exit(0);
	//   sscanf(line, "%d", &color_max);

	//   for (unsigned int i = 0; i < height; ++i) {  
	//     for (unsigned int j = 0; j < width; ++j) {
	//       if (fgets(line, sizeof line, level) == NULL)
	//         exit(0);
	//       sscanf(line, "%d", &r);
	//       if (fgets(line, sizeof line, level) == NULL)
	//         exit(0);
	//       sscanf(line, "%d", &g);
	//       if (fgets(line, sizeof line, level) == NULL)
	//           exit(0);
	//       sscanf(line, "%d", &b);
	      
	//       if (r != 255 || g != 255 || b != 255) {
	      
	//       // ------ DEPARTURE & ARRIVAL -----
	//         if (r == 255 && g == 50 && b == 255) {
	//            Arrival - Magenta 
	          
	//         }
	//         if (r == 100 && g == 50 && b == 200) {
	//           /* Departure - Purple*/
	//         }

	//       // ------ GROUND -----
	//         if (r == 100 && g == 0 && b == 0) {
	//           /* Ground - Dark brown */
	//         }
	//         if (r == 255 && g == 150 && b == 0) {
	//           /* Ground + coin 1 - Light Yellow */
	//         }

	//         if (r == 255 && g == 255 && b == 0) {
	//           /* Ground + coin 2 - Yellow */
	//         }

	//         if (r == 150 && g == 50 && b == 0) {
	//           /* TurnLeft - Brown */
	//         }

	//         if (r == 150 && g == 150 && b == 0) {
	//           /* TurnRight - Light Brown */
	//         }

	//       // ------ HOLE -----
	//         if (r == 100 && g == 100 && b == 100) {
	//           /* Hole - Grey */
	//         }
	//         if (r == 0 && g == 0 && b == 0) {
	//           /* Hole + coin 2 - Black */
	//         }

	//       // ------ BLOCK -----
	//         if (r == 50 && g == 200 && b == 255) {
	//           /* Block + coin 2 - Light blue */
	//         }

	//         if (r == 0 && g == 0 && b == 255) {
	//           /* Block - Blue */
	//         }

	//       // ------ ARCHE -----
	//         if (r == 0 && g == 255 && b == 0) {
	//           /* Arche - Green */
	//         }

	//         if (r == 50 && g == 150 && b == 0) {
	//           /* Arche + coin 1- Dark green */
	//         }
	//       }
	//     }
	//   }
	//   fclose (level);
	// }
}