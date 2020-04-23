#pragma once
#include"Cage.h"


class JurassicPark {
	Cage*cages;
	int size;
	int cap;
	int fish;
	int plants;
	int meat;
	int staff;

	void copy(const JurassicPark&other);
	void erase();
	void resize();
public:
	JurassicPark();
	JurassicPark(const JurassicPark&other);
	~JurassicPark();
	JurassicPark&operator=(const JurassicPark&other);

	void addAnimalInPark(const Dinosaur &newDino);
	void makeCage(SizeOfCage cageSize, Climate climate);
	void removeAnimal(Dinosaur animal);
	void foodDelivery(int fishToAdd, int plantsToAdd, int meatToAdd);

	void addStaff(int staffToAdd);

	friend ostream& operator<<(ostream& os, const JurassicPark& park);
	friend istream& operator>>(istream& is, const JurassicPark& park);

	void print();
};

