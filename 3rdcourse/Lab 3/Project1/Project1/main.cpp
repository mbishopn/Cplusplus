#include <iostream>
//#include "Plant.h"  // Include the Plant base class header
#include "Flower.h"  // Include the Flower derived class header
#include "Tree.h"    // Include the Tree derived class header

using namespace std;

int main() {
    // Create dynamic pointers to Plant
    Plant* plant1 = new Flower("Red Rose", "red");
    Plant* plant2 = new Tree("Oak Tree", 50);
    Plant* plant3 = new Flower("Flor exquisita");
    // Display information about the dynamically allocated Flower and Tree
    std::cout << "Flower Information:" << std::endl;
    plant1->display(std::cout);

    std::cout << "\nTree Information:" << std::endl;
    plant2->display(std::cout);

    std::cout << "My Flower Information:" << std::endl;
    plant3->display(std::cout);

    // Clean up dynamically allocated objects
    delete plant1;
    delete plant2;
    delete plant3;

    //int *p = new int[3];
    //int xx 25;
    //cout << "xx vale: " << xx << endl;
    //cout << "\nel puntero p va a: " << p << "\n y su valor es :" << *p;

    //for (int x = 0; x < 3; x++)
    //{
    //    p[x] = x + 1;
    //}

    //cout << "ahora el arreglo completo \n";
    //for (int ii = 0; ii < 3; ii++)
    //{
    //    cout << p[ii]<< " ";
    //}


    //delete [] p;

    return 0;
}