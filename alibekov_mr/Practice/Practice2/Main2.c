#include<stdio.h>
void main() {
	int i, j = 0, q = 0, n, game_over = 0, x = 0, x_forChanges, min = 1, max, x_igroka_forChanges, x_igroka, b = 0, k = 0;
	short case0 = 0, case1 = 0, case2 = 0, case3 = 0, case4 = 0, case5 = 0, case6 = 0, case7 = 0, case8 = 0, case9 = 0;
	do {
		printf("Vvedite n\n");
		scanf_s("%d", &n);
	} while (n<=0);

	for (i = 1; i < n; i++) { min *= 10; } //min znachenie chisla dlini n
	max = min * 10;

	scanf_s("%d", &x_igroka);
	while ((x_igroka < min) || (x_igroka >= max)) {
		printf("Vvedeno plohoe chislo\n");
		scanf_s("%d", &x_igroka);
		
	} 
		x_igroka_forChanges = x_igroka;
	for (i = 0; i < n; i++) {                        
		while (j < (((((x_igroka_forChanges * (i + 1)) % 255) % 7) * n) % 10)) {
			if (q < 10) q++;
			else q = 1;
			j++;
		}
		j = 0;
		while (j < i) {
			q *= 10;
			j++;
		}
		x += q;
		q = 0;
	}

	while (game_over == 0) {
		
		scanf_s("%d", &x_igroka);
		while ((x_igroka < min) || (x_igroka >= max)) {
			printf("Vvedeno plohoe chislo\n");
			scanf_s("%d", &x_igroka);
		}
			printf("\n%d\n", x);

		x_forChanges = x;
		x_igroka_forChanges = x_igroka;
		for (i = 1; i <= n; i++) {                          //while (x_forChanges !=0 )
			if ((x_forChanges % 10) == (x_igroka_forChanges % 10)) b++;
			x_forChanges /= 10;
			x_igroka_forChanges /= 10;
		}
		x_forChanges = x;
		x_igroka_forChanges = x_igroka;
		printf("Kolichestvo bikov: %d\n", b);
		
		/* k = ?
		for (i = 1; i <= n; i++){
		cells_of_x[i] = x_forChanges % 10;                       //massiv iz zifr chisla komputera
		cells_of_x_igroka[i] = x_igroka_forChanges % 10;         //massiv iz zifr chisla igroka
		x_forChanges /= 10;
		x_igroka_forChanges /= 10;
		}
		*/
		for (i = 1; i <= n; i++) {
			switch (x_forChanges % 10) {
			case 0: case0 = i;
					break;
			case 1: case1 = i;
				break;
			case 2: case2 = i;
				break;
			case 3: case3 = i;
				break;
			case 4: case4 = i;
				break;
			case 5: case5 = i;
				break;
			case 6: case6 = i;
				break;
			case 7: case7 = i;
				break;
			case 8: case8 = i;
				break;
			case 9: case9 = i;
				break;
			}
			x_forChanges /= 10;
		}
		x_forChanges = x;
		for (i = 1; i <= n; i++) {
			switch (x_igroka_forChanges % 10){
			case 0: if ((case0 != i) && (case0 != 0)) k++;
				break;
			case 1: if ((case1 != i) && (case1 != 0)) k++;
				break;
			case 2: if ((case2 != i) && (case2 != 0)) k++;
				break;
			case 3: if ((case3 != i) && (case3 != 0)) k++;
				break;
			case 4: if ((case4 != i) && (case4 != 0)) k++;
				break;
			case 5: if ((case5 != i) && (case5 != 0)) k++;
				break;
			case 6: if ((case6 != i) && (case6 != 0)) k++;
				break;
			case 7: if ((case7 != i) && (case7 != 0)) k++;
				break;
			case 8: if ((case8 != i) && (case8 != 0)) k++;
				break;
			case 9: if ((case9 != i) && (case9 != 0)) k++;
				break;
			}
			x_igroka_forChanges /= 10;
		}
		x_igroka_forChanges = x_igroka;
		printf("Kolichestvo korov: %d\n", k);

		if (b == n){             //if (x = x_igroka) {
			game_over = 1;
			printf("You win\n");
		}
		b = 0;
		k = 0;
	}
}