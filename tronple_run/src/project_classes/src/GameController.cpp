#include <stdio.h>
#include <string>
#include <string.h>
#include <iostream>
#include "project_classes/GameController.hpp"
#include "project_classes/Arrival.hpp"
#include "project_classes/Ground.hpp"
#include "project_classes/Coin.hpp"
#include "project_classes/Hole.hpp"
#include "project_classes/Block.hpp"

GameController::GameController(Level* level){
	_level = level;
}

int GameController::loadLevel(){
	FILE *level_file;

	/* Ouverture du fichier de niveau pour la lecture */
	level_file = fopen(_level->getSourceFile().c_str(), "r");
	
	if (level_file == NULL) {
		std::cout << "Erreur de chargement du fichier" << std::endl;
		return 0;
	}

	/* Traitement du fichier ppm */
	
	char line[64];
	int r, g, b;
	int width, height, color_max;

	/* 
	* Première ligne du fichier 
	* <type>
	*/
	if (fgets(line, sizeof line, level_file) == NULL)
	exit(0);

	if (strcmp(line, "P3\n") != 0) {
		std::cout << "Format du fichier non pris en charge" << std::endl;
		return 0;
	}

	/* 
	* Deuxième ligne du fichier 
	* <width> <height>
	*/
	if (fgets(line, sizeof line, level_file) == NULL)
		return 0;
	if (line[0] == '#') {
		if (fgets(line, sizeof line, level_file) == NULL)
		  	return 0;
	}
	sscanf(line, "%d %d", &width, &height);

	_level->setSizeX(width);
	_level->setSizeX(height);

	/* 
	* Troisième ligne du fichier 
	* <color_max>
	*/
	if (fgets(line, sizeof line, level_file) == NULL)
	exit(0);
	sscanf(line, "%d", &color_max);

	std::vector<Cell*> cells; // Vector of all map elements
	std::vector<Coin*> coins; // Vector of coins

	for (unsigned int i = 0; i < height; ++i) {
		for (unsigned int j = 0; j < width; ++j) {
		  	if (fgets(line, sizeof line, level_file) == NULL)
		    	return 0;
		  	sscanf(line, "%d", &r);
		  	if (fgets(line, sizeof line, level_file) == NULL)
		    	return 0;
		  	sscanf(line, "%d", &g);
		  	if (fgets(line, sizeof line, level_file) == NULL)
		  		return 0;
		  	sscanf(line, "%d", &b);

		  	Cell* cell;
		  
		  	if (r != 255 || g != 255 || b != 255) {
		  	// ------ DEPARTURE & ARRIVAL -----
		    	if (r == 255 && g == 50 && b == 255) {
		    	   	/* Arrival - Magenta */
		      		cell = new Arrival('f',1.f, 1.f, (float)i, (float)j, 0.f);
		    	}
		    	if (r == 100 && g == 50 && b == 200) {
		      		/* Departure - Purple*/
		      		cell = new Ground('g',1.f, 1.f, (float)i, (float)j, 0.f);
		    	}

		  	// ------ GROUND -----
	    		if (r == 100 && g == 0 && b == 0) {
	      			/* Ground - Dark brown */
		      		cell = new Ground('g',1.f, 1.f, (float)i, (float)j, 0.f);
		    	}
		    	if (r == 255 && g == 150 && b == 0) {
		      		/* Ground + coin 1 - Light Yellow */
		      		cell = new Ground('g',1.f, 1.f, (float)i, (float)j, 0.f);
		      		coins.push_back(new Coin('c',1.f, 1.f, (float)i, (float)j, 1.f, 10));
		    	}

		    	if (r == 255 && g == 255 && b == 0) {
		      		/* Ground + coin 2 - Yellow */
		      		cell = new Ground('g',1.f, 1.f, (float)i, (float)j, 0.f);
		      		coins.push_back(new Coin('c',1.f, 1.f, (float)i, (float)j, 2.f, 10));
		    	}

		    	if (r == 150 && g == 50 && b == 0) {
		      		/* TurnLeft - Brown */
		      		cell = new Ground('g',1.f, 1.f, (float)i, (float)j, 0.f);
		    	}

		    	if (r == 150 && g == 150 && b == 0) {
		      		/* TurnRight - Light Brown */
		      		cell = new Ground('g',1.f, 1.f, (float)i, (float)j, 0.f);
		    	}

		  	// ------ HOLE -----
		    	if (r == 100 && g == 100 && b == 100) {
		      		/* Hole - Grey */
		      		cell = new Hole('h',1.f, 1.f, (float)i, (float)j, 0.f);
		    	}
		    	if (r == 0 && g == 0 && b == 0) {
		      		/* Hole + coin 2 - Black */
		      		cell = new Hole('h',1.f, 1.f, (float)i, (float)j, 0.f);
		      		coins.push_back(new Coin('c',1.f, 1.f, (float)i, (float)j, 2.f, 10));
		   		}

		  	// ------ BLOCK -----
		    	if (r == 50 && g == 200 && b == 255) {
		      		/* Block + coin 2 - Light blue */
		      		cell = new Ground('g',1.f, 1.f, (float)i, (float)j, 0.f);
		      		cells.push_back(cell);
		    		cell = new Block('b',1.f, 1.f, (float)i, (float)j, 1.f);
		      		coins.push_back(new Coin('c',1.f, 1.f, (float)i, (float)j, 2.f, 10));
		    	}

		    	if (r == 0 && g == 0 && b == 255) {
		      		/* Block - Blue */
		    		cell = new Ground('g',1.f, 1.f, (float)i, (float)j, 0.f);
		      		cells.push_back(cell);
		    		cell = new Block('b',1.f, 1.f, (float)i, (float)j, 1.f);
		    	}

		  	// ------ ARCHE -----
		    	if (r == 0 && g == 255 && b == 0) {
		      		/* Arche - Green */
		    		cell = new Ground('g',1.f, 1.f, (float)i, (float)j, 0.f);
		      		cells.push_back(cell);
		    		cell = new Block('b',1.f, 1.f, (float)i, (float)j, 2.f);
		    	}

		    	if (r == 50 && g == 150 && b == 0) {
		      		/* Arche + coin 1- Dark green */
		    		cell = new Ground('g',1.f, 1.f, (float)i, (float)j, 0.f);
		      		cells.push_back(cell);
		    		cell = new Block('b',1.f, 1.f, (float)i, (float)j, 2.f);
		    		coins.push_back(new Coin('c',1.f, 1.f, (float)i, (float)j, 1.f, 10));
		    	}
		  	}
		  	cells.push_back(cell);
		}
	}
	fclose (level_file);
	_level->setCells(cells);
	_level->setCoins(coins);
}