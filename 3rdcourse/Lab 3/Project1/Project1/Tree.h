#pragma once
#include "Plant.h"

using namespace std;

class Tree : public Plant
{
private:
	int age;
public:
	// Parametrized constructor
	Tree(const string& name, int treeAge);
	void display(ostream&) const;

};

Tree::Tree(const string& name, int treeAge) : Plant(name)
{
	age = treeAge;
}

void Tree::display(ostream& os) const
{
	os << endl << "Tree Name: " << getName() << "\t\tAge: " << age << endl;

}