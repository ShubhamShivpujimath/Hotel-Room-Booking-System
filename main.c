/* ========================= main.c ========================= */

#include <stdio.h>
#include <string.h>

#include "hotel.h"
#include "file.h"

int main()
{
    int choice;
    int customerChoice;

    char username[20];
    char password[20];

    loadFromFile();
    loadCustomers();

    while (1)
    {
        printf("\n=====================================\n");
        printf("      WELCOME TO HOTEL HOGWARTS 9¾\n");
        printf("=====================================\n");

        printf("1. Admin\n");
        printf("2. User / Customer\n");
        printf("3. Exit\n");

        printf("\nEnter Choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:

                printf("\n========== ADMIN LOGIN ==========\n");

                printf("Enter Username: ");
                scanf("%s", username);

                printf("Enter Password: ");
                scanf("%s", password);

                if (strcmp(username, "admin") == 0 &&
                    strcmp(password, "1234") == 0)
                {
                    printf("Login Successful\n");

                    adminMenu();
                }

                else
                {
                    printf("Invalid Username Or Password\n");
                }

                break;

            case 2:

                while (1)
                {
                    printf("\n========== CUSTOMER ==========\n");

                    printf("1. Login\n");
                    printf("2. Signup\n");
                    printf("3. Back\n");

                    printf("Enter Choice: ");
                    scanf("%d", &customerChoice);

                    switch (customerChoice)
                    {
                        case 1:
                            customerLogin();
                            break;

                        case 2:
                            customerSignup();
                            break;

                        case 3:
                            goto mainMenu;

                        default:
                            printf("Invalid Choice\n");
                    }
                }

            case 3:

                saveToFile();
                saveCustomers();

                printf("\nThank You For Visiting Hotel Hogwarts\n");

                return 0;

            default:

                printf("Invalid Choice\n");
        }

mainMenu:
        ;
    }
}