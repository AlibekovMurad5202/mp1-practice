#include "Matrix.h"

Matrix::Matrix()
{
  rows = 0;
  columns = 0;
  
  cells = nullptr;
}

Matrix::Matrix(int _rows, int _columns)
{
  if ((_rows <= 0) || (_columns <= 0))  
  {
    ExceptionNotPositiveDimension e(__LINE__, __FILE__);
    throw e;
  }

  rows = _rows;
  columns = _columns;
  cells = new double[rows * columns];
}

Matrix::Matrix(int _rows, int _columns, double * _cells)
{
  if ((_rows <= 0) || (_columns <= 0))
  {
    ExceptionNotPositiveDimension e(__LINE__, __FILE__);
    throw e;
  }

  rows = _rows;
  columns = _columns;
  cells = new double[rows * columns];
  for (int i = 0; i < rows; i++)
  {
    for (int j = 0; j < columns; j++)
      cells[(columns * i) + j] = _cells[(columns * i) + j];
  }
}

Matrix::Matrix(const Matrix & _matrix)
{
  if ((_matrix.rows == 0) || (_matrix.columns == 0))
  {
    ExceptionEmptyMatrix e(__LINE__, __FILE__);
    throw e;
  }

  rows = _matrix.rows;
  columns = _matrix.columns;
  cells = new double[rows * columns];
  for (int i = 0; i < rows; i++)
  {
    for (int j = 0; j < columns; j++)
      cells[(columns * i) + j] = _matrix.cells[(columns * i) + j];
  }
}

Matrix::~Matrix()
{
  rows = 0;
  columns = 0;
  delete[] cells;
}

Matrix Matrix::operator+(const Matrix & _matrix) const
{
  if (!rows || !columns)
  {
    ExceptionEmptyMatrix e(__LINE__, __FILE__);
    throw e;
  }
  if ((rows != _matrix.rows) || (columns != _matrix.columns))
  {
    ExceptionDifferentDimensions e(__LINE__, __FILE__);
    throw e;
  }

  Matrix tmp(*this);
  for (int i = 0; i < rows; i++)
  {
    for (int j = 0; j < columns; j++)
      cells[(columns * i) + j] += _matrix.cells[(columns * i) + j];
  }
  return tmp;
}

Matrix Matrix::operator+(double d) const
{
  if ((rows == 0) || (columns == 0))
  {
    ExceptionEmptyMatrix e(__LINE__, __FILE__);
    throw e;
  }

  Matrix tmp(*this);
  for (int i = 0; i < rows; i++)
  {
    for (int j = 0; j < columns; j++)
      cells[(columns * i) + j] += d;
  }
  return tmp;
}

Matrix Matrix::operator-(const Matrix & _matrix) const
{
  if (!rows || !columns)
  {
    ExceptionEmptyMatrix e(__LINE__, __FILE__);
    throw e;
  }
  if ((rows != _matrix.rows) || (columns != _matrix.columns))
  {
    ExceptionDifferentDimensions e(__LINE__, __FILE__);
    throw e;
  }

  Matrix tmp(*this);
  for (int i = 0; i < rows; i++)
  {
    for (int j = 0; j < columns; j++)
      cells[(columns * i) + j] -= _matrix.cells[(columns * i) + j];
  }
  return tmp;
}

Matrix Matrix::operator-(double d) const
{
  if ((rows == 0) || (columns == 0))
  {
    ExceptionEmptyMatrix e(__LINE__, __FILE__);
    throw e;
  }

  Matrix tmp(*this);
  for (int i = 0; i < rows; i++)
  {
    for (int j = 0; j < columns; j++)
      cells[(columns * i) + j] -= d;
  }
  return tmp;
}
                                                              
