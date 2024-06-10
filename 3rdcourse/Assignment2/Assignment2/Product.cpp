/*
	MANUEL BISHOP NORIEGA
	Product Class implementation file.

*/


#include "Product.h"
#include <sstream>
#include <algorithm>

// default constructor asking the user to input data members
Product::Product()
{
	productName = new string; //allocating memory dynamically

	bool flag = false;
	string str = "";
	while(!flag)	// ----------- this loop is to validate bar code number (postive integer allowed)
	{
		cout << endl << "Please enter a Bar Code Number: (decimals will be disregarded)" << endl;
		getline(cin, str); 
		stringstream(str) >> barCode;
		cout<<((flag = ( (all_of(str.begin(), str.end(), isdigit)) && (barCode > 0))? true:false)?"":"Code must be a postive integer. Try again.\n");

	}

	while (flag)  // loop to validate string for product name is not empty
	{
		cout << endl << "Please enter the Product name:" << endl;
		getline(cin, *productName);
		cout << ((flag = productName->empty()) ? "No empty string allowed": "");

		//cout<<((flag = (*productName == "") ? true : false)?"No empty string allowed. Try again.\n":"");
	}
}

// constructor receiving data members as parameters
Product::Product(int _barCode, const string& _productName)
{
	/*
		----------------------				 R E A D    M E  ! ! !            ---------------------

		initially, in this constructor I just did:

		barCode=_barCode;
		productName = new string(_productName);
		
		but after reading assignment guidelines, I wasn't sure whether data validation was required only for default
		constructor asking user to input data or this constructor too. Considering that we are not allowed to add
		more data/functions than those explicitly required I had to duplicate some code for validation. because I'm still
		not sure what are we supposed to do, I added this validation only in this class.
	*/
	bool flag = false;
	string str = "";

	if (_barCode > 0)
	{
		barCode = _barCode;
	}
	else
	{
		cout << "\nwrong value for code was passed to constructor, please fix it\n";
		while (!flag)	// ----------- this loop is to validate bar code number (postive integer allowed)
		{
			cout << endl << "Please enter a Bar Code Number: (decimals will be disregarded)" << endl;
			getline(cin, str); stringstream(str) >> barCode;
			cout << ((flag = (barCode > 0) ? true : false) ? "" : "Code must be a postive integer. Try again.\n");
		}
	}

	if (_productName != "")
	{
		productName = new string(_productName);
	}
	else
	{
		productName = new string;
		flag = true;
		cout << "\nwrong value for product name was passed to constructor, please fix it\n";
		while (flag)  // loop to validate string for product name is not empty
		{
			cout << endl << "Please enter the Product name:" << endl;
			getline(cin, *productName);
			cout << ((flag = (*productName == "") ? true : false) ? "No empty string allowed. Try again.\n" : "");
		}

	}
}

// this destructor makes sure proper de-allocation of any dynamically allocated memory
Product::~Product()
{
	delete productName;
}

// show function for our base class, send data members to an output stream (screen or a file)
void Product::show(ostream& os)
{
	os << "BarCode: "<<getBarCode() << "\t\t Product name: " << getProductName() << endl;
}