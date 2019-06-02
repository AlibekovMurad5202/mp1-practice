#ifndef __VECTOR_H__
#define __VECTOR_H__

#include "math.h"
#include <stdlib.h>
#include "iostream" 
#include "MyExceptions.h"

struct Vector
{
private:
    int size;
    double* elements;

public:
    Vector();
    explicit Vector(int _size);
    Vector(int _size, double* _elements);
    Vector(const Vector& _vector);
    ~Vector();

    Vector operator+ (const Vector& _vector) const;
    Vector operator- (const Vector& _vector) const;
    double operator* (const Vector& _vector) const;

    Vector operator+ (double _d) const;
    Vector operator- (double _d) const;
    Vector operator* (double _d) const;

    const Vector& operator= (const Vector& _vector);

    double& operator[] (int index);
    const double& operator[] (int index) const;

    Vector& operator+= (double _d);
    Vector& operator-= (double _d);
    Vector& operator*= (double _d);

    double Length() const;
    void Print() const;

    friend std::ostream& operator<< (std::ostream& out, const Vector& _vector);
    friend std::istream& operator>> (std::istream& in, Vector& _vector);

    void* operator new (size_t _size);
    void operator delete (void* pointerOfDeletingElement);

    void* operator new[](size_t _size);
    void operator delete[](void* pointerOfDeletingElement);
};

#endif // !__VECTOR_H__