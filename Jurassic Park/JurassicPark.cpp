#include"JurassicPark.h"
#include<iostream>
using namespace std;

void JurassicPark::copy(const JurassicPark&other) {
	cages = other.cages;
	size = other.size;
}

void JurassicPark::erase() {
	delete[]cages;
}

void JurassicPark::resize() {
	Cage* newCages = new Cage[cap + 10];
	for (int i = 0; i < cap; i++) {
		newCages[i] = cages[i];
	}
	erase();
	cages = newCages;
	delete[] newCages;
	cap += 10;
}

JurassicPark::JurassicPark() {
	fish = 0;
	plants = 0;
	meat = 0;
}

JurassicPark::JurassicPark(const JurassicPark&other) {
	copy(other);
}

JurassicPark::~JurassicPark() {
	erase();
}

JurassicPark&JurassicPark::operator=(const JurassicPark&other) {
	if (this != &other) {
		erase();
		copy(other);
	}
	return*this;
}

void JurassicPark::addAnimalInPark(const Dinosaur &newDino) {
	Food dinoFood = newDino.getFood();
	if ((dinoFood == Fish && fish <= 0) && (dinoFood == Meat && meat <= 0) && (dinoFood == Plants && plants <= 0)) {
		cout << "Not enough " << dinoFood << ". Add more food first!" << endl;
		return;
	}

	for (int i = 0; i < size; i++) {
		if (cages[i].addAnimalInCage(newDino)) {
			switch (dinoFood) {
				case Fish: fish--;break;
				case Meat: meat--;break;
				case Plants: plants--;break;
			}
			return;
		}
	}
	cout << "No suitable cage.Please create one for " << newDino.getGroup() << " dinosaur." << endl;

}

void JurassicPark::makeCage(SizeOfCage cageSize, Climate climate) {
	Cage newCage(cageSize, climate);
	if (size == cap) {
		resize();
	}
	cages[size] = newCage;
	size++;
}

void JurassicPark::removeAnimal(Dinosaur animal) {
	for (int i = 0; i < size; i++) {
		if (cages[i].removeAnimalFromCage(animal)) {
			cout << animal.getName() << " has been removed from the park." << endl;
			return;
		}
	}
	cout << "There is no such a dinosaur in the park." << endl;
}

void JurassicPark::foodDelivery(int fishToAdd, int plantsToAdd, int meatToAdd) {
	fish += fishToAdd;
	plants += plantsToAdd;
	meat += meatToAdd;
}