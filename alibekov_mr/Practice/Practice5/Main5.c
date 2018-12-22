#include<stdio.h>
#include<stdlib.h>

void input_a(int a[], int n) {
  int i;
  for (i = 0; i < n; i++)
    scanf("%d", &(a[i]));
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
  int i, j, k = 0;
  k = a[0];
  for (i = 1; i < n; i++)
    if (a[i] > k)
      k = a[i];
  k++;
  int *count = (int *)malloc(k * sizeof(int));
  for (i = 0; i < k; i++) count[i] = 0;
  for (i = 0; i < n; i++) {
    *(count + a[i]) = *(count + a[i]) + 1;
    count - a[i];
  }
  int index = 0;
  for (j = 0; j < k; j++) {
    for (i = 0; i < count[j]; i++) {
      a[index] = j;
      index++;
    }
    count - j;
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

void Merge(int *a, int left, int mid, int right) {
  int i = 0, j = 0, k;
  int *c = (int *)malloc((right - left) * sizeof(int));
  while ((left + i < mid) && (mid + j < right))
  {
    if (a[left + i] < a[mid + j]) {
      c[i + j] = a[left + i];
      i++;
    }
    else {
      c[i + j] = a[mid + j];
      j++;
    }
  }
  while (left + i < mid) {
    c[i + j] = a[left + i];
    i++;
  }
  while (mid + j < right) {
    c[i + j] = a[mid + j];
    j++;
  }
  for (k = 0; k < i + j; k++) a[left + k] = c[k];
  free(c);
}

void Merge_Sort(int a[], int left, int right) {
  int mid, i;
  if (left + 1 >= right) return;
  mid = (right + left) / 2;
  Merge_Sort(a, left, mid);
  Merge_Sort(a, mid, right);
  Merge(a, left, mid, right);
}

void main() {
  int N, choose;
  printf("Enter count of elements in array.\n");
  scanf("%d", &N);
  int *a = (int *)malloc(N * sizeof(int));
  printf("Enter array.\n");
  input_a(a, N);
  printf("Your array: ");
  output_a(a, N);
  printf("\nChoose method of sort:\n1)Choose Sort\n2)Insert Sort\n3)Bubble Sort\n4)Counting Sort\n5)Quick Sort\n6)Merge Sort\n");
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
  case 6: Merge_Sort(a, 0, N);
    break;
  }
  printf("\n");
  output_a(a, N);

  free(a);
}