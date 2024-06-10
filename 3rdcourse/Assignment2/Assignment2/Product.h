/*
header file for Product class specification
BASE CLASS
*/

#pragma once
#include <string>
#include <iostream>

using namespace std;

class Product
{
	public:
		Product();						// default constructor
		Product(int, const string&);	// constructor overload, accepts 2 args 
		~Product();						// destructor
		virtual void show(ostream&);	// We need to make it virtual to allow child implementations.

		// inline functions for the getters
		int getBarCode()
		{
			return barCode;
		}
		string getProductName()
		{
			return (productName!=nullptr)?*productName:"";
		}

		// data members will be accessible from derived classes
	protected:
		int barCode;
		string* productName;
};
