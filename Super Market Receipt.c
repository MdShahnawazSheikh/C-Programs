#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int i, j, sum, user, price[50], quantity[50];
    int store, temp = 0, tp;
    float discount, total = 0;
    time_t t; 
    time(&t);

    system("cls");
    printf("How many products?\n");
    printf("RESPONSE: ");
    scanf("%d", &user);
    char Name[user][50];
    char answer;

    for (i = 0; i < user; i++)
    {
        system("cls");
        printf("Enter Product %d Name: ", i + 1);
        scanf(" %s", &Name[i]);
        printf("Enter product %d price: ", i + 1);
        scanf("%d", &price[i]);
        printf("Enter quantity of product %d: ", i + 1);
        scanf("%d", &quantity[i]);
        tp = price[i] * quantity[i];
        temp = tp + temp;
    }

    printf("Total = %d\n", temp);
    printf("Discount Applicable? ");
    scanf(" %c", &answer);
    if (answer == 'Y' || answer == 'y')
    {
        printf("How much percent of discount? ");
        scanf("%f", &discount);
        store = discount;
        discount = (temp) * (discount / 100);
        total = temp - discount;
    }

    else 
    {
        printf("Okay! discount not applied:)\n");
    }

    printf("RECEIPT GENERATED PRESS ANY KEY TO VIEW.....\n");
    getch();

    system("cls");
    printf("\n\n\n");
    printf("\n\n\n\n\t                                                           BILL GENERATED SUCCESSFULLY                                        ");
    printf("\n\t     =============================================================================================================================\n");
    printf("\n\t\t\t%10s%38s%20s%15s%20s\n\n","PRODUCT NAME","PRICE","QUANTITY", "", "DATE AND TIME");


    for (j = 0; j < user; j++)
    {
        printf("\t\t\t%-30s%15s%-15d%2s%-0d%23s%-2s\n", Name[j], "", price[j], "", quantity[j], "", ctime(&t));
    }
    printf("\n\t     =============================================================================================================================\n");
    if (answer == 'y' || answer == 'Y')
    {
    printf("\t\t\t         GRAND TOTAL BEFORE DISCOUNT:                    %d\n", temp);
    printf("\t\t\t         %d%% DISCOUNT APPLIED:                           %.2f\n\n", store, discount);
    printf("\t\t\t         TOTAL AFTER DISCOUNT DEDUCTION:                 %.2f\n", total);
    }
    else
    {
        printf("\t\t\t                  TOTAL:                                 %d\n", temp);
    }
    
    printf("\t     =============================================================================================================================\n");


    getch();
}