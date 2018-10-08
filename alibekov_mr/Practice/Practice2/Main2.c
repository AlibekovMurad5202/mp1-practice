#include<stdio.h>
void main() {
	int i, n, game_over = 0, x = 78, x_forChanges = 78, min = 1, max, x_igroka_forChanges, x_igroka, b=0, k=0;
	do {
		printf("Vvedite n\n");
		scanf_s("%d", &n);
	} while (n<=0);
	for (i = 0; i < n; i++) { min *= 10; } //min znachenie chisla dlini n
	max = min * 10;
	while (game_over == 0) {
		/* random  x */


		scanf_s("%d", &x_igroka);
		while ((x_igroka < min) || (x_igroka >= max)) {
			printf("Vvedeno plohoe chislo\n");
			scanf_s("%d", &x_igroka);
		}
		x_forChanges = x;
		x_igroka_forChanges = x_igroka;
		for (i = 0; i < n; i++) {                          //while (x_forChanges !=0 )
			if ((x_forChanges % 10) == (x_igroka_forChanges % 10)) b++;
			x_forChanges /= 10;
			x_igroka_forChanges /= 10;
		}

		printf("Kolichestvo bikov: %d\n", b);
		
		/* k = ?

		for (i = 1; i <= n; i++){
		cells_of_x[i] = x_forChanges % 10;                       //massiv iz zifr chisla komputera
		cells_of_x_igroka[i] = x_igroka_forChanges % 10;         //massiv iz zifr chisla igroka
		x_forChanges /= 10;
		x_igroka_forChanges /= 10;
		}
		
		
		
		*/


		printf("Kolichestvo korov: %d\n", k);
		if (b == n){             //if (x = x_igroka) {
			game_over = 1;
			printf("You win");
		}
	}
}