/*
	DERIVED CLASS - FreshFood
	this class is based on Product class and adds 2 data members: class unitPrice and weight
	it also implements its own show function, adding the new data members to the
	output and performing a calculation to print the final price.
*/

#pragma once
#include "Product.h" // must be included to be able to inherit from Product

class FreshFood :public Product
{
	private:
		double unitPrice;
		double weight;

	public:
		FreshFood();							// default constructor
		FreshFood(int, string, double, double); // constructor overload

		void show(ostream&);					 // sends data members to output stream

		// getters functions
		double getUnitPrice()
		{
			return unitPrice;
		}
		double getWeight()
		{
			return weight;
		}
};

