#include"Cage.h"
#include<cstring>

void Cage::copy(const Cage&other) {
	sizeOfCage = other.sizeOfCage;

	climate = other.climate;

	animals = new Dinosaur[other.sizeOfCage];
	for (int i = 0; i < other.sizeOfCage; i++) {
		animals[i] = other.animals[i];
	}

	size = other.size;

	era = other.era;
	
}

void Cage::erase() {
	delete[]animals;
}

Cage::Cage(SizeOfCage newSizeOfCage, Climate newClimate) {
	switch (newSizeOfCage) {
		case Small:sizeOfCage = 1; break;
		case Medium:sizeOfCage = 3; break;
		case Large:sizeOfCage = 10; break;
	}

	climate = newClimate;

	size = 0;

	era = NoEra;

	animals = new Dinosaur[sizeOfCage];
}

Cage::Cage(const Cage&other) {
	copy(other);
}

Cage::~Cage() {
	erase();
}

Cage&Cage::operator=(const Cage&other) {
	if (this != &other) {
		erase();
		copy(other);
	}
	return *this;
}

bool Cage::addAnimalInCage(const Dinosaur &newAnimal) {
	if (size == sizeOfCage 
		|| (climate==Air && newAnimal.getGroup() != Flying)
		|| (climate == Land && (newAnimal.getGroup() != Herbivore && newAnimal.getGroup() != Carnivore))
		|| (climate == Water && newAnimal.getGroup() != Aquatic)){
		return false;
	}
	else if (size == 0) {
		era = newAnimal.getEra();
	}
	else if (era != newAnimal.getEra()) {
		return false;
	}

	animals[size] = newAnimal;
	size++;
	return true;
}

bool Cage::removeAnimalFromCage(const Dinosaur &newAnimal) {
	int index = -1;
	for (int i = 0; i < size; i++) {
		if (newAnimal == animals[i]) {
			index = i;
			break;
		}
	}
	if (index == -1) {
		return false;
	}
	for (int i = index; i < size - 1; i++) {
		animals[i] = animals[i + 1];
	}
	size--;
	return true;
}

