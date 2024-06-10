/*
	MANUEL BISHOP NORIEGA
	STUDENT ID: 4362207
	ASSINGMENT 1
	COMP1014 - Intermediate C++ Programming
*/

#include<iostream>
#include<iomanip>

using namespace std;

// functions to read, multiply and print multidimensional matrices
void readMatrix(int mNum,int**,int cols,int rows); 
void multiply(int**,int**,int**,int r1,int c1r2,int c2);
void printMatrix(int mNum, int**, int cols, int rows);

int main()
{
	// first I need to define mi matrices, because I want to handle any size I'm using pointers
	// to create a bidimensional matrix I use a pointer to another pointer
	// according instrucctions to multiply matrices, I will need at list 3 values for their dimensiones
	// the number for columns in matrix 1 MUST be the same for rows in matrix 2, thats my c1r2 variable
	// then rows for matrix 1 is r1 variable and columns for matrix 2 is r2 variable.
	int **mat1,**mat2,**result,r1,c1r2,c2;
	// now I just ask for matrices dimensions
	cout << "Enter Matrix 1 COLUMNS :";
	cin >> c1r2;
	cout << "Enter Matrix 1 ROWS :";
	cin >> r1;
	cout << "Enter Matrix 2 COLUMNS :";
	cin >> c2;
	cout << "Matrix 2 has as many ROWS as Matrix 1 COLUMNS, that is: " << c1r2<<endl;
	
	// allocating memory for 3 matrices
	mat1 = new int* [r1];
	mat2 = new int* [c1r2];
	result = new int* [r1];

	for (int i = 0; i < r1; i++) // matrx 1
		mat1[i] = new int[c1r2];
	for (int i = 0; i < c1r2; i++) // matrix 2
		mat2[i] = new int[c2];
	for (int i = 0; i < r1; i++)		// matrix result
		result[i] = new int[c2];

	system("pause");
// let's read matrices to multiply
	readMatrix(1,mat1,c1r2,r1);
	readMatrix(2,mat2,c2,c1r2);
// now let's print their values
	printMatrix(1, mat1, c1r2, r1);
	printMatrix(2, mat2, c2, c1r2);

// then, let's show the procedure performed to multiply matrices
	multiply(mat1,mat2,result,r1,c1r2,c2);

// finally let's print resulting matrix
	printMatrix(3, result,c2,r1);
	
	return 0;
}

// THIS FUNCTION READS MATRIX VALUES
// args mNum : to identify matrix, mat is the matrix of integers and cols an rows the dimensions
void readMatrix(int mNum,int**mat,int cols,int rows)
{
	cout <<endl<<endl<< "Enter Matrix "<<mNum<<" values:"<<endl;
	for(int r=0;r<rows;r++)
		for (int c = 0; c < cols; c++)
		{
			cout << "Matrix[" << r << "][" << c << "]: ";
			cin >> *(*(mat + r) + c);
		}
}

// to multiply I pass all matrices to this function, and also all dimensiones required to read an store values
// in result matrix.
void multiply(int** mat1, int** mat2, int** result, int r1, int c1r2, int c2)
{
	cout << "Operations performed to multiply Matrix 1 and Matrix 2\n";
	for (int r=0;r<r1;r++)
	{
		for (int i = 0; i < c2; i++)
		{
			int sum = 0;
			for (int c = 0; c < c1r2; c++)
			{
				if (c != c1r2 - 1)
				{
					cout << *(*(mat1 + r) + c) << "x" << *(*(mat2 + c) + i) << "+";
					sum += (*(*(mat1 + r) + c)) * (*(*(mat2 + c) + i));
				}
				else
				{
					cout << *(*(mat1 + r) + c) << "x" << *(*(mat2 + c) + i);
					sum += (*(*(mat1 + r) + c)) * (*(*(mat2 + c) + i));
				}
				*(*(result + r) + i) = sum;
			}
			cout <<"\t";
		}
		cout << endl;
	}
}
void printMatrix(int mNum,int **mat,int cols,int rows)
{
	if (mNum == 3)
		cout << endl << "Printing Resulting Matrix" << endl;
	else
		cout << endl << "Printing Matrix " << mNum << endl;
	for (int r = 0; r < rows; r++)
	{
		for (int c = 0; c < cols; c++)
			cout << *(*(mat + r) + c) << "\t";
		cout << endl;
	}
	cout << endl;
}