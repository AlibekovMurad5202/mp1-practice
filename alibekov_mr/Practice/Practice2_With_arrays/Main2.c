#define N 10
#include<stdio.h>               //�������� ������� x �������
#include<stdlib.h>				//� ��������� ������� �� �������� �������.
#include<time.h>				//��������� �������� ������ ��� n = 1,2,3,4, �� �� ��� n > 4
#include<stdbool.h>				//����� �������� ������ �������!
#include<locale.h>				//(� ���������, ��������� ������ ����� ��������)
#include<math.h>
void main() {
	int x_igroka, new_game, p, i, vvedeno_pravilno = 1, j = 0, steps = 0, n, x = 1, x_forChanges, min = 1, max, x_igroka_forChanges, b = 0, k = 0;
	short cells_x[10] = {0};//������� � �������� ������, � ������� ����� ������ ���� � ����� x 
	short cells_x_igroka[10] = {0};//������� � �������� ������, � ������� ����� ������ ���� � ����� x_igroka
	_Bool GameOver = false, xIsGood = true, x_igrokaIsGood = true;
	int number_x[N] = {0};

	setlocale(LC_ALL, "Russian"); //���!!! ������ ����� �������� �� ������� �����

	do {
		do {                         //���� n + ��������
			printf("Vvedite n\n");
			/*vvedeno_pravilno = */scanf_s("%d", &n);
		} while ((n <= 0) || (n > 9) || (vvedeno_pravilno != 1)); //����� n <= 9,�.�. ����� ���������� ������������� ����� � ���������������� �������

		for (i = 1; i < n; i++)  min *= 10;    //min znachenie chisla dlini n
		max = min * 10;                        //max znachenie chisla dlini n

		//vvedeno_pravilno = 0;

		/*do  //���� ����������� ����� x �� ���������� ����
		{
			srand((unsigned int)time(0));                  //Random
			
			x =(int)((max - min) * 1.0/ RAND_MAX * rand() + min);     //
			printf("%d, %d, %d, %d\n", x, max - min, RAND_MAX, rand());
			x_forChanges = x;                               //"������� ��� �����"
			for (i = 0; i < n; i++) {     //���������� �������. �������� �������� - ����� ������� (� �����) ����� � �����          
				if (cells_x[x_forChanges % 10] == 0) {
					cells_x[x_forChanges % 10] = i + 1; //����� �������� - ����� � �����.
					xIsGood = true;
				}
				else {
					xIsGood = false;
					for ( p = 0; p <n; p++)
					{
						cells_x[p] = 0;
					}
					break;
				}
				x_forChanges /= 10; // ������: ����� 196 -> cells_x[6]=1; cells_x[9]=2; cells_x[1]=3. ��������� ������ ����� 0.                
			}
		} while (!xIsGood); */  //
		 





		j = 0;
		i = 0;
		//do {
			while(i < n) {
				srand((unsigned int)time(0));
				if ((i == (n - 1)) && ((rand() % 10) == 0)) number_x[i] = 4;
				else number_x[i] = rand() % 10;
				for ( j = 0; j < i; j++) {
					if (number_x[i] == number_x[j]) {
						i--;
						break;
					};
				}
				printf("%d\n", i);
				i++;
			}
		//} while (!xIsGood);


		j = 0;

					//printf("\n");
			for (i = 0; i < n; i++) {
				for ( j = 0; j < i; j++){
					number_x[i] *= 10;
				}
				j = 0;
				//printf("%d\n", number_x[i]);
			}
			for (i = 0; i < n; i++) {
				x += number_x[i];
			}
			//printf("\n");
			printf("%d\n", x);

			x_forChanges = x;
			for (i = 0; i < n; i++) {     //���������� �������. �������� �������� - ����� ������� (� �����) ����� � �����          
					cells_x[x_forChanges % 10] = i + 1; //����� �������� - ����� � �����.
					x_forChanges /= 10;
				}
		
		do {
			steps++;
			do { //���� ����������� ����� x_igroka �� ���������� ����
				printf("%d\n", x);

				vvedeno_pravilno = scanf_s("%d", &x_igroka);
			/*	while (vvedeno_pravilno != 1) {
					printf("Vvedeno ne chislo! Vvedite chislo");
					scanf_s("%d", &x_igroka);
					vvedeno_pravilno = scanf_s("%d", &x_igroka);
				}*/
				x_igroka_forChanges = x_igroka;     //"������� ��� �����"
				for (i = 0; i < n; i++) {     //���������� �������. �������� �������� - ����� ������� (� �����) ����� � �����. H���� �������� - ����� � �����.         
					if ((cells_x_igroka[x_igroka_forChanges % 10] == 0) && (x_igroka >= min) && (x_igroka < max)) {
						cells_x_igroka[x_igroka_forChanges % 10] = i + 1;
						x_igrokaIsGood = true;
						x_igroka_forChanges /= 10; // ������: ����� 196 -> cells_x_igroka[6]=1; cells_x_igroka[9]=2; cells_x_igroka[1]=3. ��������� ������ ����� 0.                
					}
					else {
						printf("Vvedeno plohoe chislo\n");
						steps++;
						x_igrokaIsGood = false;
						for (p = 0; p < N; p++)
						{
							cells_x_igroka[p] = 0;
						}
						break;
					}
				}
			} while (!x_igrokaIsGood);   //

			for (i = 0; i < N; i++) {
				if ((cells_x[i] != 0) && (cells_x_igroka[i] != 0))
					cells_x[i] == cells_x_igroka[i] ? b++ : k++;
			}

			printf("���������� �����: %d\n���������� �����: %d\n", b, k);

			if (b == n) {
				printf("You win!\n My number is %d\n", x);
				steps == 1 ? printf("������� �� 1 ���") : printf("������� �� %d ���a(-��)", steps);
				printf("������ ������� ��� ���?      1 - ��       0 - ���\n");
				scanf_s("%d", &new_game);
				if (new_game == 0) GameOver = true;
				else return;
				break;
			}
			b = 0;
			k = 0;
			x_igroka = 0;
			x_igroka_forChanges = 0;
			for (p = 0; p <N; p++)
			{
				cells_x_igroka[p] = 0;
			}

		} while (b != n);
		for (p = 0; p <N; p++) {
			cells_x[p] = 0;
		}
		x = 0;
		x_forChanges = 0;
		n = 0;
		b = 0;
		k = 0;
		x_igroka = 0;
		x_igroka_forChanges = 0;
		for (p = 0; p <N; p++) {
			cells_x_igroka[p] = 0;
		}
		steps = 0;
	} while (!GameOver);
}