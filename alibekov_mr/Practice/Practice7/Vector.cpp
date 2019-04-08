#include "Vector.h"
#include "iostream"
#include "math.h"

Vector::Vector()
{
  size = 0;
  elements = nullptr;
}

Vector::Vector(int _size)
{
  size = _size;
  elements = new double[size];
  std::cout << "Enter elements: " << std::endl;
  for (int i = 0; i < size; i++) 
    std::cin >> elements[i];
  std::cout << "Vector full" << std::endl;
}

Vector::Vector(int _size, double * _elements)
{
  size = _size;
  elements = new double [size];
  for (int i = 0; i < size; i++) 
    elements[i] = _elements[i];
}

Vector::Vector(const Vector & _vector)
{
  size = _vector.size;
  elements = new double[size];
  for (int i = 0; i < size; i++) 
    elements[i] = _vector.elements[i];
}

Vector::~Vector()
{
  size = 0;
  delete[] elements;
}

Vector Vector::operator+(const Vector & _vector) const
{
  if (size != _vector.size) {
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
  if (size != _vector.size) {
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
  if (size != _vector.size) {
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
  for (int i = 0; i < size; i++) {
    tmp[i] = elements[i] + _d;
  }
  return tmp;
}

Vector Vector::operator-(double _d) const
{
  Vector tmp(*this);
  for (int i = 0; i < size; i++) {
    tmp[i] = elements[i] - _d;
  }
  return tmp;
}

Vector Vector::operator*(double _d) const
{
  Vector tmp(*this);
  for (int i = 0; i < size; i++) {
    tmp[i] = elements[i] * _d;
  }
  return tmp;
}

const Vector & Vector::operator=(const Vector & _vector)
{
  if (this != &_vector) {
    size = _vector.size;
    delete[] elements;
    elements = new double[size];
    for (int i = 0; i < size; i++)
      elements[i] = _vector.elements[i];
  }
  return *this;
}

double & Vector::operator[](int index)
{
  if ((index < 0) || (index > size)) {
    ExceptionOutOfRange e(__LINE__, __FILE__);
    throw e;
  }
  return elements[index];
}

const double & Vector::operator[](int index) const
{
  if ((index < 0) || (index > size)) {
    ExceptionOutOfRange e(__LINE__, __FILE__);
    throw e;
  }
  return elements[index];
}

Vector & Vector::operator+=(double _d)
{
  for (int i = 0; i < size; i++) {
    elements[i] += _d;
  }
  return *this;
}

Vector & Vector::operator-=(double _d)
{
  for (int i = 0; i < size; i++) {
    elements[i] -= _d;
  }
  return *this;
}

Vector & Vector::operator*=(double _d)
{
  for (int i = 0; i < size; i++) {
    elements[i] *= _d;
  }
  return *this;
}

double Vector::Length()
{
  double lengthSquared = 0;
  for (int i = 0; i < size; i++) {
    lengthSquared += (elements[i] * elements[i]);
  }
  return sqrt(lengthSquared);
}

void Vector::Print()
{
  for (int i = 0; i < size; i++) std::cout << "\n" << elements[i]; std::cout << "\n";
}

void * Vector::operator new(size_t _size)
{
  void *pointerToMemory;
  pointerToMemory = malloc(_size);
  if (!pointerToMemory) {
    ExceptionBadAlloc e(__LINE__, __FILE__);
    throw e;
  }
  return pointerToMemory;
}

void Vector::operator delete(void * pointerOfDeletingElement)
{
  free(pointerOfDeletingElement);
}

void * Vector::operator new[](size_t _size)
{
  void *pointerToMemory;
  pointerToMemory = malloc(_size);
  if (!pointerToMemory) {
    ExceptionBadAlloc e(__LINE__, __FILE__);
    throw e;
  }
  return pointerToMemory;
}

void Vector::operator delete[](void * pointerOfDeletingElement)
{
  free(pointerOfDeletingElement);
}

std::ostream & operator<<(std::ostream & out, const Vector & _vector)
{
  out << " (";
  for (int i = 0; i < _vector.size; i++)
    out << " " << _vector[i];
  out << " )" << std::endl;
  return out;
}

std::istream & operator>>(std::istream & in, Vector & _vector)
{
  for (int i = 0; i < _vector.size; i++)
    in >> _vector[i];
  return in;
};
