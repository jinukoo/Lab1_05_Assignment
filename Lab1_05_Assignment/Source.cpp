#include <iostream>
#include <fstream>
#include "gaussian_elimination.h"

using namespace std;


int main() {
	double b[MATRIX_SIZE] = { 0.0, 3.0, 6.0, 11.0 };
	double A[MATRIX_SIZE][MATRIX_SIZE];
	double I[MATRIX_SIZE][MATRIX_SIZE] = { {1, 0,0,0}, {0, 1,0,0}, {0, 0,1,0}, {0, 0,0,1} };

	fstream inputStream;
	inputStream.open("Matrix.txt");
	for (int i = 0; i < MATRIX_SIZE; i++)
	{
		for (int j = 0; j < MATRIX_SIZE; j++) inputStream >> A[i][j];
	}
	inputStream.close();

	print(A);
	print(b);
	rref(A, b);
	print(b);
	system("pause");

	return 0;

}