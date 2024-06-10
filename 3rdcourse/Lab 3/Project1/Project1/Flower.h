#pragma once
#include "Plant.h"  // to be able to inherit from this class

using namespace std;

class Flower : public Plant
{
private:
	string * color;

public:
	// default constructor, not required, but I wanted to check my assignment operator and copy constructor
	Flower();
	// parametrized constructor
	Flower(const string&, const string& = "transparente");

	void display(ostream&) const;
	~Flower();
};

Flower::Flower(): color(nullptr), Plant()
{

}

Flower::Flower(const string& name, const string& flowerColor) : Plant(name)
{
	color = new string(flowerColor);
}
//
void Flower::display(ostream& os) const{
	os << endl << "Flower Name: " << getName() << "\t\tColor: " << *color << endl;

}

Flower::~Flower() {
	cout << "limpio mi basurero\n";
	delete color;
}
//
