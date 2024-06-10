/*
	DERIVED CLASS - PrePackedFood
	this class is based on Product class and adds a data member class unitPrice
	it also implements its own show function adding unitPrice value to the output
*/

#pragma once
#include "Product.h" // must be included to be able to inherit from Product

class PrePackedFood :public Product
{
	private:
		double unitPrice;

	public:
		PrePackedFood();						// default constructor
		PrePackedFood(int, string, double);		// constructor overload

		void show(ostream&);					// sends data members to output stream

		// getter inline function for the data member
		double getUnitPrice()
		{
			return unitPrice;
		}
};

