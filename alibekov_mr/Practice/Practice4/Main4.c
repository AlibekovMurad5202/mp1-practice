#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define N 10000
#define MAX_LENGTH 16
#define NUMBER_OF_ITEMS 71
 
int flag1 = 0, flag3 = 0, flag4 = 0;

typedef struct 
{
  char name[MAX_LENGTH];
  int price;
  int cashback;
  int id_code;
  int k;
} TItem;

TItem items[N];

void Fill_names() 
{
  int i;
  for (i = 1; i < NUMBER_OF_ITEMS; i += 7) 
  {
    items[i].name[0] = 'G';
    items[i].name[1] = 'u';
    items[i].name[2] = 'n';
  }
  for (i = 2; i < NUMBER_OF_ITEMS; i += 7) 
  {
    items[i].name[0] = 'P';
    items[i].name[1] = 'o';
    items[i].name[2] = 't';
    items[i].name[3] = 'a';
    items[i].name[4] = 't';
    items[i].name[5] = 'o';
  }
  for (i = 3; i < NUMBER_OF_ITEMS; i += 7) 
  {
    items[i].name[0] = 'T';
    items[i].name[1] = 'o';
    items[i].name[2] = 'm';
    items[i].name[3] = 'a';
    items[i].name[4] = 't';
    items[i].name[5] = 'o';
  }
  for (i = 4; i < NUMBER_OF_ITEMS; i += 7) 
  {
    items[i].name[0] = 'E';
    items[i].name[1] = 'y';
    items[i].name[2] = 'e';
  }
  for (i = 5; i < NUMBER_OF_ITEMS; i += 7) 
  {
    items[i].name[0] = 'F';
    items[i].name[1] = 'r';
    items[i].name[2] = 'o';
    items[i].name[3] = 'g';
  }
  for (i = 6; i < NUMBER_OF_ITEMS; i += 7) 
  {
    items[i].name[0] = 'B';
    items[i].name[1] = 'u';
    items[i].name[2] = 'g';
  }
  for (i = 7; i < NUMBER_OF_ITEMS; i += 7) 
  {
    items[i].name[0] = 'C';
    items[i].name[1] = 'h';
    items[i].name[2] = 'e';
    items[i].name[3] = 'e';
    items[i].name[4] = 's';
    items[i].name[5] = 'e';
  }
  for (i = 1; i < NUMBER_OF_ITEMS; i++) 
  {
    switch (i % 10) 
    {
    case 0: break;
    case 1: items[i].name[7] = 'f';
      items[i].name[8] = 'r';
      items[i].name[9] = 'e';
      items[i].name[10] = 's';
      items[i].name[11] = 'h';
      break;
    case 2: items[i].name[7] = 'a';
      items[i].name[8] = 'l';
      items[i].name[9] = 'i';
      items[i].name[10] = 'v';
      items[i].name[11] = 'e';
      break;
    case 3: items[i].name[7] = 'y';
      items[i].name[8] = 'o';
      items[i].name[9] = 'u';
      items[i].name[10] = 'n';
      items[i].name[11] = 'g';
      break;
    case 4: items[i].name[7] = 'a';
      items[i].name[8] = 'n';
      items[i].name[9] = 'c';
      items[i].name[10] = 'i';
      items[i].name[11] = 'e';
      items[i].name[12] = 'n';
      items[i].name[13] = 't';
      break;
    case 5: items[i].name[7] = 'e';
      items[i].name[8] = 'l';
      items[i].name[9] = 'i';
      items[i].name[10] = 't';
      items[i].name[11] = 'e';
      break;
    case 6: items[i].name[7] = 'k';
      items[i].name[8] = 'i';
      items[i].name[9] = 'n';
      items[i].name[10] = 'd';
      break;
    case 7: items[i].name[7] = 'c';
      items[i].name[8] = 'o';
      items[i].name[9] = 'l';
      items[i].name[10] = 'o';
      items[i].name[11] = 'r';
      break;
    case 8: items[i].name[7] = 'r';
      items[i].name[8] = 'o';
      items[i].name[9] = 't';
      items[i].name[10] = 't';
      items[i].name[11] = 'e';
      items[i].name[12] = 'n';
      break;
    case 9: items[i].name[7] = 'f';
      items[i].name[8] = 'u';
      items[i].name[9] = 'n';
      items[i].name[10] = 'n';
      items[i].name[11] = 'y';
      break;
    }
  }
}

void Fill_struct_without_names() 
{
  srand((unsigned)time(0));
  int i, j;
  for (i = 1; i < N; i++) 
  {
    if (items[i].name[0] != '0')
    {
      items[i].price = 399.0 / RAND_MAX * rand() + 20;
      items[i].cashback = 49.0 / RAND_MAX * rand() + 1;
      items[i].id_code = i;
      items[i].k = 0;
    }
  }
}

