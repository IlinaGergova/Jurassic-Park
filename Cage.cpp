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
	delete[] animals;
	animals = nullptr;
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

	if (size == 0) {
		era = NoEra;
	}

	return true;
}

///////////////////////////////////////////////
ostream&operator<<(ostream &os, const Cage &cage) {
	switch (cage.sizeOfCage) {
		case 1: os << "Small cage "; break;
		case 3: os << "Medium cage "; break;
		case 10: os << "Large cage "; break;
	}
	switch (cage.climate) {
		case Land: os << "with land climate"; break;
		case Water: os << "with water climate"; break;
		case Air: os << "with air climate"; break;
	}
	switch (cage.era) {
		case Triassic: os << ", Triassic era" << endl; break;
		case Jurassic: os << ", Jurrasic era" << endl; break;
		case Cretaceous: os << ", Cretaceus era" << endl; break;
		case NoEra: os << ", no era yet" << endl; break;
	}
	

	for (int i = 0; i < cage.size; i++) {
		os << "-> " << cage.animals[i] << endl;
	}
	return os;
}

