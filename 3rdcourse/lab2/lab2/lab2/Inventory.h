/*
MANUEL BISHOP NORIEGA
ID: 4362207

Class Definition/specification file.
This is our blueprint for the class, I built it based on UML diagram
to add members and methods prototypes.
I'm defining here the const SIZE and ProductRec struct used by the class.

*/

#pragma once
#include <string>
#include<iostream>
using namespace std;

const int SIZE = 25;
struct ProductRec
{
	int ProductCode;
	string description;
	double price;
};

class Inventory
{
	public:
		 void showProduct(int); // receives a product code (int) and displays the info related
		 void writeInventory(ostream &); // writes all products in the array to the output stream (file/screen) received
		 int getNoProducts(); // returns actual number of products in array (int)
		 void increasePrice(int, double); // receives a product code (int), finds the product and increases its price adding the amount received (double)
		 Inventory(const string, const int=25); // constructor accepting 2 arguments, 1) file to read data and 2) integer for noProducts
		 ~Inventory(); // default destructor

	private:
		ProductRec products[SIZE];
		int maxProducts;
		int noProducts;
		int searchProduct(int); // receives a product code (int), finds the product related and returns its position in array


};




