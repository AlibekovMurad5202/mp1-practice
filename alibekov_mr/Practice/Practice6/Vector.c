#include "Vector.h"
#include "math.h"
#include "stdio.h"
#include "stdlib.h"
#define PI 3.1415926

int CreateVector(int *_n, vector **_vector) 
{
	*_vector = (vector *)malloc(sizeof(vector));
	if (*_n <= 0) {
		printf("Error: Dimension is less than zero!\n");
		return DimensionIsLessThanZero;
	}
	(*_vector)->n = *_n;
	//_vector->n = 3;
	(*_vector)->d = (double *)malloc(sizeof(double) * ((*_vector)->n));
	return ItWorks;
}

int DeleteVector(vector *_vector) 
{
	if (_vector == NULL) {
		printf("Error: Vector is empty!\n");
		return VectorIsEmpty;
	}
	free(_vector->d);
	_vector = 0;
	return ItWorks;
}

int Summation(vector *v1, vector *v2, vector *rezult)
{
	if ((v1 == NULL) || (v2 == NULL)) {
		printf("Error: Vector is empty!\n");
		return VectorIsEmpty;
	}
	int i, _n = v1->n;
	if (v1->n != v2->n) {
		printf("Error: Vectors have different dimensions!\n");
		return DifferentDimensions;
	}
	CreateVector(&_n, &rezult);
	for (i = 0; i < v1->n; i++) {
		(rezult->d)[i] = (v1->d)[i] + (v2->d)[i];
	}
	return ItWorks;
}

int Subtraction(vector *v1, vector *v2, vector *rezult)
{
	if ((v1 == NULL) || (v2 == NULL)) {
		printf("Error: Vector is empty!\n");
		return VectorIsEmpty;
	}
	int i, _n = v1->n;
	if (v1->n != v2->n) {
		printf("Error: Vectors have different dimensions!\n");
		return DifferentDimensions;
	}
	CreateVector(&_n, &rezult);
	for (i = 0; i < v1->n; i++) {
		(rezult->d)[i] = (v1->d)[i] - (v2->d)[i];
	}
	return ItWorks;
}

int Length(vector *_vector, double *_length) 
{
	if (_vector == NULL) {
		printf("Error: Vector is empty!\n");
		return VectorIsEmpty;
	}
	int i, _n = _vector->n;
	//if (_vector->n == 0) return -1;
	double l = 0;
	*_length = 0;
	for (i = 0; i < _n; i++) {
		l += ((_vector->d)[i] * (_vector->d)[i]);
	}
	*_length = sqrt(l);
	return ItWorks;
}

int ScalarProduct(vector *v1, vector *v2, double *_scalarProduct) 
{
	if ((v1 == NULL) || (v2 == NULL)) {
		printf("Error: Vector is empty!\n");
		return VectorIsEmpty;
	}
	int i, _n = v1->n;
	if (v1->n != v2->n) {
		printf("Error: Vectors have different dimensions!\n");
		return DifferentDimensions;
	}
	/*if (_n == 0) {
		printf("Error!");
		return -2;
	}*/
	*_scalarProduct = 0;
	for (i = 0; i < _n; i++) {
		*_scalarProduct += ((v1->d)[i] * (v2->d)[i]);
	}
	return ItWorks;
}

int Angle(vector *v1, vector *v2, double *_rezultInGrad) 
{
	double l1, l2;
	int codeOfError = 0;
	if ((v1 == NULL) || (v2 == NULL)) {
		printf("Error: Vector is empty!\n");
		return VectorIsEmpty;
	}
	codeOfError = Length(v1, &l1);
	if (codeOfError) return codeOfError;
	codeOfError = Length(v2, &l2);
	if (codeOfError) return codeOfError;
	double rezultInRad;
	if ((l1 == 0) || (l2 == 0)) {
		printf("Error: Length of vector is zero!\n");
		return LengthIsZero;
	}	//exit(1);
	double _scalarProduct = 0;
	codeOfError = ScalarProduct(v1, v2, &_scalarProduct);
	if (codeOfError) return codeOfError;
	rezultInRad = acos(_scalarProduct / (l1 * l2));
	*_rezultInGrad = 180 * rezultInRad / PI;
	return ItWorks;
};