int Choose_an_action() 
{
  int z = 0;
  if (flag1 == 0) 
  {
    printf("Please, enter number of action what you want to do:\n");
    printf("1 - Scan ID_code of item;\n6 - Exit from %cShop for witches%c.\nEnter: ", '"', '"');
    scanf("%d", &z);
    while ((z != 1) && (z != 6)) 
    {
      printf("Please, enter 1 or 6.\nEnter: ");
      scanf("%d", &z);
    }
    if (z == 1) printf("Please enter ID_code of item: ");
  }
  else if (flag4 == 1) 
  {
    printf("Please, enter number of action what you want to do:\n5 - Bill;\n");
    printf("6 - Exit from %cShop for witches%c.\nEnter: ", '"', '"');
    scanf("%d", &z);
    while ((z != 5) && (z != 6)) 
    {
      printf("Please, enter 5 or 6.\nEnter: ");
      scanf("%d", &z);
    }
  }
  else 
  {
    printf("Please, enter number of action what you want to do:\n");
    printf("1 - Scan ID_code of another item;\n2 - Show information about scanned item;\n");
    printf("3 - Add scanned item to check;\n4 - Create check;\n5 - Bill;\n");
    printf("6 - Exit from %cShop for witches%c.\nEnter: ", '"', '"');
    scanf("%d", &z);
    if (z == 1) printf("Please enter ID_code of item: ");
    while ((z < 1) || (z > 6)) 
    {
      printf("Please, enter one number from 1 to 6.\nEnter: ");
      scanf("%d", &z);
    }
  }
  return z;
}

int Scan_new_item() 
{
  int id;
  scanf("%d", &id);
  while ((items[id].name[0] == 0)||(id < 0)||(id >= N))
  {
    printf("Item with this ID_code is not exist.\nPlease, enter another ID_code: ");
    scanf("%d", &id);
  }
  printf("\n");
  flag1 = 1;
  return id;
}

void Output_info_about_item(int id) 
{
  printf("     Name: ");
  int i;
  for (i = 0; i < MAX_LENGTH; i++)
    printf("%c", items[id].name[i]);
  printf("\n     Price: %d rub.", items[id].price);
  printf("\n     Cashback: %d %c\n     ID_code: ", items[id].cashback, '%');
  if (id >= 1000) printf("%d\n", id);
  else if (id >= 100) printf("0%d\n", id);
  else if (id >= 10) printf("00%d\n", id);
  else printf("000%d\n", id);
  printf("\n");
}

void Add_item(int id) 
{
  items[id].k++;
  printf("\n");
  flag3 = 1;
}

void Check() 
{
  int i;
  printf("\n        ---------------------------------------\n");
  for (i = 0; i < N; i++) 
  {
    if (items[i].k != 0) 
    {
      int q;
      printf("         ");
      for (q = 0; q < MAX_LENGTH; q++)
        printf("%c", items[i].name[q]);
      printf(" - %d", items[i].price);
      printf(" - %d", items[i].k);
      printf(" - %d", ((items[i].price) * (items[i].k)));
      printf("\n");
    }
  }
  printf("\n        ---------------------------------------\n\n");
}

void Bill() 
{
  int i, pay = 0, cash_back = 0;
  for (i = 0; i < N; i++) 
  {
    if (items[i].k != 0) 
    {
      pay += (items[i].price) * (1 - (0.01 * items[i].cashback))* (items[i].k);
      cash_back += (items[i].price) * (0.01 * items[i].cashback)* (items[i].k);
    }
  }
  printf("\n                                   Bill: %d rub.", pay + cash_back);
  printf("\n                               Cashback: %d rub.", cash_back);
  printf("\n                                 To pay: %d rub.\n", pay);
  printf("\n          *** Thank you for buying. Come again. ***\n\n");
}

void main() 
{
  int choose = 0, ind;
  Fill_names();
  Fill_struct_without_names();
  printf("         Good day. Welcome to %cShop for witches%c. ", '"', '"');
  printf("Here you can buy gun, eye, frog and other.\n\n");
  while (1)
  {
    choose = Choose_an_action();
    if (choose != 1) printf("\n");

    switch (choose) 
    {
    case 1: ind = Scan_new_item();
            break;
    case 2: Output_info_about_item(ind);
            break;
    case 3: Add_item(ind);
            break;
    case 4: Check();
            break;
    case 5: Bill();
            return;
    case 6: if (flag3 == 1) 
            {
              printf("Please, pay before you exit.\n");
              Bill();
            }
            return;
    }
  }
}