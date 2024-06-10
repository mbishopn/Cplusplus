/*
Use the following main() for your first assignment.
This code will replace your main()
******** Do not make any changes to this code!**********
You will need to add the required header files, prototypes and data files.

Add your name and a short narrative explaining the purpose of the program.

MANUEL BISHOP NORIEGA
ID: 4362207

This file is the main program (named client in the assignment),
by including inventory class implementation file it can instantiate
inventory object and access members and methods.

All files are found on Blackboard in the Assignments folder


*/
// write the showNoProducts() function

#include<iostream>
#include<iomanip>
#include<fstream>
#include "Inventory.h"

void showNoProducts(Inventory);

int main()
{
	
	cout << "Inventory object examples from Inventory.data file:" << endl << endl;
	Inventory company("Inventory.data", 15);
	cout << "\nNumber of products = "
		<< company.getNoProducts() << endl;
	cout << "printing all products in Inventory.data to the screen:\n\n";
	company.writeInventory(cout);
	cout << "\nLooking up product # 54312:\n";
	company.showProduct(54312);		//should be in Inventory.data, if not add it
	cout << "\nIncrease price by $1.22 for product # 54312\n\n";
	company.increasePrice(54312, 1.22);
	cout << "Looking up new price for product # 54312:\n";
	company.showProduct(54312);		//should be incremented
	cout << "\nLooking up product # 60000:\n";
	company.showProduct(60000);		//incremented over $1000
	cout << "\n\nIncrease price by $1000 for product # 60000:\n";
	company.increasePrice(60000, 1000.);
	cout << "Looking up new price for product # 60000\n\n";
	company.showProduct(60000);		//incremented over $1000
	cout << "Number of products = " << company.getNoProducts() << endl;
	cout << "\nprinting all products in Inventory.data screen:\n\n";
	company.writeInventory(cout);

	cout << "\n\n\nEmpty object examples from default.data file" << endl << endl;
	Inventory myshop("default.data");			//empty file
	cout << "Number of products = " << myshop.getNoProducts() << endl << endl;
	cout << "Increase price by $1.22 for product # 24000\n\n";//not in file
	myshop.increasePrice(3483, 1.22);
	ofstream fout("output.file");
	if (!fout.is_open())
	{
		cout << "error opening file " << endl;
		system("pause");
		exit(1);
	}
	fout << fixed << setprecision(2);
	myshop.writeInventory(fout);
	

	cout << "\n\nFull file (products.data file) examples" << endl << endl;
	Inventory fullLoad("product.data");  //file has more than 25 records
	fullLoad.increasePrice(854, 2.00);
	fullLoad.writeInventory(cout);
	cout << "Number of products  = " << fullLoad.getNoProducts()
		<< endl << endl;
	cout << "\nLooking up product # 666:\n";
	fullLoad.showProduct(666);  //pass one that doesn't exist

				   //add the code to call your showNoProducts() function here
	 // I'm calling the function to get noProducts for all Inventory objects created
	showNoProducts(company);
	showNoProducts(myshop);
	showNoProducts(fullLoad);

	system("type output.file");
	system("pause");
}

// showNoProducts function implementation
void showNoProducts(Inventory obj)
{
	cout << "Calling showNoProducts()-- Total Inventory items: " << obj.getNoProducts() << endl;
}
