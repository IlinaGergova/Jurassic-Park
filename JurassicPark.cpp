#include "JurassicPark.h"
#include <iostream>
#include <cstdlib>
#include <ctime> 
using namespace std;


JurassicPark::JurassicPark(int MAX_CAGES) {
	fish = 0;
	plants = 0;
	meat = 0;
	if (MAX_CAGES == 0) {
		size = 0;
		staff = size;
	}
	else {
		srand(time(NULL));

		size = rand() % MAX_CAGES + 1;
		staff = size;

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
			cages.push_back(tempCage);
		}
	}
}


void JurassicPark::addAnimalInPark(const Dinosaur &newDino) {
	Food dinoFood = newDino.getFood();
	if ((dinoFood == Fish && fish <= 0) || (dinoFood == Meat && meat <= 0) || (dinoFood == Plants && plants <= 0)) {
		cout << "Not enough food for that dinosaur. Add more food first!" << endl;
		return;
	}

	for (int i = 0; i < size; i++) {
		if (cages[i].addAnimalInCage(newDino)) {
			switch (dinoFood) {
			case Fish: fish--; break;
			case Meat: meat--; break;
			case Plants: plants--; break;
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

	cages.push_back(newCage);
	size++;
}

void JurassicPark::addCageWithData(const Cage &newCage) {
	if (staff <= size) {
		cout << "Not enough staff. Please add." << endl;
		return;
	}

	cages.push_back(newCage);
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
	meat += meatToAdd;
	fish += fishToAdd;
	plants += plantsToAdd;
}
void JurassicPark::addStaff(int staffToAdd) {
	staff += staffToAdd;
}

ostream& operator<<(ostream& os, JurassicPark& park) {
	os << park.fish << " " << park.plants << " " << park.meat << " " << park.staff << '\n';
	for (int i = 0; i < park.size; i++) {
		park.cages[i].saveCage(os);
	}
	return os;
}

istream& operator>>(istream& is, JurassicPark& park) {
	int fish, plants, meat, staff;
	is >> fish >> plants >> meat >> staff;

	park.addStaff(staff);
	park.foodDelivery(fish, plants, meat);

	char symbol;

	is.get();
	symbol = is.peek();
	//cout << "cage:" << symbol << endl;
	while (symbol == '#' && !is.eof()) {
		is.get();
		park.addCageWithData(loadCage(is));
		//is.get();
		symbol = is.peek();
		//cout << "cage:" << symbol << endl;
	}

	return is;
}

void JurassicPark::print() {
	cout << "================================" << endl;
	cout << "Number of cages: " << size << endl;
	for (int i = 0; i < size; i++) {
		cout << "--------------------------------" << endl;
		cout << cages[i] << endl;
	}
	cout << "--------------------------------" << endl;
	cout << "================================" << endl;
	cout << "Quantity of fish: " << fish << endl;
	cout << "Quantity of plants: " << plants << endl;
	cout << "Quantity of meat: " << meat << endl;
	cout << "People in the staff: " << staff << endl;
	cout << "================================" << endl;

}