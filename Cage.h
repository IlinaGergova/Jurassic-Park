#pragma once
#include"Dinosaur.h"
#include"ParkEnumerables.h"
#include<vector>

class Cage {
	int sizeOfCage;
	Climate climate;
	vector<Dinosaur>animals;
	int size;
	Era era;
	
public:
	Cage(SizeOfCage newSizeOfCage = Medium, Climate newClimate = Land);

	bool addAnimalInCage(const Dinosaur &newAnimal);

	bool removeAnimalFromCage(const Dinosaur &newAnimal);
	friend ostream&operator<<(ostream &os, const Cage &cage);

	void saveCage(ostream& file);
	friend Cage loadCage(istream& file);
};