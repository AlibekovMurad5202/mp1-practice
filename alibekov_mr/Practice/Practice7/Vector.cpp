#include "Vector.h"

Vector::Vector()
{
    size = 0;
    elements = nullptr;
}

Vector::Vector(int _size)
{
    if (_size <= 0)
    {
        ExceptionNotPositiveDimension e(__LINE__, __FILE__);
        throw e;
    }

    size = _size;
    elements = new double[size];
    memset(elements, 0, (sizeof(double) * size));
}

Vector::Vector(int _size, double* _elements)
{
    if (_size <= 0)
    {
        ExceptionNotPositiveDimension e(__LINE__, __FILE__);
        throw e;
    }

    size = _size;
    elements = new double[size];
    memcpy(elements, _elements, (sizeof(double) * size));
}

Vector::Vector(const Vector & _vector)
{
    if (_vector.size == 0)
    {
        ExceptionEmptyVector e(__LINE__, __FILE__);
        throw e;
    }

    size = _vector.size;
    elements = new double[size];
    memcpy(elements, _vector.elements, (sizeof(double) * size));
}

Vector::~Vector()
{
    size = 0;
    delete[] elements;
}

Vector Vector::operator+(const Vector & _vector) const
{
    if (_vector.size == 0)
    {
        ExceptionEmptyVector e(__LINE__, __FILE__);
        throw e;
    }

    if (size != _vector.size)
    {
        ExceptionDifferentDimensions e(__LINE__, __FILE__);
        throw e;
    }

    Vector tmp(*this);
    for (int i = 0; i < size; i++)
        tmp[i] += _vector[i];
    return tmp;
}

Vector Vector::operator-(const Vector & _vector) const
{
    if (_vector.size == 0)
    {
        ExceptionEmptyVector e(__LINE__, __FILE__);
        throw e;
    }

    if (size != _vector.size)
    {
        ExceptionDifferentDimensions e(__LINE__, __FILE__);
        throw e;
    }

    Vector tmp(*this);
    for (int i = 0; i < size; i++)
        tmp[i] -= _vector[i];
    return tmp;
}

double Vector::operator*(const Vector & _vector) const
{
    if (_vector.size == 0)
    {
        ExceptionEmptyVector e(__LINE__, __FILE__);
        throw e;
    }

    if (size != _vector.size)
    {
        ExceptionDifferentDimensions e(__LINE__, __FILE__);
        throw e;
    }

    double scalarProduct = 0;
    for (int i = 0; i < size; i++)
        scalarProduct += elements[i] * _vector[i];
    return scalarProduct;
}

Vector Vector::operator+(double _d) const
{
    Vector tmp(*this);
    for (int i = 0; i < size; i++)
    {
        tmp[i] = elements[i] + _d;
    }
    return tmp;
}

Vector Vector::operator-(double _d) const
{
    Vector tmp(*this);
    for (int i = 0; i < size; i++)
    {
        tmp[i] = elements[i] - _d;
    }
    return tmp;
}

Vector Vector::operator*(double _d) const
{
    Vector tmp(*this);
    for (int i = 0; i < size; i++)
    {
        tmp[i] = elements[i] * _d;
    }
    return tmp;
}

const Vector& Vector::operator=(const Vector & _vector)
{
    if (_vector.size == 0)
    {
        ExceptionEmptyVector e(__LINE__, __FILE__);
        throw e;
    }

    if (this != &_vector)
    {
        size = _vector.size;
        delete[] elements;
        elements = new double[size];
        memcpy(elements, _vector.elements, (sizeof(double) * size));
    }
    return *this;
}

double& Vector::operator[](int index)
{
    if ((index < 0) || (index > size))
    {
        ExceptionOutOfRange e(__LINE__, __FILE__);
        throw e;
    }

    return elements[index];
}

const double& Vector::operator[](int index) const
{
    if ((index < 0) || (index > size))
    {
        ExceptionOutOfRange e(__LINE__, __FILE__);
        throw e;
    }

    return elements[index];
}

Vector& Vector::operator+=(double _d)
{
    for (int i = 0; i < size; i++)
        elements[i] += _d;
    return *this;
}

Vector& Vector::operator-=(double _d)
{
    for (int i = 0; i < size; i++)
        elements[i] -= _d;
    return *this;
}

Vector& Vector::operator*=(double _d)
{
    for (int i = 0; i < size; i++)
        elements[i] *= _d;
    return *this;
}

double Vector::Length() const
{
    return sqrt((*this) * (*this));
}

void* Vector::operator new(size_t _size)
{
    // For "operator new" the size of the object (_size)  
    // is calculated and passed to the function automatically.

    void* pointerToMemory;
    pointerToMemory = malloc(_size);

    if (!pointerToMemory)
    {
        ExceptionBadAlloc e(__LINE__, __FILE__);
        throw e;
    }

    return pointerToMemory;
}

void Vector::operator delete(void* pointerOfDeletingElement)
{
    free(pointerOfDeletingElement);
}

void* Vector::operator new[](size_t _size)
{
    if (_size <= 0)
    {
        ExceptionOutOfRange e(__LINE__, __FILE__);
        throw e;
    }

    void* pointerToMemory;
    pointerToMemory = malloc(_size);

    if (!pointerToMemory)
    {
        ExceptionBadAlloc e(__LINE__, __FILE__);
        throw e;
    }

    return pointerToMemory;
}

void Vector::operator delete[](void* pointerOfDeletingElement)
{
    free(pointerOfDeletingElement);
}

std::ostream& operator<<(std::ostream & out, const Vector & _vector)
{
    if (_vector.size == 0)
        return out;
    out << " (";
    for (int i = 0; i < _vector.size; i++)
        out << " " << _vector[i];
    out << " )" << std::endl;
    return out;
}

std::istream& operator>>(std::istream & in, Vector & _vector)
{
    std::cout << "Enter elements: " << std::endl;
    for (int i = 0; i < _vector.size; i++)
        in >> _vector[i];
    return in;
};