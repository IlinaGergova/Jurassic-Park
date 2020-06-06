#include"Cage.h"
#include<cstring>

Cage::Cage(SizeOfCage newSizeOfCage, Climate newClimate) {
	switch (newSizeOfCage) {
	case Small:sizeOfCage = 1; break;
	case Medium:sizeOfCage = 3; break;
	case Large:sizeOfCage = 10; break;
	}

	climate = newClimate;

	size = 0;

	era = NoEra;
}

bool Cage::addAnimalInCage(const Dinosaur &newAnimal) {
	if (size == sizeOfCage
		|| (climate == Air && newAnimal.getGroup() != Flying)
		|| (climate == Land && (newAnimal.getGroup() != Herbivore && newAnimal.getGroup() != Carnivore))
		|| (climate == Water && newAnimal.getGroup() != Aquatic)) {
		return false;
	}
	else if (size == 0) {
		era = newAnimal.getEra();
	}
	else if (era != newAnimal.getEra()) {
		return false;
	}

	animals.push_back(newAnimal);
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
	animals.erase(animals.begin() + index);
	size--;

	if (size == 0) {
		era = NoEra;
	}

	return true;
}

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

void Cage::saveCage(ostream& file) {
	file << '#';
	file << sizeOfCage << " " << climate << '\n';
	for (int i = 0; i < size; i++) {
		animals[i].saveDino(file);
	}
}

Cage loadCage(istream& file) {
	int sizeCage, climate;
	file >> sizeCage >> climate;
	
	SizeOfCage size;
	switch (sizeCage) {
	case 1:size = Small; break;
	case 3:size = Medium; break;
	case 10:size = Large; break;
	}

	Climate c;
	switch (climate) {
		case 0:c = Air; break;
		case 1:c = Land; break;
		case 2:c = Water; break;
	}
	file.get();
	Cage cage(size, c);
	char symbol;
	symbol = file.peek();
	while (symbol == '^' && !file.eof()) {
		file.get();
		cage.addAnimalInCage(loadDino(file));
		file.get();
		symbol = file.peek();
	}

	return cage;
}

