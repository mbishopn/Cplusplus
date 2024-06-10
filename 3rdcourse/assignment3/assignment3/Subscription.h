/*
	MANUEL BISHOP NORIEGA
	Specification file. Contains all data members and methods declarations
*/

#pragma once
#include<iostream>

using namespace std;

class Subscription
{
	struct Magazine
	{
		string name;
		string isbn;
		char delivery;
		Magazine* link;
	};

private:

	Magazine* firstPtr;
	string distributorName;
	int numberOfMagazines;

public:
	// Non-default constructor. Accepts a string to set distributorName private member.
	Subscription(string);
	// Destructor. 
	~Subscription();
	// displays all magazines in the Susbscription list. Syntax: showMagazines(<output stream reference>)
	//Ex. showMagazines(cout);
	void showMagazines(ostream&);
	// Adds new Magazine node to Subscription list. Syntax: addMagazine(string <name>,string <isbn>, char <delivery mode>).
	//string<name> must be unique in the list, otherwise, addition will be refused.
	void addMagazine(string, string, char);
	// Removes a Magazine node from Subscription list. Sintax: removeMagazine(string<isbn>).
	// Function looks inside the list for a node having isbn field matching the string provided.
	// If match found, the node is deleted, otherwise, returns a not-found message.
	void removeMagazine(string,bool=false);
	// getter function for number of magazines data member
	int getNoMagazines() { return numberOfMagazines; };
	// getter function for distributor name data member.
	string getDistributorName() { return distributorName; };

};

