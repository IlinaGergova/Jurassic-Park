#include "JurassicPark.h"
#include <iostream>
#include <cstdlib>
#include <time.h> 
using namespace std;

void JurassicPark::copy(const JurassicPark&other) {
	cages = new Cage[other.cap];
	for (int i = 0; i < other.size; i++) {
		cages[i] = other.cages[i];
	}
	size = other.size;
	cap = other.cap;
	fish = other.fish;
	plants = other.plants;
	meat = other.meat;
	staff = other.staff;
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

const int MAX_CAGES = 10;

JurassicPark::JurassicPark() {
	fish = 0;
	plants = 0;
	meat = 0;

	srand(time(NULL));

	size = rand() % MAX_CAGES + 1;
	cap = size;
	staff = size;

	cages = new Cage[cap];
	for (int i = 0; i < size; i++) {

		int number = rand() % 3 + 1;
		SizeOfCage cageSize;
		switch (number) {
			case 1:cageSize = Small;
			case 2:cageSize = Medium;
			case 3:cageSize = Large;
		}

		number = rand() % 3 + 1;
		Climate climate;
		switch (number) {
			case 1:climate = Air;
			case 2:climate = Water;
			case 3:climate = Land;
		}

		Cage tempCage(cageSize, climate);
		cages[i] = tempCage;
	}
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
	if (staff <= size) {
		cout << "Not enough staff. Please add." << endl;
		return;
	}

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


void JurassicPark::addStaff(int staffToAdd) {
	staff += staffToAdd;
}

ostream& operator<<(ostream& os, const JurassicPark& park) {
	os.write((char*)&park, sizeof(park));
	return os;
}

istream& operator>>(istream& is, const JurassicPark& park) {
	is.read((char*)&park, sizeof(park));
	return is;
}

void JurassicPark::print() {
	cout << "================================" << endl;
	cout << "Number of cages: " << size << endl;
	for (int i = 0; i < size; i++) {
		cout << "--------------------------------" << endl;
		cout << cages[i];
	}
	cout << "--------------------------------" << endl;
	cout << "================================" << endl;
	cout << "Quantity of fish: " << fish << endl;
	cout << "Quantity of plants: " << plants << endl;
	cout << "Quantity of meat: " << meat << endl;
	cout << "People in the staff: " << staff << endl;
	cout << "================================" << endl;
	
}

