/*
	MANUEL BISHOP NORIEGA
	Derived class PrepackedFood implementation file
*/

#include "FreshFood.h"
#include <sstream>
#include <iomanip>

// default constructor asking user to input all data members
FreshFood::FreshFood()
{

	bool flag = false;
	string str = "";
	while (!flag) 	// ----------- this loop is to validate weight (postive double)
	{
		cout << endl << "Please enter weight in grams:" << endl;
		getline(cin, str); stringstream(str) >> weight;
		cout << ((flag = (weight > 0) ? true : false) ? "" : "Code must be a real number >= 0. Try again.\n");
	}

	while (flag)	// ----------- this loop is to validate price (postive double)
	{
		cout << endl << "Please enter price per gram:" << endl;
		getline(cin, str); stringstream(str) >> unitPrice;
		cout << ((flag = (unitPrice > 0) ?false:true) ? "" : "Code must be a real number >= 0. Try again.\n");
	}
}

// constructor receiving all data members as parameters
FreshFood::FreshFood(int _barCode, const string _productName, double _unitPrice, double _weight):Product(_barCode,_productName)
{
	unitPrice = _unitPrice;
	weight = _weight;
}

// show function, this one exists in base class but it's virtual so it's possible for this derived class to implement and use its own show function.
void FreshFood::show(ostream& os)
{
	Product::show(os);  // I'm lazy, so I just re-used existing code because there was no specific formatting requirement for this function
	os << fixed << setprecision(2)<< "weight: "<< weight << "\t\t Price per gram: $" << unitPrice<< "\t\t Total price: $" << (weight * getUnitPrice()) << endl;
}