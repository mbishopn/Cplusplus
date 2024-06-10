/*****************************************************************************************************************
	MANUEL BISHOP NORIEGA
	client code file.
	this code tests if I built the classes according to the instructions.
	I also implemented a polymorphic function called showProduct() which calls show()
	built-in inside the objects.

	for each class:
		- dynamically creates an instance using the constructor overload by passing all data members when called.
		- prints all data members by calling show() class function
		- calls the polymorphic fucntion to print all data members again

		- dynamically creates an instance using the default constructor, which asks user for data members values.
		- prints data members using show() class function.
		- prints data members once again calling showProduct() function.

*******************************************************************************************************************/		


#include <iostream>
#include "FreshFood.h";		// must include our class headers to be able to instantiate objects. As seen in class,
#include "PrePackedFood.h"; // Product.h base class is already included in derived class so there's no need to include it here

using namespace std;

//Write the code for the polymorphic function. Label all output. Add a comment statement clearly identifying the polymorphic function.
void showProduct( Product&); // function header. Implementation is after main()


int main()
{
	// do not change my main except where you call the polymorphic function as indicated below

	cout << "1a) Create dynamic Product (non default): " << endl;
	Product* phone = new Product(90, "Android cell");
	//assert(phone);
	cout << "Name= " << phone->getProductName() << endl;
	cout << "Bar code=" << phone->getBarCode() << endl << endl;
	phone->show(cout);
	cout << "Call polymorphic function:\n ";

	showProduct(*phone); // calling the polymorphic function passing a Product object.

	cout << endl << endl;
	delete phone; // de-allocating memory

	cout << "1b) Create dynamic Product (default): " << endl;
	Product* item = new Product;
	//assert(item);
	cout << "Name= " << item->getProductName() << endl;
	cout << "Bar code=" << item->getBarCode() << endl << endl;
	item->show(cout);
	cout << "Call polymorphic function:\n ";

	showProduct(*item); // calling the polymorphic function passing a Product object.

	cout << endl << endl;
	delete item;// de-allocating memory

	cout << "2a) Create dynamic PrePackedFood (non default): " << endl;
	PrePackedFood* pasta = new PrePackedFood(40, "spaghetti", -.67);
	//assert(pasta);
	cout << "Name= " << pasta->getProductName() << endl;
	cout << "Bar code=" << pasta->getBarCode() << endl << endl;
	cout << "Unit Price=" << pasta->getUnitPrice() << endl << endl;
	pasta->show(cout);
	cout << "Call polymorphic function:\n ";

	showProduct(*pasta); // calling polymorphic function passing a PrePackedFood object

	cout << endl << endl;
	delete pasta;// de-allocating memory


	cout << "2b) Create dynamic Prepacked (default): " << endl;
	PrePackedFood* food = new PrePackedFood;
	//assert(food);
	cout << "Name= " << food->getProductName() << endl;
	cout << "Bar code=" << food->getBarCode() << endl << endl;
	cout << "Unit Price=" << food->getUnitPrice() << endl << endl;
	food->show(cout);
	cout << "Call polymorphic function:\n ";

	showProduct(*food); // calling polymorphic function passing a PrePackedFood object

	cout << endl << endl;
	delete food;// de-allocating memory


	cout << "3a) Create dynamic FreshFood (non default): " << endl;
	FreshFood* apples = new FreshFood(-6, "Delicious", 1.1, .67);
	//assert(apples);
	cout << "Name= " << apples->getProductName() << endl;
	cout << "Bar code=" << apples->getBarCode() << endl << endl;
	cout << "Weight=" << apples->getWeight() << endl << endl;
	cout << "Price=" << apples->getUnitPrice() << endl << endl;
	apples->show(cout);
	cout << "Call polymorphic function:\n ";

	showProduct(*apples); // now pass a FreshFood object

	cout << endl << endl;
	delete apples;// de-allocating memory

	cout << "3b) Create dynamic FreshFood (default): " << endl;
	FreshFood* freshPtr = new FreshFood;
	//assert(freshPtr);
	cout << "Name= " << freshPtr->getProductName() << endl;
	cout << "Bar code=" << freshPtr->getBarCode() << endl << endl;
	cout << "Weight=" << freshPtr->getWeight() << endl << endl;
	cout << "Price=" << freshPtr->getUnitPrice() << endl << endl;
	freshPtr->show(cout);
	cout << "Call polymorphic function:\n ";

	showProduct(*freshPtr); // another freshFood object

	cout << endl << endl;
	delete freshPtr;// de-allocating memory

	system("pause");
}

// this is the polymorphic function which calls the right show() function inside the object,
// disregarding whether it belongs to a base or derived class object.
void showProduct( Product& object)
{
	cout << "-------------------------------------------------------------------------------------\n";// just added this to rapidly indentify the call to polymorphic function
	object.show(cout);
}
