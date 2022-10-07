#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int main()
{
    int temp, user, hour[50], minutes[50]; 
    int hr[50], mi[50];
    char priority[50];
    
    printf("How many activities?\n");
    scanf("%d", &user);

    char activity[user][50];
    for (int i = 0; i < user; i++)
    {
        printf("Enter activity %d:  ", i+1);
        scanf("%s",&activity[i]);
        printf("Activity %d starts from? (format: hh mm): ", i+1);
        scanf("%d%d", &hour[i], &minutes[i]);
        printf("Activity %d till? (format: hh mm): ", i+1);
        scanf("%d%d", &hr[i], &mi[i]);
        printf("Enter priority for %d activity(Enter H for HIGH and L for LOW): ", i+1);
        scanf(" %c", &priority[i]);
    }
    
    system("cls");
    printf("\n\n\n\t\t\t\t\t     TIME-TABLE CREATED SUCCESSFULLY\n");
    printf("\n\t%20s%30s%20s%20s\n\n","ACTIVITY","STARTS","ENDS","PRIORITY");
    
    for (int j = 0; j < user; j++)
    {
        printf("\t\t%-30s%6s%02d:%02d%17s%02d:%02d", activity[j],"",hour[j], minutes[j],"", hr[j], mi[j]);
        if (priority[j] == 'h' || priority[j] == 'H')
        {
            printf("%17s\n", "HIGH");
        }

        else if (priority[j] == 'L' || priority[j] == 'l')
        {
            printf("%17s\n", "LOW");
        }
        
        else
        {
            printf("%17s\n", "U/A");
        }
        
    }
    
    
getch();

}