#pragma once
typedef struct {
	int n;
	double *d;
} vector;

int CreateVector(int _n, vector *_vector);
void DeleteVector(vector *_vector);
int Summ(vector *v1, vector *v2, vector *rezult);
double Length(vector *_vector);
double multiplicate(vector *v1, vector *v2);
double angle(vector *v1, vector *v2);