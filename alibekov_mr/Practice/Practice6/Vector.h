#ifndef __VECTOR_H__
#define __VECTOR_H__

typedef struct {
	int n;
	double *d;
} vector;

enum Errors
{
	ItWorks,                    //0
	DifferentDimensions,        //1
	DimensionIsOrLessThanZero,  //2
	VectorIsEmpty,              //3
	LengthIsZero                //4
};


int CreateVector(int *_n, vector **_vector);

void DeleteVector(vector *_vector);

int Addition(vector *v1, vector *v2, vector **rezult);

int Subtraction(vector *v1, vector *v2, vector **rezult);

int Length(vector *_vector, double *_length);

int ScalarProduct(vector *v1, vector *v2, double *_scalarProduct);

int Angle(vector *v1, vector *v2, double *_rezultInGrad);

#endif // !__VECTOR_H__