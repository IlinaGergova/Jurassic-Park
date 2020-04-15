#pragma once
#include"Dinosaur.h"
#include"ParkEnumerables.h"

class Cage {
	int sizeOfCage;
	Climate climate;
	Dinosaur*animals;
	int size;
	Era era;

	void copy(const Cage&other);
	void erase();
public:
	Cage(SizeOfCage newSizeOfCage = Medium, Climate newClimate = Land);
	Cage(const Cage&other);
	~Cage();
	Cage&operator=(const Cage&other);

	bool addAnimalInCage(const Dinosaur &newAnimal);

	bool removeAnimalFromCage(const Dinosaur &newAnimal);
};