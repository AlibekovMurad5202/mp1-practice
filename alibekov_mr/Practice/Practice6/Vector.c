#include "Vector.h"
#include "math.h"
#include "stdio.h"
#include "stdlib.h"
#define PI acos(-1.)

int CreateVector(int* _n, vector** _vector)
{
    *_vector = (vector*)malloc(sizeof(vector));
    if (*_n <= 0)
    {
        printf("Error: Dimension is or less than zero! ");
        return DimensionIsOrLessThanZero;
    }
    (*_vector)->n = *_n;
    (*_vector)->d = (double*)malloc(sizeof(double) * ((*_vector)->n));
    return ItWorks;
}

void DeleteVector(vector* _vector)
{
    if (_vector != NULL)
    {
        free(_vector->d);
        _vector->n = 0;
        free(_vector);
    }
}

int Addition(vector* v1, vector* v2, vector** rezult)
{
    if ((v1 == NULL) || (v2 == NULL))
    {
        printf("Error: Vector is empty! ");
        return VectorIsEmpty;
    }

    int i, _n = v1->n;

    if (v1->n != v2->n)
    {
        printf("Error: Vectors have different dimensions! ");
        return DifferentDimensions;
    }
    DeleteVector(*rezult);
    CreateVector(&_n, rezult);
    for (i = 0; i < v1->n; i++)
        ((*rezult)->d)[i] = (v1->d)[i] + (v2->d)[i];
    return ItWorks;
}

int Subtraction(vector * v1, vector * v2, vector * *rezult)
{
    if ((v1 == NULL) || (v2 == NULL))
    {
        printf("Error: Vector is empty! ");
        return VectorIsEmpty;
    }

    int i, _n = v1->n;

    if (v1->n != v2->n)
    {
        printf("Error: Vectors have different dimensions! ");
        return DifferentDimensions;
    }
    DeleteVector(*rezult);
    CreateVector(&_n, rezult);
    for (i = 0; i < v1->n; i++)
        ((*rezult)->d)[i] = (v1->d)[i] - (v2->d)[i];
    return ItWorks;
}

int Length(vector * _vector, double* _length)
{
    if (_vector == NULL)
    {
        printf("Error: Vector is empty! ");
        return VectorIsEmpty;
    }

    double l = 0;
    *_length = 0;
    int i, _n = _vector->n;

    for (i = 0; i < _n; i++)
        l += ((_vector->d)[i] * (_vector->d)[i]);
    *_length = sqrt(l);
    return ItWorks;
}

int ScalarProduct(vector * v1, vector * v2, double* _scalarProduct)
{
    if ((v1 == NULL) || (v2 == NULL))
    {
        printf("Error: Vector is empty! ");
        return VectorIsEmpty;
    }

    int i, _n = v1->n;
    *_scalarProduct = 0;

    if (v1->n != v2->n)
    {
        printf("Error: Vectors have different dimensions! ");
        return DifferentDimensions;
    }
    for (i = 0; i < _n; i++)
        * _scalarProduct += ((v1->d)[i] * (v2->d)[i]);
    return ItWorks;
}

int Angle(vector * v1, vector * v2, double* _rezultInGrad)
{
    if ((v1 == NULL) || (v2 == NULL))
    {
        printf("Error: Vector is empty! ");
        return VectorIsEmpty;
    }

    double l1, l2;
    int codeOfError = 0;
    double rezultInRad;
    double _scalarProduct = 0;

    codeOfError = Length(v1, &l1);
    if (codeOfError) return codeOfError;
    codeOfError = Length(v2, &l2);
    if (codeOfError) return codeOfError;
    if ((l1 == 0) || (l2 == 0))
    {
        printf("Error: Length of vector is zero! ");
        return LengthIsZero;
    }
    codeOfError = ScalarProduct(v1, v2, &_scalarProduct);
    if (codeOfError) return codeOfError;
    rezultInRad = acos(_scalarProduct / (l1 * l2));
    *_rezultInGrad = 180 * rezultInRad / PI;
    return ItWorks;
};
