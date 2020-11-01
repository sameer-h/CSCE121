// matrix.h
#ifndef MATRIX_H
#define MATRIX_H

#include <initializer_list>

struct Matrix {
  std::size_t rows;
  std::size_t cols;
  int** data;

  // Construct a Matrix from an initializer list
  //   e.g. Matrix A = {{1, 2}, {3, 4}}; (see examples.cpp)
  //   should only be used for testing
  using iList = std::initializer_list<int>;
  using iiList = std::initializer_list<iList>;
  Matrix(iiList l) : rows(l.size()), data(new int*[rows]) {
    std::size_t row = 0;
    for (const iList* r = l.begin(); r != l.end(); ++r, ++row) {
      cols = r->size();
      data[row] = new int[cols];
      std::size_t col = 0;
      for (const int* v = r->begin(); v != r->end(); ++v, ++col) {
        data[row][col] = *v;
      }
    }
  }

  // Destruct a Matrix
  ~Matrix();

  // Matrix access operator: access the specified row of the Matrix
  //   e.g. Matrix A = {{0, 0}, {0, 0}};
  //        A[0][1] = 2;      // set element in row 0, column 1 to value 2
  //        cout << A[0][1];  // print the element in row 0, column 1 
  const int* operator [] (std::size_t row) const { return data[row]; }
  int*& operator [] (std::size_t row) { return data[row]; }
};

Matrix& vertcat(Matrix &, Matrix const&);

#endif  // MATRIX_H