#pragma once
#include"Cage.h"
#include<vector>


class JurassicPark {
	vector<Cage>cages;
	int size;
	int fish;
	int plants;
	int meat;
	int staff;

public:
	JurassicPark(int MAX_CAGES = 0);

	void addAnimalInPark(const Dinosaur &newDino);
	void makeCage(SizeOfCage cageSize, Climate climate);
	void addCageWithData(const Cage &newCage);
	void removeAnimal(Dinosaur animal);
	void foodDelivery(int fishToAdd, int plantsToAdd, int meatToAdd);
	void addStaff(int staffToAdd);

	friend ostream& operator<<(ostream& os, JurassicPark& park);
	friend istream& operator>>(istream& is, JurassicPark& park);

	void print();
};