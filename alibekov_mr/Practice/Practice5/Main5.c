#include<stdio.h>
#define N 10
#define k 5

void input_a(int a[], int n) {
  int i;
  for (i = 0; i < n; i++) scanf("%d", &(a[i]));
}

void output_a(int a[], int n) {
  int i;
  for (i = 0; i < n; i++) {
    printf("%d", a[i]);
    printf(" ");
  }
}

void Choose_Sort(int a[], int n) {
  int i, j, min, min_ind;
  for (i = 0; i < n; i++) {
    min = a[i];
    min_ind = i;
    for (j = i + 1; j < n; j++) {
      if (a[j] < min) {
        min = a[j];
        min_ind = j;
      }
    }
    a[min_ind] = a[i];
    a[i] = min;
  }
}

void Insert_Sort(int a[], int n) {
  int i, j, tmp;
  for (i = 0; i < n; i++) {
    tmp = a[i];
    j = i - 1;
    while ((j >= 0) && (a[j] > tmp)) {
      a[j + 1] = a[j];
      a[j] = tmp;
      j--;
    }
  }
}

void Bubble_Sort(int a[], int n) {
  int i, j, tmp;
  for (i = 0; i < n; i++) {
    for (j = 1; j < n - i; j++) {
      if (a[j - 1] > a[j]) {
        tmp = a[j];
        a[j] = a[j - 1];
        a[j - 1] = tmp;
      }
    }
  }
}

void Counting_Sort(int a[], int n) {
  int i, j;
  int count[k] = { 0 };
  for (i = 0; i < n; i++) count[a[i]]++;
  int index = 0;
  for (j = 0; j < k; j++) {
    for (i = 0; i < count[j]; i++) {
      a[index++] = j;
    }
  }
}

void main() {
  int a[N] = { 0 };
  int choose;
  printf("Enter array.\n");
  input_a(a, N);
  printf("Your array: ");
  output_a(a, N);
  printf("\nChoose method of sort:\n1)Choose Sort\n2)Insert Sort\n3)Bubble Sort\n4)Counting Sort\n");
  scanf("%d", &choose);
  switch (choose)
  {
  case 1: Choose_Sort(a, N);
    break;
  case 2: Insert_Sort(a, N);
    break;
  case 3: Bubble_Sort(a, N);
    break;
  case 4: Counting_Sort(a, N);
    break;
  }
  printf("\n");
  output_a(a, N);
}