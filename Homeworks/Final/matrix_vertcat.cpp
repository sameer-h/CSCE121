// matrix_vertcat.cpp
#include <iostream>
#include <stdexcept>
#include "./matrix.h"

using std::cout, std::endl;
using std::invalid_argument;
using std::size_t;

// vertically concatenate B to A (A on top of B)
// throws an invalid_argument exception on mismatched dimensions
// side effects:
//   A is reallocated to be bigger


Matrix& vertcat(Matrix& A, Matrix const& B) {
  // TODO(student) : vertcat


// from struct matrix

if(A.cols != B.cols) { // same cols to concat
    throw invalid_argument("A columns and B columns not equal sizes");
}

int A_rows = A.rows;

int B_rows = B.rows;

int totRows = A.rows + B.rows;

int columns = B.cols;

int** nData = A.data; // copy

A.data = new int*[totRows];

for(size_t rw = 0; rw < totRows; rw++) { // iterate through
    A[rw] = new int[columns];
    for(size_t cols = 0; cols < columns; cols++) { 
        A[rw][cols] = 0; // setting vals
    }

}

for(size_t rws = 0; rws < A_rows; rws++) {  // copy data
    for(size_t cls = 0; cls < columns; cls++) {
        A[rws][cls] = nData[rws][cls];
    }
}

for (size_t rws = A_rows; rws < totRows; ++rws) {
    for(size_t cls = 0; cls < columns; cls++) {
        A[rws][cls] = B[rws - A_rows][cls];  // values B on A
    }
}

for(size_t a = 0; a < A_rows; a++) {
    delete[] nData[a];
}

delete[] nData;

A_rows = A_rows + B_rows;
columns = 0;

  return A;
}

Matrix::~Matrix() {
  // TODO(student): destructor

for(size_t rws = 0; rws < rows; rws++) {  // delete the data from rows and cols
    for(size_t cls = 0; cls < cols; cols++) {
        delete[] &data[rws][cls];
    }
  }
  delete[] data;  // making sure no memory leak
}