#include"Dinosaur.h"
#include<cstring>
#include<iostream>
using namespace std;


Dinosaur::Dinosaur(const string newName, Gender newGender, Era newEra, Group newGroup, const string newKind, Food newFood) {
	name = newName;

	gender = newGender;

	era = newEra;

	group = newGroup;

	kind = newKind;

	food = newFood;

}

string Dinosaur::getName() const {
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

string Dinosaur::getKind() const {
	return kind;
}

Food Dinosaur::getFood() const {
	return food;
}

bool operator==(const Dinosaur&other1, const Dinosaur&other2) {
	if (other1.name == other2.name && other1.gender == other2.gender && other1.era == other2.era &&
		other1.group == other2.group &&
		other1.kind == other2.kind && other1.food == other2.food) {
		return true;
	}
	return false;
}

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
	switch (dino.food) {
	case Fish: os << "eats fish" << endl; break;
	case Meat: os << "eats meat" << endl; break;
	case Plants: os << "eats plants" << endl; break;
	}
	return os;
}

void Dinosaur::saveDino(ostream& file) {
	file << '^';
	file << name <<" "<< gender << " " << era << " " << group << " " << kind << " " << food << '\n';
}
Dinosaur loadDino(istream& file) {
	string name, kind;
	int gender, era, group, food;
	file >> name >> gender >> era >> group >> kind >> food;

	Gender g;
	switch (gender) {
		case 0:g = Male; break;
		case 1:g = Female; break;
	}

	Era e;
	switch (era) {
		case 0:e = Triassic; break;
		case 1:e = Jurassic; break;
		case 2:e = Cretaceous; break;
	}

	Group gr;
	switch (group) {
		case 0:gr = Flying; break;
		case 1:gr = Aquatic; break;
		case 2:gr = Herbivore; break;
		case 3:gr = Carnivore; break;
	}

	Food f;
	switch (food) {
	case 0:f = Fish; break;
	case 1:f = Meat; break;
	case 2:f = Plants; break;
	}

	Dinosaur dino(name, g, e, gr, kind, f);
	return dino;

}