Matrix Matrix::operator*(const Matrix & _matrix) const        
{                                                            
  if (!_matrix.rows || !_matrix.columns || !rows || !columns)
  {
    ExceptionEmptyMatrix e(__LINE__, __FILE__);
    throw e;
  }
  if ((_matrix.rows != rows) || (_matrix.columns != columns))
  {
    ExceptionUndefinedMultiplication e(__LINE__, __FILE__);
    throw e;
  }

  Matrix tmp(rows, _matrix.columns);
  for (int j = 0; j < tmp.columns; j++)
  {
    for (int i = 0; i < tmp.rows; i++)
    {
      double dotProductOfRowOfTheFirstMatrixAndColumnOfTheSecondMatrix = 0;
      for (int k = 0; k < columns; k++)
      {
        dotProductOfRowOfTheFirstMatrixAndColumnOfTheSecondMatrix +=
          cells[(columns * i) + k] * _matrix.cells[(_matrix.columns * k) + j];
      }
      tmp.cells[(tmp.columns * i) + j] = dotProductOfRowOfTheFirstMatrixAndColumnOfTheSecondMatrix;
    }
  }
  return tmp;
}

// _   _  
//| 1 5 |
//| 2 6 | 
//| 3 7 | 
//|_4 8_|
//
// 1, 2, ... - the order of finding the values 
// of elements of resulting matrix

Matrix Matrix::operator*(double d) const
{
  if ((rows == 0) || (columns == 0))
  {
    ExceptionEmptyMatrix e(__LINE__, __FILE__);
    throw e;
  }

  Matrix tmp(*this);
  for (int i = 0; i < rows; i++)
  {
    for (int j = 0; j < columns; j++)
      cells[(columns * i) + j] *= d;
  }
  return tmp;
}

const Matrix & Matrix::operator=(const Matrix & _matrix)
{
  if ((_matrix.columns == 0) || (_matrix.rows == 0))
  {
    ExceptionEmptyMatrix e(__LINE__, __FILE__);
    throw e;
  }

  if (this != &_matrix)
  {
    rows = _matrix.rows;
    columns = _matrix.columns;
    delete[] cells;
    cells = new double[rows * columns];
    for (int i = 0; i < rows; i++)
    {
      for (int j = 0; j < columns; j++)
        cells[(columns * i) + j] = _matrix.cells[(columns * i) + j];
    }
  }
  return *this;
}

const double * Matrix::operator[](int rowNumber) const
{
  if ((rowNumber < 0) || (rowNumber >= rows))
  {
    ExceptionOutOfRange e(__LINE__, __FILE__);
    throw e;
  }

  return &cells[columns * rowNumber];
}

std::istream & operator>>(std::istream & in, Matrix & _matrix)
{
  for (int j = 0; j < _matrix.columns; j++)
  {
    std::cout << "\nEnter column #" << j + 1 << ":\n";
    for (int i = 0; i < _matrix.rows; i++)
      std::cin >> _matrix.cells[(_matrix.columns * i) + j];
  }
  std::cout << "Matrix full" << std::endl;
  return in;
}

std::ostream & operator<<(std::ostream & out, Matrix & _matrix)
{
  if ((_matrix.rows == 0) || (_matrix.columns == 0) || (_matrix.cells == nullptr))
  {
    out << "Matrix is empty!\n";
    return out;
  }

  out << "\n _";
  for (int k = 0; k < 2 * _matrix.columns - 1; k++)
    out << " ";
  out << "_\n";

  for (int i = 0; i < _matrix.rows - 1; i++)
  {
    out << "| ";
    for (int j = 0; j < _matrix.columns; j++)
      out << (_matrix[i])[j] << " ";
    out << "|\n";
  }

  out << "|_";
  for (int j = 0; j < _matrix.columns; j++)
  {
    out << (_matrix[_matrix.rows - 1])[j];
    j != _matrix.columns - 1 ? out << " " : out << "_|\n";
  }

  return out;
}
/*
double * findMaxLengths (const Matrix & _matrix, double * dml)
{
  for (int i = 0; i < _matrix.rows; i++)
  {
    int s = 1;
    for (int j = 0; j < _matrix.columns; j++)
    {

    }
  }
  
}*/;
