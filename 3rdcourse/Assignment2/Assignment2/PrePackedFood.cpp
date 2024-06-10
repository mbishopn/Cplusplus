/*
	MANUEL BISHOP NORIEGA
	Derived class PrepackedFood implementation file
*/

#include "PrePackedFood.h"
#include <sstream>
#include <iomanip>

// default constructor asking user to input data members
PrePackedFood::PrePackedFood()
{
	bool flag = false;
	string str = "";
	while (!flag)	// ----------- in loop price is validated (postive integer allowed)
	{
		cout << endl << "Please enter unit Price:" << endl;
		getline(cin, str); stringstream(str) >> unitPrice;
		cout << ((flag = (unitPrice > 0) ? true : false) ? "" : "Code must be a real number >= 0. Try again.\n");
	}

}

// constructor accepting all datamembers as parameters
PrePackedFood::PrePackedFood(int _barCode, const string _productName, double _unitPrice):Product(_barCode, _productName)
{
	unitPrice = _unitPrice;
}

// show function, this one exists in base class but it's virtual so it's possible for this derived class to implement and use its own show function.
void PrePackedFood::show(ostream& os)
{
	Product::show(os);  // I'm lazy, so I just re-used existing code because there was no specific formatting requirement for this function
	os << fixed << setprecision(2) << "Price: $" << getUnitPrice() << endl;
}