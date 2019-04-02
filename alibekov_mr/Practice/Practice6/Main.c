#include "Vector.h"
#include "stdio.h"
 
void main()
{
	vector *_vector1 = NULL;
	vector *_vector2 = NULL;
	vector *_vector3 = NULL;
	vector *v_rezult = NULL;

	int count1 = 0, count2 = 0, count3 = count2, i;
	double _rezult = 0;

	/* Creating */
	{
		printf("Demension of the first vector: ");
		scanf("%d", &count1);
		if (CreateVector(&count1, &_vector1)) { system("pause"); return; }

		printf("Demension of the second and the third vectors: ");
		scanf("%d", &count2);
		if (CreateVector(&count2, &_vector2)) { system("pause"); return; }

		count3 = count2;
		if (CreateVector(&count3, &_vector3)) { system("pause"); return; }
	}

	printf("Enter the first vector: \n");
	for (i = 0; i < count1; i++) scanf("%lf", &(_vector1->d)[i]);
	printf("Enter the second vector: \n");
	for (i = 0; i < count2; i++) scanf("%lf", &(_vector2->d)[i]);
	printf("Enter the third vector: \n");
	for (i = 0; i < count3; i++) scanf("%lf", &(_vector3->d)[i]);
	
	printf("\nThe first vector: (");
	for (i = 0; i < _vector1->n; i++) printf(" %lf", (_vector1->d)[i]);
	printf(" )\n");

	printf("The second vector: (");
	for (i = 0; i < _vector2->n; i++) printf(" %lf", (_vector2->d)[i]);
	printf(" )\n");

	printf("The third vector: (");
	for (i = 0; i < _vector3->n; i++) printf(" %lf", (_vector3->d)[i]);
	printf(" )\n\n");

	/* Angles */
	{
		if (Angle(_vector1, _vector2, &_rezult))
			printf("That's why angle between the first and the second vectors cann't be found!\n");
		else printf("Angle between the first and the second vectors: %lf\n", _rezult);

		if (Angle(_vector2, _vector3, &_rezult))
			printf("That's why angle between the second and the third vectors cann't be found!\n");
		else printf("Angle between the second and the third vectors: %lf\n", _rezult);

		if (Angle(_vector1, _vector3, &_rezult))
			printf("That's why angle between the first and the third vectors cann't be found!\n\n");
		else printf("Angle between the first and the third vectors: %lf\n\n", _rezult);
	}   

	/* ScalarProducts */
	{
		if (ScalarProduct(_vector1, _vector2, &_rezult))
			printf("That's why scalar product between the first and the second vectors cann't be found!\n");
		else printf("ScalarProduct between the first and the second vectors: %lf\n", _rezult);

		if (ScalarProduct(_vector2, _vector3, &_rezult))
			printf("That's why scalar product between the second and the third vectors cann't be found!\n");
		else printf("ScalarProduct between the second and the third vectors: %lf\n", _rezult);

		if (ScalarProduct(_vector1, _vector3, &_rezult))
			printf("That's why scalar product between the first and the third vectors cann't be found!\n\n");
		else printf("ScalarProduct between the first and the third vectors: %lf\n\n", _rezult);
	}

	/* Lengths */
	{
		if (Length(_vector1, &_rezult))
			printf("That's why length of the first vector cann't be found!\n");
		else printf("Length of the first vector: %lf\n", _rezult);

		if (Length(_vector2, &_rezult))
			printf("That's why length of the second vector cann't be found!\n");
		else printf("Length of the second vector: %lf\n", _rezult);

		if (Length(_vector3, &_rezult))
			printf("That's why length of the third vector cann't be found!\n\n");
		else printf("Length of the third vector: %lf\n\n", _rezult);
	}

	/* Additions */
	{
		if (Addition(_vector1, _vector2, &v_rezult))
			printf("That's why summation of the first and the second vectors cann't be found!\n");
		else {
			printf("Summation of the first and the second vectors: (");
			for (i = 0; i < v_rezult->n; i++) printf(" %lf", (v_rezult->d)[i]);
			printf(" )\n");
		}

		if (Addition(_vector1, _vector3, &v_rezult))
			printf("That's why summation of the first and the third vectors cann't be found!\n");
		else {
			printf("Summation of the first and the third vectors: (");
			for (i = 0; i < v_rezult->n; i++) printf(" %lf", (v_rezult->d)[i]);
			printf(" )\n");
		}

		if (Addition(_vector2, _vector3, &v_rezult))
			printf("That's why summation of the second and the third vectors cann't be found!\n\n");
		else {
			printf("Summation of the second and the third vectors: (");
			for (i = 0; i < v_rezult->n; i++) printf(" %lf", (v_rezult->d)[i]);
			printf(" )\n\n");
		}
	}

	/* Subtractions */
	{
		if (Subtraction(_vector1, _vector2, &v_rezult))
			printf("Subtraction of the first and the second vectors cann't be found!\n");
		else {
			printf("Subtraction of the first and the second vectors: (");
			for (i = 0; i < v_rezult->n; i++) printf(" %lf", (v_rezult->d)[i]);
			printf(" )\n");
		}
		
		if (Subtraction(_vector1, _vector3, &v_rezult))
			printf("Subtraction of the first and the third vectors cann't be found!\n");
		else {
			printf("Subtraction of the first and the third vectors: (");
			for (i = 0; i < v_rezult->n; i++) printf(" %lf", (v_rezult->d)[i]);
			printf(" )\n");
		}
		
		if (Subtraction(_vector2, _vector3, &v_rezult))
			printf("Subtraction of the second and the third vectors cann't be found!\n\n");
		else {
			printf("Subtraction of the second and the third vectors: (");
			for (i = 0; i < v_rezult->n; i++) printf(" %lf", (v_rezult->d)[i]);
			printf(" )\n\n");
		}
	}

	/* Deleting */
	{
		DeleteVector(_vector1);
		DeleteVector(_vector2);
		DeleteVector(_vector3);
		DeleteVector(v_rezult);
	}

	system("pause");
}