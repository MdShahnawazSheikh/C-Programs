#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int main()
{
        struct Students
        {
            int sId;
            float per, sum;
            char sName[30];
            char subName[20][30];
            float sMarks[6];
        };

        int num, choice, subCount;
        float per;
        char c;
        char secChoice;

        system("cls");
        printf("How many Students? ");
        scanf("%d", &num);
        struct Students stu[num];

        system("cls");
        printf("How many Subjects? ");
        scanf("%d", &subCount);
        scanf("%c", &c);

        //Getting Subject Names
        for (int i = 0; i < 1; i++)
        {
            for (int j = 0; j < subCount; j++)
            {
                printf("Enter name of Subject %d: ", j+1);
                gets(stu[i].subName[j]);
            }
            
        }
        
        //Accepting Details and Marks
        for (int i = 0; i < num; i++)
        {
            stu[i].sum = 0, stu[i].per = 0;
            system("cls");
            printf("Enter Student ID %d: ", i + 1);
            scanf("%d", &stu[i].sId);
            scanf("%c", &c);
            printf("Name of Student %d: ", i + 1);
            gets(stu[i].sName);

            for (int l = 0; l < 1; l++)
            {
                for (int j = 0; j < subCount; j++)
                {
                    printf("Enter Mark in %s: ", stu[l].subName[j]);
                    scanf("%f", &stu[i].sMarks[j]);
                    stu[i].sum = stu[i].sum + stu[i].sMarks[j];
                }
            }
            stu[i].per = stu[i].sum / subCount;
        }

        system("cls");
        printf("What type of view do you want?\n");
        printf("\t1) Column View (Does not contain Individual Subject Marks)\n");
        printf("\t2) Detail View (Does contain Individual Subjects Marks)\n");
        printf("RESPONSE: ");
        scanf("%d", &choice);

        if (choice == 1)
        {
            system("cls");
            printf("\n%5s%14s%38s%20s%2s%20s\n\n","","STUDENT NAME","STUDENT ID","TOTAL MARKS", "", "PERCENTAGE");

            for (int i = 0; i < num; i++)
            {
                printf("%5s%-30s%15s%-15d%2s%.2f%19s%.2f\n","", stu[i].sName, "", stu[i].sId, "", stu[i].sum, "", stu[i].per);
            }
            
            scanf("%c", &c);
            printf("\n\n\n\t\t\t\t\tEnter Detailed View...? ");
            scanf("%c", &secChoice);
            if (secChoice == 'Y' || secChoice == 'y')
            {
                system("cls");
                for (int i = 0; i < num; i++)
                {
                    printf("                Student %d\n", i + 1);
                    printf("Student ID                       : %d\n", stu[i].sId);
                    printf("Student Name                     : %s\n", stu[i].sName);
                    for (int l = 0; l < 1; l++)
                    {
                        for (int j = 0; j < subCount; j++)
                        {
                            printf("Marks in %s  : %.2f\n", stu[l].subName[j], stu[i].sMarks[j]);
                        }
                        
                    }
                    printf("\nTotal Marks                      : %.2f\n", stu[i].sum);
                    printf("Total Percentage                 : %.2f\n", stu[i].per);
                    printf("\n\n\n");
                }
            }
            
            else printf("\n\n\t\t\t\t\tPRESS ANY KEY TO EXIT...\n");
        }

        else if (choice == 2)
        {
            system("cls");
            for (int i = 0; i < num; i++)
            {
                printf("                Student %d\n", i + 1);
                printf("Student ID                       : %d\n", stu[i].sId);
                printf("Student Name                     : %s\n", stu[i].sName);
                for (int l = 0; l < 1; l++)
                {
                    for (int j = 0; j < subCount; j++)
                    {
                        printf("Marks in %s  : %.2f\n", stu[l].subName[j], stu[i].sMarks[j]);
                    }
                    
                }
                printf("\nTotal Marks                      : %.2f\n", stu[i].sum);
                printf("Total Percentage                 : %.2f\n", stu[i].per);
                printf("\n\n\n");

                scanf("%c", &c);
                printf("\n\n\n\t\t\t\t\tEnter Column View...? ");
                scanf("%c", &secChoice);

                if (secChoice == 'y' || secChoice == 'Y')
                {
                    system("cls");
                    printf("\n%5s%14s%38s%20s%2s%20s\n\n","","STUDENT NAME","STUDENT ID","TOTAL MARKS", "", "PERCENTAGE");

                    for (int i = 0; i < num; i++)
                    {
                        printf("%5s%-30s%15s%-15d%2s%.2f%19s%.2f\n","", stu[i].sName, "", stu[i].sId, "", stu[i].sum, "", stu[i].per);
                    }
                }
                else printf("\n");
            }
    }


    else 
    {
        system("cls");
        printf("\t\t\t\t\tInvalid Input...\n");
    }

    //Next Session
                scanf("%c", &c); //To avoid error...
                printf("\n\n\n\t\t\t\tCreate New Session?\n");
                printf("\t\t\t\tRESPONSE: ");
                scanf("%c", &secChoice);
                if (secChoice == 'y' || secChoice == 'Y')
                {
                    main();
                }
                else exit(0);

    getch();


}