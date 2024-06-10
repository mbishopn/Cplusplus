/*
	MANUEL BISHOP NORIEGA
	Client file, here I test behavior or my Subscriptiion class:
		- instantiation, adding and removing nodes methods
		- printing data members info

*/

#include "Subscription.h"
#include<string>
using namespace std;

int main() {

	Subscription* list1 = new Subscription("Disticor");

	// a) calling the get functions from recently created list
	cout << "a) Subscription instance created, and calling its getters to display info, I also called showMagazines()\n\n";
	cout << "Distributor: "  << list1->getDistributorName() << " Number of Magazines: " << list1->getNoMagazines() << "\n\n";
	list1->showMagazines(cout);
	system("pause");
	
	// b) adding some nodes to list
	cout << "\nb) calling addMagazine() repeatedly to add 8 nodes, 1 tries to repeat a name. Each call outcome will be displayed...\n\n";
	//list1->addMagazine("Cosmopolitan", "1234567891233", 'm');		// first node
	//list1->addMagazine("Dinousaurs", "1234567891230", 'd');			// second node added at the end
	list1->addMagazine("Ninousaurs (isbn rep)", "1234567891230", 'w');		// it should be added at the end, UNIQUE NAME - REPEATED ISBN
	//list1->addMagazine("Popular Mechanics", "1234567891231", 'm');	// it should be added at the end
	//list1->addMagazine("Men's Health", "1234567891232", 'w');		// it should be inserted in the middle
	//list1->addMagazine("Binousaurs (isbn rep)", "1234567891230", 'w');		// it should be inserted first, UNIQUE NAME - REPEATED ISBN
	//list1->addMagazine("Popular Mechanics", "1234567891231", 'm');	// REPEATED NAME - it shouldn't be added to the list
	//list1->addMagazine("American Science", "1234567891234", 'm');	// this should be inserted at the beginning
	//list1->addMagazine("blablabla", "34234cd", 'k');				// just to test delivery validation
	system("pause");

	// c) calling showMagazines to display the whole list info
	cout << "\nc) calling showMagazines(cout) to display all list nodes\n";
	list1->showMagazines(cout);
	system("pause");

	// d) removing some nodes
	cout << "\nd) calling removeMagazine(<isbn>) to remove nodes from beginning, middle and end of the list, every call outcome will be displayed\n\n";
	list1->removeMagazine("1234567891230",true);			// removes only the first onde found with this isbn
	//list1->removeMagazine("1234567891234");			// removes the current first node American Science
	//list1->removeMagazine("1234567891230",true);	// removes a node in the middle Dinosaurs, but there are still 2 nodes with the same isbn, so delete all of them
	//list1->removeMagazine("1234567891231");			// removes the last node in the current list Popular mechanics
	system("pause");

	// calling the getters again
	cout << "Distributor: " << list1->getDistributorName() << " handles " << list1->getNoMagazines() << " magazines.\n";
	// e) calling showMagazines() function
	cout << "\ne) calling showMagazines(cout) again to see report updated";
	list1->showMagazines(cout);
	system("pause");

	delete list1;
	return 0;
}