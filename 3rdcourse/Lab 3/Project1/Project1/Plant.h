
#pragma once
#include <string>
#include <iostream>

using namespace std;

class Plant {
    private:
        string* Name;

    public:
        // functions declarations, only prototypes
        // Default constructor
        Plant();

        // Constructor with a name
        Plant(const string& name);

        Plant(const Plant& other); // copy constructor

        ~Plant(); // destructor

        Plant& operator=(const Plant&); // assignment operator overload

        // Getter for Name
        string getName() const;

        // Setter for Name
        void setName(const string&);

        // Pure virtual function for display
        virtual void display(ostream&) const =0;
};

// all class functions are implemented below

// Default constructor implementation, puts the Name pointer in a safe state
Plant::Plant():Name(nullptr){}

// Parametrized Constructor implementation --- this one accepts a string as a argument to set the name data member
Plant::Plant(const string& name){
    Name = new string(name);
}

// Copy constructor implementation
Plant::Plant(const Plant& other){
    *this = other;  // because we're lazy, we re-use code from assignment operator overload
}

// assignment operator overload, 
Plant& Plant::operator=(const Plant& other){

    // let's check that this is not self-assignment
    if (this != &other)
    {
        if (Name != nullptr)        // is Name data member in destination already pointing to something?
        {
            delete Name;            // delete to prevent memory leaks
        }

        if (other.Name != nullptr)  // is Name data member in source object pointing to something?
        {
           Name = new string;      // then let's Name in dest object points to it too, but first allocate the space to hold the value
           *Name = *(other.Name);  // now we can safely copy the content to the recently allocated spot in memory. deep copy
        }
        else                        // Name in source object is pointing to nothing?
        {
            Name = nullptr;         // then just do the same with dest_object Name data member
        }
        return *this;   // once we do all validations and copies, return the new object wich is a copy of the original one.
    }
}
/**/

// Destructor implementation
virtual Plant::~Plant() {
            cout << *Name << " was destroyed" << endl;
            delete Name;// deallocate all dynamically allocated variables to prevent memory leaks
    }  

// Getter for Name implementation
string Plant::getName() const {  
    return ((Name)? (*Name): "\nname is empty"); // returns the name if Name has been set to point ot something different from nullptr, otherwise returns "name is empty" message.
}

// Setter for Name implementation
void Plant::setName(const string& name) {
    delete Name; // deallocate memory to prevent memory leakage 
    Name = new string(name); // allocate memory for the new name
}

