#include <iostream>
using namespace std;


float a[2];
float b[2];
float m[2];
float c1;
float c2;
float x;
char operatorA;
char operatorB;
char variable;
char equals = '=';

struct vec {
	char name;
	float x;
	float y;
};

struct vec enter_vector(struct vec Vector)
{
	cout << "Enter the two components of vector " << Vector.name << ", separated by spaces: ";
	cin >> Vector.x >> Vector.y;

	cout << "\nYou entered [" << Vector.x << ", " << Vector.y << "]" << endl;
	return Vector;
}

void display_vector(struct vec Vector)
{
	cout << Vector.name << " = " << "[" << Vector.x << ", " << Vector.y << "]" << endl;
}



void linear_combination_calc() {
	struct vec M;
	struct vec A;
	struct vec B;

	M.name = 'M';
	A.name = 'A';
	B.name = 'B';

	cout << "A vector M is a linear combination if it is the sum of vectors A and B, scaled by some scalars C1 and C2." << endl;
	M = enter_vector(M);
	A = enter_vector(A);
	B = enter_vector(B);
	
	
	display_vector(M);
	display_vector(A);
	display_vector(B);
	
	// create the coefficient matrix & the solution "vector"
	float matMain[2][2];
	struct vec X;

	// populate the matrix
	matMain[0][0] = A.x;
	matMain[0][1] = B.x;
	matMain[1][0] = A.y;
	matMain[1][1] = B.y;

	// calculate the inverse of matMain
	float determinant;
	float matInverse[2][2];
	float inv_determinant;


	determinant = (matMain[0][0]*matMain[1][1]) - (matMain[1][0]*matMain[0][1]);

	// Not a linear combination
	if (determinant == 0)
	{
	   cout << "The vector M is NOT a linear combination of A and B." << endl;
	}
	else
	{
	   inv_determinant = 1/determinant;
	   matInverse[0][0] = inv_determinant*matMain[1][1];
	   matInverse[0][1] = (-1)*inv_determinant*matMain[1][0];
	   matInverse[1][0] = (-1)*inv_determinant*matMain[0][1];
	   matInverse[1][1] = inv_determinant*matMain[0][0];

	   // do matrix multiplication of inverse with the vector M
	   X.x = (matInverse[0][0]*M.x) + (matInverse[0][1]*M.y);
	   X.y = (matInverse[1][0]*M.x) + (matInverse[1][1]*M.y);



	   // output the result
	   cout << "The coefficients that make M a linear combination of A and B are " << X.x << " and " << X.y << "." << endl;
	}
}


int main() {

	linear_combination_calc();
	return 0;
}
