/*
	MANUEL BISHOP NORIEGA
	STUDENT ID: 4362207
	COMP1014 - INTERMEDIATE PROGRAMMING C++
	L A B   1 2
*/

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

void readBooks(book* b,int& n); // function to read up to n(max size of array), user decides when to stop reading
book readBook();				// reads data for each book in the array

/*	all next functions accept int n as argument to perform their functions considering
	only the number of books really stored in the array instead of looping through all
	300 elements in the array
*/
void printBooks(book books[], int n);	// prints all books registered
void printBook(book b1);				// prints only one book upon selection, this comes from previous lab I didn't remove it
void updateBook(book books[], int n);	// searchs a book and updates it
void deleteBook(book books[], int& n);	// searchs a book and deletes it
void drawline(int length);

using namespace std;

int main()
{
	int n = 0;
	book books[300]; // we define an array of max 300 books

	readBooks(books, n);	// read all books you want
	printBooks(books, n);	// now it's time to print all books
	updateBook(books, n);	// update 1 book data
	//printBook(searchBook(books, n));
	deleteBook(books, n);	// remove a book from the array of books
	printBooks(books, n);
	return 0;
}

/// ---------- READING BOOKS AND PLACING THEM INTO THE ARRAY
void readBooks(book* b, int& n)
{
	string res;
	
	do
	{
		b[n] = readBook();
		n++;
		cout << "Another book entry? Y/y to continue, any other key to leave : ";
		getline(cin,res);
	}while (res == "y" || res == "Y"); 
	/*
	   Remember what I commented about this? I discovered that problem occurs when 
	   I use cin/getchar before getline, it seems something remains in buffer. so I was
	   using cin to stop loop in readBooks, but in readBook which is called inside
	   I was using getline. I found that using only cin or getline fix the problem
	 */
}

/// ------------- READS DATA FOR 1 BOOK, I STORES DATA IN THE STRUCTURE
book readBook()
{	// read a temporary struct and return it
	string data;
	book temp;
	cout << "Book ID : ";
	getline(cin, temp.id);
	cout << "Author : ";
	getline(cin, temp.author);
	cout << "Title : ";
	getline(cin, temp.title);
	cout << "Price : ";
	getline(cin, data); stringstream(data) >> temp.price;

	return temp;
}
/// -------- JUST PRINT A LINE WITH LENGHT SPECIFIED
void drawline(int length)
{
	for (int i = 0; i < length; i++)
		cout << "=";
	cout << endl;
}
// --------- PRINTS ALL BOOKS STORED IN THE ARRAY, 
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
	cout << "\t" "total of books: " << n<<endl;
}
// ----------- PRINTS THE SPECIFIED BOOK
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
// ------- I create this function to use it in update and delete functions
int searchBook(book books[],int n)
{
	string str;
	cout << "Enter book ID: "; getline(cin, str);
	for (int i = 0; i < n; i++)
	{
		if(books[i].id==str)
			return i;
	}
	return -1;
}
// ----- ALLOWS TO UPDATE DATA IN A STORED BOOK
void updateBook(book books[], int n)
{
	string str;
	cout << "UPDATE BOOK INFO" << endl;
	int b = searchBook(books, n);
	if (b>=0)
	{
		printBook(books[b]);
		cout << endl << "Now enter new data for this book: " << endl;
		books[b] = readBook();
		cout << endl << "Book has been updated" << endl;
		printBook(books[b]);

	}
	else
		cout << "BOOK NOT FOUND" << endl;

}
// -------------- FUNCTION DELETE A BOOK
void deleteBook(book books[], int& n)
{
	string str;
	cout << "Want to delete a book? Press n/N to cancel.";
	getline(cin, str);
	if (str == "n" || str == "N")
		return;
	cout << "DELETE BOOK" << endl;
	int b = searchBook(books, n);
	if (b>=0)
	{
		printBook(books[b]);
		cout << "Last chance before DELETION Press n/N to cancel.";
		getline(cin, str);
		if (str == "n" || str == "N")
			return;
		book tmp;
		for (int i = b+1; i < n; i++)
		{
			books[i - 1] = books[i];
		}
		n--;
		cout << "BOOK DELETED ..." << endl;
	}

}