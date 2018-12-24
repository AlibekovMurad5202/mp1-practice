#include<stdio.h>
#include<stdlib.h>
#include <windows.h>
#include <string.h>
#include <time.h>
#define ULL unsigned long long int

int down = 1;
int cof = 0;
//int exit_from_loop = 0;
int Exit = 0;
typedef char* word;

void input_a(ULL a[], ULL *sizes) {
  int i;
  for (i = 0; i < cof; i++)
    a[i] = sizes[i];
}

void output(ULL sizes[], int ind[], word *names) {
  int k;
  for (k = 0; k < cof; k++) {
    printf("%s ", (names[ind[k]]));
    printf("%llu\n", sizes[ind[k]]);
  }
}

void Choose_Sort(ULL a[] , int n) {
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

void Insert_Sort(ULL a[], int n) {
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

void Bubble_Sort(ULL a[], int n) {
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

void Counting_Sort(ULL a[], int n) {
  int i, j, k = 0;
  k = a[0];
  for (i = 1; i < n; i++)
    if (a[i] > k)
      k = a[i];
  k++;
  ULL *count = (ULL *)malloc(k * sizeof(ULL));
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

void quick_split(ULL a[], int *i, int *j, int p) {
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

void Quick_Sort(ULL a[], int n1, int n2) {
  int m = (n1 + n2) / 2;
  int i = n1, j = n2;
  quick_split(a, &i, &j, a[m]);
  if (i > n1) Quick_Sort(a, n1, i - 1);
  if (j < n2) Quick_Sort(a, j + 1, n2);
}

void Merge(ULL *a, int left, int mid, int right) {
  int i = 0, j = 0, k;
  ULL *c = (ULL *)malloc((right - left) * sizeof(ULL));
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

void Merge_Sort(ULL a[], int left, int right) {
  int mid, i;
  if (left + 1 >= right) return;
  mid = (right + left) / 2;
  Merge_Sort(a, left, mid);
  Merge_Sort(a, mid, right);
  Merge(a, left, mid, right);
}

int Count_of_files(const wchar_t *sDir)
{
  WIN32_FIND_DATA fdFile;
  HANDLE hFind = NULL;
  wchar_t sPath[2048];
  int i = 0;
  wsprintf(sPath, L"%s\\*.*", sDir);
  if ((hFind = FindFirstFile(sPath, &fdFile)) == INVALID_HANDLE_VALUE)
    return 0;
  do {
    if (wcscmp(fdFile.cFileName, L".") != 0 && wcscmp(fdFile.cFileName, L"..") != 0)
      i++;
  } while (FindNextFile(hFind, &fdFile));
  FindClose(hFind);
  return i;
}

int GetInfoAboutFiles(const wchar_t *sDir, char ***names, ULL *sizes)
{
  WIN32_FIND_DATA fdFile;
  HANDLE hFind = NULL;
  wchar_t sPath[2048];
  int i, j = 0;
  wsprintf(sPath, L"%s\\*.*", sDir);
  *names = (char **)malloc(cof * sizeof(char *));
  for (i = 0; i < cof; i++) {
    (*names)[i] = (word)malloc(2048 * sizeof(char));
  }
  hFind = FindFirstFile(sPath, &fdFile);
  do
  {
    if (wcscmp(fdFile.cFileName, L".") != 0 && wcscmp(fdFile.cFileName, L"..") != 0)
    {
      i = 0;
      ULONGLONG fileSize = fdFile.nFileSizeHigh;
      fileSize <<= sizeof(fdFile.nFileSizeHigh) * 8;
      fileSize |= fdFile.nFileSizeLow;
      wsprintf(sPath, L"%s\\%s", sDir, fdFile.cFileName);
      while ((int)(*(fdFile.cFileName + i)) != 0) {
        if (i == 0) strcpy((*names)[j], fdFile.cFileName + 0);
        else strcat((*names)[j], fdFile.cFileName + i);
        i++;
        sizes[j] = fileSize;
      }
      strcat((*names)[j], "\0");
      j++;
    }
  } while (FindNextFile(hFind, &fdFile));
  FindClose(hFind);
  return 0;
}

void main() {
  int choose, i, choose_action;
  clock_t t1;
  clock_t t2;
  ULL tmp = 0;
  int k, j = 0;
  printf("Good day. ");
  do
  {
    printf("Please, enter the path.\n");
    word aw = (word)malloc(2048 * sizeof(char));
    scanf("%s", aw);
    wchar_t *wa = (wchar_t *)malloc(2048 * sizeof(char));
    swprintf(wa, 2048 * sizeof(char), L"%hs", aw);
    cof = Count_of_files(wa);
    if (cof == 0) {
      wprintf(L"Path not found: [%s]\n", wa);
      printf("Please, enter another path.\n");
      continue;
    }
    char **names;
    ULL *sizes = (ULL *)malloc(cof * sizeof(ULL));
    GetInfoAboutFiles(wa, &names, sizes);
    do {
      ULL *a = (ULL *)malloc(cof * sizeof(ULL));
      char *c_ar = (char *)malloc(cof * sizeof(char));
      for (i = 0; i < cof; i++) c_ar[i] = 0;
      int *ind = (int *)malloc(cof * sizeof(int));
      ind[0] = 0;
      input_a(a, sizes);
      printf("\nChoose method of sort:\n1)Choose Sort\n2)Insert Sort\n3)Bubble Sort\n4)Counting Sort\n5)Quick Sort\n6)Merge Sort\n");
      scanf("%d", &choose);
      printf("Choose characteristic of sort: 1 - down     0 - up\n");
      scanf("%d", &down);
      t1 = clock();
      switch (choose)
      {
      case 1: Choose_Sort(a, cof);
        break;
      case 2: Insert_Sort(a, cof);
        break;
      case 3: Bubble_Sort(a, cof);
        break;
      case 4: Counting_Sort(a, cof);
        break;
      case 5: Quick_Sort(a, 0, cof - 1);
        break;
      case 6: Merge_Sort(a, 0, cof);
        break;
      }
      t2 = clock();
      printf("%lf sec\n", ((double)(t2-t1))/CLOCKS_PER_SEC);
      if (down) {
        for (i = 0; i < cof / 2; i++) {
          tmp = a[i];
          a[i] = a[cof - 1 - i];
          a[cof - 1 - i] = tmp;
        }
      }
      for (i = 0; i < cof; i++) {
        for (j = 0; j < cof; j++)
          if ((sizes[i] == a[j]) && (c_ar[j] == 0)) {
            ind[j] = i;
            c_ar[j] = 1;
            break;
          }
      }
      printf("Please, enter number of action what you want to do:\n1)Change path\n2)Sort\n");
      printf("3)Show\n4)Exit\n");
      scanf("%d", &choose_action);
      if (choose_action == 1)
        break;
      else if (choose_action == 3)
        output(sizes, ind, names);
      else if (choose_action == 4) return;
      printf("\nWhat you want?\n1)Use another sort.\n2)Change path.\n");
      scanf("%d", &choose_action);
      if (choose_action == 2) break;
      free(a);
      free(ind);
      free(c_ar);
    } while (1);//while (exit_from_loop == 0);
    free(names);
    free(sizes);
    free(wa);
    free(aw);
  } while (Exit == 0);
}