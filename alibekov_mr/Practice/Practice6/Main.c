#include "Vector.h"
#include "stdio.h"

void main() {
	vector *_vector;
	int count;
	int numberOfError;
	scanf("%d", &count);
	numberOfError = CreateVector(count, _vector);
}