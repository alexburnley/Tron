#ifndef MATRIX_H
#define MATRIX_H

#include <stdio.h>
#include "Vector.h"

class Matrix {
private:
	double vals[3][3]; // Row, column

public:
	Matrix( double a00, double a01, double a02, double a10, double a11, double a12, double a20, double a21, double a22 );
	double get( int i, int j ); // Get row, column
	void set( int i, int j, int n ); // Set vals[i][j] = n
	Matrix inverse(); // Calculate inverse of matrix
	Vector mult( Vector vec ); // Multiply matrix by a vector to produce a vector
};

#endif