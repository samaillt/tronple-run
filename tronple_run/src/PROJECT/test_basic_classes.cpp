#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <project_classes/Object.hpp>
#include <project_classes/Character.hpp>
#include <project_classes/Player.hpp>
#include <project_classes/Enemy.hpp>
#include <project_classes/Cell.hpp>
#include <project_classes/Coin.hpp>
#include <project_classes/Ground.hpp>
#include <project_classes/Hole.hpp>
#include <project_classes/Block.hpp>
#include <project_classes/Arch.hpp>
#include <project_classes/Arrival.hpp>



void testObject(){
	// Constructeur
	Object mur('m',1.f, 1.f, 2.f, 3.f, 4.f);
	float f1 = 100.f;

	// Get
	std::cout << mur.getType() << std::endl; 
	std::cout << mur.getWidth() << std::endl; 
	std::cout << mur.getHeight() << std::endl; 
	std::cout << mur.getPosX() << std::endl; 
	std::cout << mur.getPosY() << std::endl; 

	//Set
	mur.setType('a');
	mur.setWidth(f1); 
	mur.setHeight(f1); 
	mur.setPosX(f1);
	mur.setPosY(f1);

	//Get
	std::cout << mur.getType() << std::endl; 
	std::cout << mur.getWidth() << std::endl; 
	std::cout << mur.getHeight() << std::endl; 
	std::cout << mur.getPosX() << std::endl; 
	std::cout << mur.getPosY() << std::endl; 

	//Collision (à faire)
}

void testCharacter(){
	// Constructeur
	Character character('p',1.f, 1.f, 2.f, 3.f, 4.f, 0.f, 0.f, 3.f);
	float f1 = 100.f;

	// Get
	std::cout << "------ 1 -----" << std::endl;
	std::cout << "Type : " << character.getType() << std::endl; 
	std::cout << "Width : " << character.getWidth() << std::endl; 
	std::cout << "Height : " << character.getHeight() << std::endl; 
	std::cout << "PosX : " << character.getPosX() << std::endl; 
	std::cout << "PosY : " << character.getPosY() << std::endl; 
	std::cout << "Speed : " << character.getSpeed() << std::endl; 
	std::cout << "InitX : " << character.getInitX() << std::endl; 
	std::cout << "InitY : " << character.getInitY() << std::endl; 

	//Set
	character.setType('N');
	character.setSpeed(f1);
	character.setInitX(f1); 
	character.setInitY(f1);

	//Get
	std::cout << "------ 2 -----" << std::endl;
	std::cout << "Type : " << character.getType() << std::endl; 
	std::cout << "Width : " << character.getWidth() << std::endl; 
	std::cout << "Height : " << character.getHeight() << std::endl; 
	std::cout << "PosX : " << character.getPosX() << std::endl; 
	std::cout << "PosY : " << character.getPosY() << std::endl; 
	std::cout << "Speed : " << character.getSpeed() << std::endl; 
	std::cout << "InitX : " << character.getInitX() << std::endl; 
	std::cout << "InitY : " << character.getInitY() << std::endl; 
}

void testPlayer(){
	// Constructeur
	Player player('p',1.f, 1.f, 2.f, 3.f, 4.f, 0.f, 0.f, 3.f, "Noelie", 3020, true);
	float f1 = 100.f;

	// Get
	std::cout << "------ 1 -----" << std::endl;
	std::cout << "Type : " << player.getType() << std::endl; 
	std::cout << "Width : " << player.getWidth() << std::endl; 
	std::cout << "Height : " << player.getHeight() << std::endl; 
	std::cout << "PosX : " << player.getPosX() << std::endl; 
	std::cout << "PosY : " << player.getPosY() << std::endl; 
	std::cout << "Speed : " << player.getSpeed() << std::endl; 
	std::cout << "InitX : " << player.getInitX() << std::endl; 
	std::cout << "InitY : " << player.getInitY() << std::endl; 
	std::cout << "Pseudo : " << player.getPseudo() << std::endl; 
	std::cout << "Score : " << player.getScore() << std::endl; 
	std::cout << "Alive : " << player.getIsAlive() << std::endl;

	//Set
	player.setType('N');
	player.setSpeed(f1);
	player.setInitX(f1); 
	player.setInitY(f1);
	player.setPseudo("Hedi");
	player.setScore(39089);
	player.setIsAlive(false);



	//Get
	std::cout << "------ 2 -----" << std::endl;
	std::cout << "Type : " << player.getType() << std::endl; 
	std::cout << "Width : " << player.getWidth() << std::endl; 
	std::cout << "Height : " << player.getHeight() << std::endl; 
	std::cout << "PosX : " << player.getPosX() << std::endl; 
	std::cout << "PosY : " << player.getPosY() << std::endl; 
	std::cout << "Speed : " << player.getSpeed() << std::endl; 
	std::cout << "InitX : " << player.getInitX() << std::endl; 
	std::cout << "InitY : " << player.getInitY() << std::endl; 
	std::cout << "Pseudo : " << player.getPseudo() << std::endl; 
	std::cout << "Score : " << player.getScore() << std::endl; 
	std::cout << "Alive : " << player.getIsAlive() << std::endl;

	player.inscrementScore(1);

	std::cout << "Score (implémenté) : " << player.getScore() << std::endl; 
}

