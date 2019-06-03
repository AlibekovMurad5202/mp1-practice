#ifndef __MATRIX__H__
#define __MATRIX__H__

#include "iostream"
#include "MyExceptions.h"

class Matrix
{
private:
    int rows, columns;
    double* cells;

public:
    Matrix();
    Matrix(int _rows, int _columns);
    Matrix(int _rows, int _columns, double* _cells);
    Matrix(const Matrix& _matrix);
    ~Matrix();

    Matrix operator+ (const Matrix& _matrix) const;
    Matrix operator+ (double d) const;
    Matrix operator- (const Matrix& _matrix) const;
    Matrix operator- (double d) const;
    Matrix operator* (const Matrix& _matrix) const;
    Matrix operator* (double d) const;

    const Matrix& operator= (const Matrix& _matrix);

    const double* operator[] (int numberOfRows) const;

    friend std::istream& operator>> (std::istream& in, Matrix& _matrix);
    friend std::ostream& operator<< (std::ostream& out, Matrix& _matrix);
};

#endif // !__MATRIX__H__