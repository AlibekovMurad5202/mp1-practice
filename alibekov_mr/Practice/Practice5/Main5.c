#include<stdio.h>
#include<stdlib.h>
#define N 10
#define k 5
  
//int bm[N];

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

void quick_split(int a[], int *i, int *j, int p) {
    do {
        while (a[(*i)] < p) (*i)++;
        while (a[(*j)] > p) (*j)--;
        if ((*i) <= (*j)) {
            int tmp = a[(*i)];
            a[(*i)] = a[(*j)];
            a[(*j)] = tmp;
        }
    } while ((*i) < (*j));
}

void Quick_Sort(int a[], int n1, int n2) {
    int m = (n1 + n2) / 2;
    int i = n1, j = n2;
    quick_split(a, &i, &j, a[m]);
    if (i > n1) Quick_Sort(a, n1, i - 1);
    if (j < n2) Quick_Sort(a, j + 1, n2);
}

/*
void Merge(int *a, int size_a, int *b, int size_b, int *c) {
  int i, j, s;
  i = j = s = 0;
  while ((i < size_a) && (j < size_b))
  {
    if (a[i] <= b[j]) c[s++] = a[i++];
    else c[s++] = b[j++];
  }
  if (i == size_a)
    while (j < size_b) c[s++] = b[j++];
  if (j == size_b)
    while (i < size_a) c[s++] = a[i++];
}

void Merge_Sort(int a[], int left, int right) {
  int mid, i;
  //int *b = (int *)malloc(N * sizeof(int));

  if (left <= right) return;
  mid = (left + right) / 2;
  Merge_Sort(a, left, mid);
  Merge_Sort(a, mid + 1, right);
  Merge(a + left, mid + left - 1, a + mid, right - mid + 1, bm);
 // return &(b[0]);
}
*/
void main() {
  int a[N] = { 0 };
  int choose, i;
//  int *bm;
  printf("Enter array.\n");
  input_a(a, N);
  printf("Your array: ");
  output_a(a, N);
  printf("\nChoose method of sort:\n1)Choose Sort\n2)Insert Sort\n3)Bubble Sort\n");
  printf("4)Counting Sort\n5)Quick Sort\n6)Merge Sort\n");
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
  case 5: Quick_Sort(a, 0, N - 1);
    break;
 /* case 6: Merge_Sort(a, 0, N - 1);
    for (i = 0; i < N; i++) {
      a[i] = bm[i];
    }
    break;*/
  }
  printf("\n");
  output_a(a, N);
}