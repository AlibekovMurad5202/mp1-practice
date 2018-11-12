#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define N 1000

void fill_items(int items[], int number_of_items)
{
    srand((unsigned)time(0));
    int i;
    for (i = 1; i < number_of_items; i++)
    {
        items[i] = rand();
    }
}

void fill_price_of_one_item(int price_of_one_item[], int number_of_items)
{
    srand((unsigned)time(0));
    int i;
    for (i = 1; i < number_of_items; i++)
    {
        price_of_one_item[i] = rand();
    }
}

void fill_cashback(int cashback[], int number_of_items)
{
    srand((unsigned)time(0));
    int i;
    for (i = 1; i < number_of_items; i++)
    {
        cashback[i] = 49.0/RAND_MAX*rand()+1;
    }
}


int scan_new_item() 
{  
    int ind;
    scanf("%d", &ind);
    return ind;
}



void main()
{
    int items[N] = { 0 };
    int price_of_one_item[N] = { 0 };
    int cashback[N] = { 0 };
    int number_of_items[N] = { 0 };
    int z, ind;
    fill_items(items, N);
    fill_price_of_one_item(price_of_one_item, N);
    fill_cashback(cashback, N);
    printf("Enter: 1 - scan;  2 - ...");
    scanf("%d", &z);
    switch (z) 
    {
      case 1: ind = scan_new_item();
              number_of_items[ind]++;
              break;
    }
    

}
