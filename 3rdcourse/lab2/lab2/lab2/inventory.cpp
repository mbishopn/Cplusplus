/*
MANUEL BISHOP NORIEGA
ID: 4362207

This is the implementation file for Inventory class defined in header file Inventory.h
here I wrote the code for all methods (constructors, destructors, getters, setters, functions, etc)
belonging to Inventory class as required in assignment.
Every time I want to use this class in another program, I just need to call this file with #include directive
*/


#include <fstream>
#include<sstream>
#include<iomanip>
#include "Inventory.h"

// --------------- function searchProduct() ----------------
// search a product in Array by product code, returns product index position in the array
  int Inventory::searchProduct(int productCode)
{
	bool found = false;
	int index = 0;
	for (int ii=0; (!found)&&(ii<noProducts);ii++)
	{
		if (products[ii].ProductCode == productCode)
		{
			index = ii;
			found = true;
		}
	}

	return(found ? index : noProducts);
}

// ---------------- function showProduct() -------------
// provided product code, shows info related to that specific product
  void Inventory::showProduct(int productCode)
{
	int productIndex = searchProduct(productCode);
	if (productIndex == noProducts)
	{
		cout << "Product not found." << endl;
	}
	else{
		cout << left << setw(15) << products[productIndex].ProductCode
		<< setw(25) << products[productIndex].description
		<< "$ " << setw(15) << products[productIndex].price << endl;
	}
}

//---------------- function writeInventory() ------------
// writes all products info to a stream that could be a file or the screen
  void Inventory::writeInventory(ostream& fout)
{
	fout << setw(85) << endl << "-------------------                INVENTORY REPORT                ------------------" << endl 
		<< endl << left << setw(15) << "PRODUCT CODE" << setw(25) << "DESCRIPTION" << setw(15) << "PRICE" << endl << endl;

	for (int ii = 0; ii < noProducts; ii++)
	{
		fout << left << setw(15) << products[ii].ProductCode
			<< setw(25) << products[ii].description
			<< "$ " << setw(15) << products[ii].price << endl;
	}
	fout << "\nTotal products in inventory: " << noProducts << endl;
}

// ----------------- function getNoProducts() --------------
// returns actual number of products in the array
  int Inventory::getNoProducts()
{
	return noProducts;
}

// ----------------- function increasePrice() --------------
// searches the product according to the code provided
// and increases the price in the specified amount
  void Inventory::increasePrice(int productCode, double increment)
{
	int productIndex = searchProduct(productCode);
	if (productIndex == noProducts)
	{
		cout << "Product not found, can't increase price." << endl;
	}
	else{
		cout << (products[productIndex].price + increment > 1000 ? "Max possible price ($1000) assigned" : "Price updated")<<endl<<endl;
		products[productIndex].price += (products[productIndex].price + increment > 1000 ? 1000 - products[productIndex].price:increment);
	}
}

// ------------- CONSTRUCTOR -------------------
// non-default constructor, creates an inventory from items read from a file named
// according to string passed as parameter and also set the array max size using the int parameter
// default value if no int passed is 25
  Inventory::Inventory(const string source, const int maxProducts)
{
	noProducts = 0;
	string line;
	ifstream ifile(source);
	this->maxProducts = (maxProducts>25?25:maxProducts); // if there's a chance of ambiguity then use this->
	if (!ifile.is_open())
	{
		cout << "error opening " << source << " file." << endl;
		system("pause");
		exit(-1);
	}
	// this loop reads source file and create feeds the array inside the Inventory object
	for (int recs=0; recs < SIZE && recs <maxProducts; recs++) // the object will add up to 25 products, extra products in file will be disregarded
	{
		if (ifile.eof())
		{
			break;
		}
		else
		{
			getline(ifile, line);
			if(line!="") // I added this to prevent record creation when reading an empty file, I suppose there's a better way
			{
				stringstream(line) >> products[recs].ProductCode;
				getline(ifile, products[recs].description);
				getline(ifile, line);
				stringstream(line) >> products[recs].price;
				noProducts++;
			}
		}
	}
}

  Inventory::~Inventory()
{
}