void testEnemy(){
	// Constructeur
	Enemy player('p',1.f, 1.f, 2.f, 3.f, 4.f, 0.f, 0.f, 3.f);
	float f1 = 100.f;

	// Get
	std::cout << "------ 1 -----" << std::endl;
	std::cout << "Type : " << player.getType() << std::endl; 
	std::cout << "Width : " << player.getWidth() << std::endl; 
	std::cout << "Height : " << player.getHeight() << std::endl; 
	std::cout << "PosX : " << player.getPosX() << std::endl; 
	std::cout << "PosY : " << player.getPosY() << std::endl; 
	std::cout << "Speed : " << player.getSpeed() << std::endl; 
	std::cout << "InitX : " << player.getInitX() << std::endl; 
	std::cout << "InitY : " << player.getInitY() << std::endl; 

	//Set
	player.setType('N');
	player.setSpeed(f1);
	player.setInitX(f1); 
	player.setInitY(f1);

	//Get
	std::cout << "------ 2 -----" << std::endl;
	std::cout << "Type : " << player.getType() << std::endl; 
	std::cout << "Width : " << player.getWidth() << std::endl; 
	std::cout << "Height : " << player.getHeight() << std::endl; 
	std::cout << "PosX : " << player.getPosX() << std::endl; 
	std::cout << "PosY : " << player.getPosY() << std::endl; 
	std::cout << "Speed : " << player.getSpeed() << std::endl; 
	std::cout << "InitX : " << player.getInitX() << std::endl; 
	std::cout << "InitY : " << player.getInitY() << std::endl; 
}

void testCell(){
	// Constructeur
	Cell cell('c',1.f, 1.f, 2.f, 3.f, 4.f);
	float f1 = 100.f;

	// Get
	std::cout << cell.getType() << std::endl; 
	std::cout << cell.getWidth() << std::endl; 
	std::cout << cell.getHeight() << std::endl; 
	std::cout << cell.getPosX() << std::endl; 
	std::cout << cell.getPosY() << std::endl; 

	//Set
	cell.setType('a');
	cell.setWidth(f1); 
	cell.setHeight(f1); 
	cell.setPosX(f1);
	cell.setPosY(f1);

	//Get
	std::cout << cell.getType() << std::endl; 
	std::cout << cell.getWidth() << std::endl; 
	std::cout << cell.getHeight() << std::endl; 
	std::cout << cell.getPosX() << std::endl; 
	std::cout << cell.getPosY() << std::endl; 
}

void testCoin(){
	// Constructeur
	Coin coin('c',1.f, 1.f, 2.f, 3.f, 4.f, 10);
	float f1 = 100.f;

	// Get
	std::cout << coin.getType() << std::endl; 
	std::cout << coin.getWidth() << std::endl; 
	std::cout << coin.getHeight() << std::endl; 
	std::cout << coin.getPosX() << std::endl; 
	std::cout << coin.getPosY() << std::endl; 
	std::cout << coin.getValue() << std::endl; 


	//Set
	coin.setType('a');
	coin.setWidth(f1); 
	coin.setHeight(f1); 
	coin.setPosX(f1);
	coin.setPosY(f1);
	coin.setValue(20);


	//Get
	std::cout << coin.getType() << std::endl; 
	std::cout << coin.getWidth() << std::endl; 
	std::cout << coin.getHeight() << std::endl; 
	std::cout << coin.getPosX() << std::endl; 
	std::cout << coin.getPosY() << std::endl; 
	std::cout << coin.getValue() << std::endl; 
}

int main(int argc, char const *argv[]){
	// Constructeur
	Arrival arrival('c',1.f, 1.f, 2.f, 3.f, 4.f);
	float f1 = 100.f;

	// Get
	std::cout << arrival.getType() << std::endl; 
	std::cout << arrival.getWidth() << std::endl; 
	std::cout << arrival.getHeight() << std::endl; 
	std::cout << arrival.getPosX() << std::endl; 
	std::cout << arrival.getPosY() << std::endl; 


	//Set
	arrival.setType('a');
	arrival.setWidth(f1); 
	arrival.setHeight(f1); 
	arrival.setPosX(f1);
	arrival.setPosY(f1);


	//Get
	std::cout << arrival.getType() << std::endl; 
	std::cout << arrival.getWidth() << std::endl; 
	std::cout << arrival.getHeight() << std::endl; 
	std::cout << arrival.getPosX() << std::endl; 
	std::cout << arrival.getPosY() << std::endl; 
	return 0;
}

