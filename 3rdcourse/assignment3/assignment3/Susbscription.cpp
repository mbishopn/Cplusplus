/*
	MANUEL BISHOP NORIEGA

	Definition file for Subscription class.
	All functions declared on the class are implemented here*, nothing more than that.
	Each function is preceded by a brief description.

	* except inline functions for getters, those are implemented in the specification file
	

	In comments, when I talk about:
	node, I refer to a Magazine struct
	list, I refer to a Subscription instance

*/

#include "Subscription.h"
#include<iomanip>

// parametrized constructor, receives a string for distributorName and put other data members to a safe state
Subscription::Subscription(string name){
	firstPtr = nullptr;			// points to the first node in the list, if no nodes, then nullptr
	distributorName = name;
	numberOfMagazines = 0;
};

// ---------------------------   destructor FUNCTION  ----------------------------
// destroys all nodes in the list,also sets numberOfMagazines to 0

Subscription::~Subscription() {
	Magazine* walker = firstPtr;	// every time you want a walkthrough a list, you'll need this pointing to 1st node in list
	Magazine* stalker = nullptr;	// annoying but useful guy

	cout << "DESTRUCTOR MESSAGES:\n";
	while (walker != nullptr)
	{
		stalker = walker;			// stalker thinks it gets walker
		walker = walker->link;		// but walker just walks ahead
		cout << stalker->name << " - " << stalker->isbn << " deleted from memory\n";
		delete stalker;				// now stalker dies de-allocating memory used for current node
	}
	numberOfMagazines = 0;
	cout << "no more Magazines in the list. " << numberOfMagazines << "nodes.\n";
};

// --------------------------   showMagazines FUNCTION  --------------------------
// sends all nodes information in the list to an ostream provided

void Subscription::showMagazines(ostream& os) {
	Magazine* walker = firstPtr;			// always need a walker to walkthrough a list, starts in the first node
	int count = 0;							// I want to put a list number in my report
	if (firstPtr == nullptr)				// is the list empty?
	{
		os << "This Subscription list is EMPTY";	// let user know
	}
	else	//  list is not empty then	1) print the header of report
	{		//							2) then loop through the list to print all magazines data
			//							3) finish the report printing total numbers of magazines in list
		os << "\n\n------------------  S U B S C R I P T I O N   R E P O R T  -------------------\n\n";

			os << "Distributor Name :\t" << distributorName << endl;
			os << left << "#  " << setw(4)<<" " << setw(21) << "Magazine Name" << setw(6) <<" "<< setw(12) << "ISBN" << "Delivery Type" << endl;
		while (walker != nullptr)
		{
			count++;
			os << setw(3) << count << setw(1) <<" "<< setw(24) << walker->name << setw(2) << " " << setw(18) << walker->isbn << "  " <<
			(walker->delivery=='D'?"Daily":(walker->delivery=='W'?"Weekly":"Monthly")) << endl;
			walker = walker->link;
		}
	}

	os << "\n# of Magazines = " << numberOfMagazines << endl;
	os << "\n-------------------------------------------------------------------------------\n\n";

};

// ---------------------------   addMagazine FUNCTION  ---------------------------
// inserts a node in the list in ascending order by magazine name

void Subscription::addMagazine(string name, string isbn, char delivery='m') {
	Magazine* walker = firstPtr;		// c'mon! we all already know this
	Magazine* builder = nullptr;		// you want this guy to "build" your new node right? we can call it Bob
	Magazine* stalker = nullptr;		// always watching walker's back and gets into action when required, we should better call it bodyguard :D
	bool found = false;					// flag to decide whether new node insertion is performed or not.

	if (toupper(delivery) != 'D' && toupper(delivery) != 'W' && toupper(delivery) != 'M')
	{
		cout << "ERROR ADDING MAGAZINE: ("<< name << ") delivery must be only D,d,M,m,W,w.\n Magazine won't be added...\n";
	}
	else 
	{
		if (firstPtr == nullptr)		// empty list?, then add the first node
		{
			firstPtr = new Magazine({ name, isbn, char(toupper(delivery))});
			firstPtr->link = nullptr;
			cout << "MAGAZINE : " << firstPtr->name << " was added as the VERY FIRST element in this list\n";
			numberOfMagazines++;
		}
		else
		{
			while (walker != nullptr && !found)		// at least one node in the list? enter this loop to look for a coincident name
			{
				if (walker->name == name)	// magazine already in the list? then send a message and finish
				{
					cout << "ERROR ADDING MAGAZINE: (" << name << ") already exists in the list, can't add another with the same name\n";
					found = true;			// let's get out of here
				}
				else
				{
					if (stalker != nullptr && stalker->name < name && name < walker->name)
					{
						break; // leave the loop with current stalker and walker
					}
				}
				stalker = walker;
				walker = walker->link;
			}
			if (!found)
			{
				builder = new Magazine({ name,isbn,char(toupper(delivery)) });
				if (walker == nullptr)
				{
					if (stalker==firstPtr) // add the 2nd node
					{
						if (stalker->name > name)
						{
							builder->link = stalker;
							firstPtr = builder;
							cout << "MAGAZINE : " << (name) << " was 2nd element added. At the beginning of the list\n";
						}
						else
						{
							builder->link = walker;
							stalker->link = builder;
							cout << "MAGAZINE : " << (name) << " was added 2nd in the list\n";
						}
					}
					else
					{
						if (firstPtr->name > name)
						{
							builder->link = firstPtr;
							firstPtr = builder;
							cout << "MAGAZINE : " << (name) << " was added at the beginning of the list\n";
						}
						else
						{
							builder->link = walker;
							stalker->link = builder;
							cout << "MAGAZINE : " << (name) << " was added at the end of the list\n";
						}
					}
				}
				else
				{
					builder->link = walker;
					stalker->link = builder;
					cout << "MAGAZINE : " << (name) << " was added in the middle of the list\n";
				}
				numberOfMagazines++;
			}
		}
	}
};

// --------------------------   removeMagazine FUNCTION  -------------------------
// removes a node with specific isbn from the list, I added an extra argument to 
// control if delete all instances found or only the first one, by default it
// deletes only the firs instance found

void Subscription::removeMagazine(string isbn, bool all) {
	Magazine* walker = firstPtr;	// ¬¬
	Magazine* bodyguard = nullptr;	// re-baptized helpful guy!
	bool found = false;
	int count = 0;
	
	if (firstPtr == nullptr)				// is the list empty?
	{
		cout << "This Subscription list is EMPTY, no nodes to remove";
	}
	while (walker != nullptr && !found)
	{
		if (firstPtr->isbn==isbn)	// node to delete is the 1st one?
		{
			cout << "FIRST node in list (" << walker->name << ") was removed\n";
			firstPtr = walker->link;
			delete walker; // delete 1st node
			numberOfMagazines--;
			walker = firstPtr;
			count++;
			if (all)
			{
				continue;
			}
			else 
			{
				found = true;
			}
		}
		else{
		if (walker->isbn == isbn)	// is this the register to delete?
		{
			//found = true;			// then say you found it and destroy him

				cout << "MIDDLE/LAST node in list (" << walker->name << ") was removed\n";
				bodyguard->link = walker->link;
				delete walker;
				walker = bodyguard->link;
				numberOfMagazines--;
				count++;
				if (all)
				{
					continue;
				}
				else
				{
					found = true;
				}
		}
		bodyguard = walker;
		if(walker)
			walker = walker->link;

	}}
	cout << "\nTotal nodes removed: " << count<<endl;
};
