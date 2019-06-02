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
    //memset(cells, 0, (sizeof(double) * rows * columns));
}

Matrix::Matrix(int _rows, int _columns, double* _cells)
{
    if ((_rows <= 0) || (_columns <= 0))
    {
        ExceptionNotPositiveDimension e(__LINE__, __FILE__);
        throw e;
    }

    rows = _rows;
    columns = _columns;
    cells = new double[rows * columns];
    //memcpy(cells, _cells, (sizeof(double) * rows * columns));
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
    //memcpy(cells, _matrix.cells, (sizeof(double) * rows * columns));
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
            tmp.cells[(columns * i) + j] += _matrix.cells[(columns * i) + j];
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
            tmp.cells[(columns * i) + j] += d;
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
            tmp.cells[(columns * i) + j] -= _matrix.cells[(columns * i) + j];
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
            tmp.cells[(columns * i) + j] -= d;
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

    if (_matrix.rows != columns)
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

// _      _  
//| 1 5 9  |    
//| 2 6 10 |   
//| 3 7 11 |   
//|_4 8 12_|   
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
            tmp.cells[(columns * i) + j] *= d;
    }
    return tmp;
}

const Matrix& Matrix::operator=(const Matrix & _matrix)
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
        //memcpy(cells, _matrix.cells, sizeof(double) * rows * columns);
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < columns; j++)
                cells[(columns * i) + j] = _matrix.cells[(columns * i) + j];
        }
    }
    return *this;
}

const double* Matrix::operator[](int rowNumber) const
{
    if ((rowNumber < 0) || (rowNumber >= rows))
    {
        ExceptionOutOfRange e(__LINE__, __FILE__);
        throw e;
    }

    return &cells[columns * rowNumber];
}

std::istream& operator>>(std::istream & in, Matrix & _matrix)
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

std::ostream& operator<<(std::ostream & out, Matrix & _matrix)
{
    if ((_matrix.rows == 0) || (_matrix.columns == 0))
    {
        out << "Matrix is empty!\n";
        return out;
    }

    double* dml = new double[_matrix.columns];
    for (int j = 0; j < _matrix.columns; j++)
    {
        double s = 1;
        for (int i = 0; i < _matrix.rows; i++)
        {
            dml[j] = 0;
            double l = (_matrix[i])[j];
            if ((l >= 1) || (l <= -1))
            {
                do {
                    l /= 10;
                    dml[j]++;
                } while ((l >= 1) || (l <= -1));
            }
            else
            {
                do {
                    l *= 10;
                    dml[j]++;
                } while ((l < 1) && (l > -1));
            }

            if (s < dml[j]) s = dml[j];
        }
        dml[j] = s;
    }

    double z = 0;
    for (int i = 0; i < _matrix.columns; i++)
        z += dml[i];

    out << "\n _";
    for (int k = 0; k < _matrix.columns + z - 1; k++)
        out << " ";
    out << "_\n";

    for (int i = 0; i < _matrix.rows - 1; i++)
    {
        out << "| ";
        for (int j = 0; j < _matrix.columns; j++)
        {
            out << (_matrix[i])[j];
            int s = 0;
            double l = (_matrix[i])[j];
            if ((l >= 1) || (l <= -1))
            {
                do {
                    s++;
                    l /= 10;
                } while ((l >= 1) || (l <= -1));
            }
            else
            {
                do {
                    s++;
                    l *= 10;
                } while ((l < 1) && (l > -1));
            }
            for (int f = 0; f < dml[j] - s + 1; f++)
                out << " ";
        }
        out << "|\n";
    }

    out << "|_";
    for (int j = 0; j < _matrix.columns; j++)
    {
        out << (_matrix[_matrix.rows - 1])[j];
        int s = 0;
        double l = (_matrix[_matrix.rows - 1])[j];
        if ((l >= 1) || (l <= -1))
        {
            do {
                s++;
                l /= 10;
            } while ((l >= 1) || (l <= -1));
        }
        else
        {
            do {
                s++;
                l *= 10;
            } while ((l < 1) && (l > -1));
        }
        for (int f = 0; f < dml[j] - s; f++)
            out << " ";
        j != _matrix.columns - 1 ? out << " " : out << "_|\n";
    }
    delete[] dml;

    return out;
}