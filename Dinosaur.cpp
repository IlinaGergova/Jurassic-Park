#include"Dinosaur.h"
#include<cstring>
#include<iostream>
using namespace std;


void Dinosaur::copy(const Dinosaur&other) {
	name = new char[strlen(other.name) + 1];
	strcpy(name, other.name);

	gender = other.gender;

	era = other.era;

	group = other.group;

	kind = new char[strlen(other.kind) + 1];
	strcpy(kind, other.kind);

	food = other.food;
}

void Dinosaur::erase() {
	delete[]name;
	delete[]kind;
}

Dinosaur::Dinosaur(const char* newName, Gender newGender, Era newEra, Group newGroup, const char* newKind, Food newFood) {
	name = new char[strlen(newName) + 1];
	strcpy(name, newName);

	gender = newGender;

	era = newEra;
	
	group = newGroup;

	kind = new char[strlen(newKind) + 1];
	strcpy(kind, newKind);

	food = newFood;
	
}

Dinosaur::Dinosaur(const Dinosaur&other) {
	copy(other);
}

Dinosaur::~Dinosaur() {
	erase();
}

Dinosaur&Dinosaur::operator=(const Dinosaur&other) {
	if (this != &other) {
		erase();
		copy(other);
	}
	return *this;
}

char*Dinosaur::getName() const {
	return name;
}

Gender Dinosaur::getGender() const {
	return gender;
}

Era Dinosaur::getEra() const {
	return era;
}

Group Dinosaur::getGroup() const {
	return group;
}

char*Dinosaur::getKind() const {
	return kind;
}

Food Dinosaur::getFood() const {
	return food;
}

bool operator==(const Dinosaur&other1, const Dinosaur&other2) {
	if (strcmp(other1.name, other2.name) == 0 && other1.gender == other2.gender && other1.era == other2.era &&
		other1.group == other2.group &&
		strcmp(other1.kind, other2.kind) == 0 && other1.food == other2.food) {
		return true;
	}
	return false;
}

/////////////////////////////////////////////////////////
ostream&operator<<(ostream &os, const Dinosaur &dino) {
	os << dino.name << " ";
	switch (dino.gender) {
		case Female: os << "female "; break;
		case Male: os << "male  "; break;
	}
	switch (dino.group) {
		case Flying: os << "flying "; break;
		case Aquatic: os << "aquatic "; break;
		case Herbivore: os << "herbivore "; break;
		case Carnivore: os << "carnivore "; break;
	}
	os << dino.kind << " ";
	switch (dino.group) {
		case Fish: os << "eats fish" << endl; break;
		case Meat: os << "eats meat" << endl; break;
		case Plants: os << "eats plants" << endl; break;
	}
	return os;
}