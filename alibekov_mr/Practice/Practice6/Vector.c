#include "Vector.h"
#include <math.h>
#define PI 3.1415926

int CreateVector(int _n, vector *_vector) {
	//vector *pv;
	if (_n <= 0) {
		printf("Error");
		return -1;
	}
	_vector->n = _n;
	_vector->d = (double *)malloc(sizeof(double) * _n);
	return 0;
}

void DeleteVector(vector *_vector) {
	free(_vector->d);
	_vector = 0;
}

int Summ(vector *v1, vector *v2, vector *rezult){
	int i, _n = v1->n;
	if (v1->n != v2->n) {
		printf("Error!");
		return -1;
	}
	CreateVector(_n, rezult);
	for (i = 0; i < v1->n; i++) {
		(rezult->d)[i] = (v1->d)[i] + (v2->d)[i];
	}
	return 0;
}

double Length(vector *_vector) {
	int _n = _vector->n;
	if (_vector->n == 0) return -1;
	int i, l = 0, length = 0;
	for (i = 0; i < _n; i++) {
		l += ((_vector->d)[i] * (_vector->d)[i]);
	}
	length = sqrt(l);
	return length;
}

double multiplicate(vector *v1, vector *v2){
	int i, _n = v1->n, rezult = 0;
	if (v1->n != v2->n) {
		printf("Error!");
		return -1;
	}
	/*if (_n == 0) {
		printf("Error!");
		return -2;
	}*/
	for (i = 0; i < _n; i++) {
		rezult += ((v1->d)[i] * (v2->d)[i]);
	}
	return rezult;
}

double angle(vector *v1, vector *v2) {
	double l1 = Length(v1);
	double l2 = Length(v2);
	double rezultInGrad, rezultInRad;
	if ((l1 == 0) || (l2 == 0)) {
		printf("Error");
		//exit(1);
	rezultInRad = acos(multiplicate(v1, v2) / (l1 * l2));
	rezultInGrad = 180 * rezultInRad / PI;
	return rezultInGrad;
};