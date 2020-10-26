/*
DADA function declarations
*/

#ifndef DADA_H
#define DADA_H

/*
Find the element with the maximum absolute value.
Input:
	x : vector (as array of doubles)
	len : number of elements in x (dimension)
Output: index of the first element with maximum absolute value
Errors: returns -1 if vector is empty (len = 0)
*/
int amax(
    const double x[], 
    const unsigned int len);

/*
Sum the absolute values.
Input:
	x : vector (as array of doubles)
	len : number of elements in x (dimension)
Output: sum of the absolute values of the elements.
*/
double asum(
    const double x[], 
    const unsigned int len);

/*
Generalized vector addition (afine transformation)
Input:
	a : scalar value
	x : vector (as an array of doubles)
	y : vector (as an array of doubles)
	len : number of elements in x and y (dimension, assumed equal)
Output: None.  y is updated as y = a*x + y
*/
void axpy(
    const double a, 
    const double x[], 
    double y[], 
    const unsigned int len);

/*
Copy a vector.
Input:
	x : source vector (as an array of doubles)
	y : destination vector (as array of doubles)
	len : number of elements in x and y (dimension, assumed equal)
Output: None. y is updated as y = x
*/
void copy(
    const double x[], 
    double y[], 
    const unsigned int len);

/*
Dot (inner) product of two vectors.
Input:
	x : vector (as an array of doubles)
	y : vector (as an array of doubles)
	len : number of elements of x and y (dimension, assumed to be equal)
Output: dot (inner) product of x and y: x . y
*/
double dot(
    const double x[], 
    const double y[], 
    const unsigned int len);

/*
Euclidean norm of a vector.
Input:
	x : vector (as an array of doubles)
	len : number of elements of x (dimension)
Output: magnitude (length) of x as the distance from the origin to x (as a point)
*/
double norm2(
    const double x[],
    const unsigned int len);

/*
Scale a vector.
Input:
	a : scalar value
	x : vector (as an array of doubles)
	len : number of elements in x (dimension)
Output: None. x is scaled by a: x = a*x;
*/
void scale(
    const double a,
    double x[], 
    const unsigned int len);

/*
Swap two vectors.
Input:
	x : vector (as an array of doubles)
	y : vector (as an array of doubles)
	len : number of elements in x and y (dimension, assumed to be equal)
Output: None. x and y are updated as x,y = y,x
*/
void swap(
    double x[], 
    double y[], 
    const unsigned int len);

#endif