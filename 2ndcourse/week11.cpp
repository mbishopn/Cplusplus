#include<iostream>
#include<sstream>
#include<string>
#include<iomanip>

using namespace std;

struct book
{
	string id;
	string author;
	string title;
	float price;
};

book readBook();
void printBooks(book books[], int n);
void printBook(book b1);
void drawline(int length);

using namespace std;

int main()
{
	int n = 3;
	book books[300]; // we define an array of max 300 books
	string str;
	for (int i = 0; i < n; i++)		// in this loop we read the books data
	{
		books[i] = readBook();
	}

	// now it's time to print all books
	printBooks(books, n);
	cout << "enter book id to print " << endl;
	cin >> str;
	for (int i = 0; i < n; i++)
		if (books[i].id == str)
		{
			printBook(books[i]);
			continue;
		}
		else
			cout << "Boot not found";

	return 0;
}


book readBook()
{	// read a temporary struct and return it
	string str;
	book temp;
	cout << "Book ID : ";
	getline(cin, temp.id);
	cout << "Author : ";
	getline(cin, temp.author);
	cout << "Title : ";
	getline(cin, temp.title);
	cout << "Price : ";
	getline(cin, str); stringstream(str) >> temp.price;

	return temp;
}

void drawline(int length)
{
	for (int i = 0; i < length; i++)
		cout << "=";
	cout << endl;
}

void printBooks(book books[], int n)
{
	cout << endl << endl; cout.left;
	drawline(85);
	cout << setw(10) << "ID" << setw(25) << "Title" << setw(25) << "Author" << setw(10) << "Price\n";
	drawline(85);

	for (int i = 0; i < n; i++)
	{
		cout << setw(10) << books[i].id;
		cout << setw(25) << books[i].title;
		cout << setw(25) << books[i].author;
		cout << setw(10) << "$" << books[i].price << endl;

	}
	drawline(85);
	cout << "\t" "total of books: " << n;
}

void printBook(book b1)
{
	cout << endl << endl; cout.left;
	drawline(85);
	cout << setw(10) << "ID" << setw(25) << "Title" << setw(25) << "Author" << setw(10) << "Price\n";
	drawline(85);

	cout << setw(10) << b1.id;
	cout << setw(25) << b1.title;
	cout << setw(25) << b1.author;
	cout << setw(10) << "$" << b1.price << endl;
	drawline(85);

}