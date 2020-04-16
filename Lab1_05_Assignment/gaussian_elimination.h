#pragma once
#define MATRIX_SIZE 4
using namespace std;

void print(const double(&A)[MATRIX_SIZE][MATRIX_SIZE])
{
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);
	for (int i = 0; i < MATRIX_SIZE; i++)
	{
		for (int j = 0; j < MATRIX_SIZE; j++) cout << A[i][j] << "\t";
		cout << endl;
	}
	cout << endl;
}

void print(const double(&b)[MATRIX_SIZE])
{
	/**************
	Implement the code here
	**************/
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);
	for (int i = 0; i < MATRIX_SIZE; i++)
		cout << b[i] << endl;
}

void assign_row(double(&old_row)[MATRIX_SIZE], const double(&new_row)[MATRIX_SIZE]) {
	for (int i = 0; i < MATRIX_SIZE; i++)
	{
		old_row[i] = new_row[i];
	}
}

void elementary_op1(double(&A)[MATRIX_SIZE][MATRIX_SIZE], int row1, int row2) {
	double temp[MATRIX_SIZE];
	assign_row(temp, A[row1]);
	assign_row(A[row1], A[row2]);
	assign_row(A[row2], temp);
}

void elementary_op1(double(&b)[MATRIX_SIZE], int row1, int row2) {
	/**************
	Implement the code here
	**************/
	double temp = b[row1];
	b[row1] = b[row2];
	b[row2] = temp;
}

void elementary_op2(double(&A)[MATRIX_SIZE][MATRIX_SIZE], int row, double a) {
	double temp[MATRIX_SIZE];
	for (int i = 0; i < MATRIX_SIZE; i++) temp[i] = a * A[row][i];
	assign_row(A[row], temp);
}

void elementary_op2(double(&b)[MATRIX_SIZE], int row, double a) {
	/**************
	Implement the code here
	**************/
	b[row] *= a;
}

void elementary_op3(double(&A)[MATRIX_SIZE][MATRIX_SIZE], int row1, int row2, double a) {
	double temp[MATRIX_SIZE];
	for (int i = 0; i < MATRIX_SIZE; i++) temp[i] = A[row1][i] + a * A[row2][i];
	assign_row(A[row1], temp);
}

void elementary_op3(double(&b)[MATRIX_SIZE], int row1, int row2, double a) {
	/**************
	Implement the code here
	**************/
	b[row1] += (b[row2] * a);
}

int where_is_non_zero_row(const double(&A)[MATRIX_SIZE][MATRIX_SIZE], int col) {
	for (int i = col; i < MATRIX_SIZE; i++) {
		if (fabs(A[i][col]) > 0.001) {
			return i;
		}
	}
	return -1;
}

void rref(double(&A)[MATRIX_SIZE][MATRIX_SIZE], double(&B)[MATRIX_SIZE][MATRIX_SIZE]) {
	int base_row;
	double temp;
	for (int i = 0; i < MATRIX_SIZE; i++)
	{
		base_row = where_is_non_zero_row(A, i);
		cout << "non_zero row is " << base_row << endl;
		if (base_row < 0) {
			cout << "The input matrix is not invertible." << endl;
			break;
		}
		else {
			elementary_op1(A, base_row, i);
			elementary_op1(B, base_row, i);
			temp = 1.0 / A[i][i];
			elementary_op2(A, i, temp);
			elementary_op2(B, i, temp);
			for (int j = 0; j < MATRIX_SIZE; j++)
			{
				if (i == j) continue;
				temp = -A[j][i];
				elementary_op3(A, j, i, temp);
				elementary_op3(B, j, i, temp);
			}
		}
	}
}

void rref(double(&A)[MATRIX_SIZE][MATRIX_SIZE], double(&b)[MATRIX_SIZE]) {
	/**************
	Implement the code here
	**************/
	int base_row;
	double temp;
	for (int i = 0; i < MATRIX_SIZE; i++)
	{
		base_row = where_is_non_zero_row(A, i);
	//  cout << "non_zero row is " << base_row << endl;
		if (base_row < 0) {
			cout << "The input matrix is not invertible." << endl;
			break;
		}
		else {
			elementary_op1(A, base_row, i);
			elementary_op1(b, base_row, i);
			temp = 1.0 / A[i][i];
			elementary_op2(A, i, temp);
			elementary_op2(b, i, temp);
			for (int j = 0; j < MATRIX_SIZE; j++)
			{
				if (i == j) continue;
				temp = -A[j][i];
				elementary_op3(A, j, i, temp);
				elementary_op3(b, j, i, temp);
			}
		}
	}
	cout << endl;
}
