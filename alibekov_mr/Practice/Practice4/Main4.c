#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#define N 10000
#define MAX_LENGTH 16
#define NUMBER_OF_ITEMS 71

int flag1 = 0, flag2 = 0, flag3 = 0;

typedef struct
{
    char name[MAX_LENGTH];
    int price;
    int cashback;
    char id[4];
    int k;
} TItem;

TItem items[N];

void Fill_names()
{
    int i;
    for (i = 1; i < NUMBER_OF_ITEMS; i++)
    {
        switch (i % 10)
        {
        case 0: strcat(items[i].name, "Normal ");
                break;
        case 1: strcat(items[i].name, "Fresh ");
                break;
        case 2: strcat(items[i].name, "Alive ");
                break;
        case 3: strcat(items[i].name, "Young ");
                break;
        case 4: strcat(items[i].name, "Ancient ");
                break;
        case 5: strcat(items[i].name, "Elite ");
                break;
        case 6: strcat(items[i].name, "Kind ");
                break;
        case 7: strcat(items[i].name, "Color ");
                break;
        case 8: strcat(items[i].name, "Rotten ");
                break;
        case 9: strcat(items[i].name, "Funny ");
                break;
        }

        switch (i % 7)
        {
        case 0: strcat(items[i].name, "gun");
                break;
        case 1: strcat(items[i].name, "potato");
                break;
        case 2: strcat(items[i].name, "tomato");
                break;
        case 3: strcat(items[i].name, "eye");
                break;
        case 4: strcat(items[i].name, "frog");
                break;
        case 5: strcat(items[i].name, "bug");
                break;
        case 6: strcat(items[i].name, "cheese");
                break;
        }
    }
}

void Fill_struct_without_names()
{
    int i;
    srand((unsigned)time(0));
    for (i = 1; i < NUMBER_OF_ITEMS; i++)
    {
        if (items[i].name[0] != '0')
        {
            items[i].price = (int)(399.0 / RAND_MAX * rand() + 20);
            items[i].cashback = (int)(49.0 / RAND_MAX * rand() + 1);
            items[i].id[3] = i % 10;
            items[i].id[2] = (i / 10) % 10;
            items[i].id[1] = (i / 100) % 10;
            items[i].id[0] = (i / 1000) % 10;
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
    else if (flag3 == 1)
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
    while ((id <= 0) || (id > NUMBER_OF_ITEMS))
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
    int i = 0;
    printf("     Name: %s\n", items[id].name);
    printf("     Price: %d rub.\n", items[id].price);
    printf("     Cashback: %d %c\n     ID_code: ", items[id].cashback, '%');
    for (; i < 4; i++) printf("%d", items[id].id[i]);
    printf("\n");
}

void Add_item(int id)
{
    items[id].k++;
    printf("\n");
    flag2 = 1;
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
            pay += (items[i].price) * (int)(1 - (0.01 * items[i].cashback))* (items[i].k);
            cash_back += (items[i].price) * (int)(0.01 * items[i].cashback)* (items[i].k);
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
        case 6: if (flag2 == 1)
                {
                    printf("Please, pay before you exit.\n");
                    Bill();
                }
                return;
        }
    }
}