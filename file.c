/* ========================= file.c ========================= */

#include <stdio.h>
#include "hotel.h"

void saveToFile()
{
    FILE *fp = fopen("hotel.txt", "w");

    if (fp == NULL)
    {
        printf("File Error\n");
        return;
    }

    for (int i = 0; i < count; i++)
    {
        fprintf(fp,
                "%d %s %s %d %d %d %s %s %.2f\n",

                hotel[i].roomNumber,
                hotel[i].name,
                hotel[i].phone,

                hotel[i].checkIn,
                hotel[i].checkOut,
                hotel[i].totalDays,

                hotel[i].type,
                hotel[i].category,

                hotel[i].bill);
    }

    fclose(fp);
}

void loadFromFile()
{
    FILE *fp = fopen("hotel.txt", "r");

    if (fp == NULL)
    {
        return;
    }

    while (fscanf(fp,
                  "%d %s %s %d %d %d %s %s %f",

                  &hotel[count].roomNumber,
                  hotel[count].name,
                  hotel[count].phone,

                  &hotel[count].checkIn,
                  &hotel[count].checkOut,
                  &hotel[count].totalDays,

                  hotel[count].type,
                  hotel[count].category,

                  &hotel[count].bill) != EOF)
    {
        count++;
    }

    fclose(fp);
}

void saveCustomers()
{
    FILE *fp = fopen("customer.txt", "w");

    if (fp == NULL)
    {
        return;
    }

    for (int i = 0; i < customerCount; i++)
    {
        fprintf(fp,
                "%s %s\n",

                customers[i].username,
                customers[i].password);
    }

    fclose(fp);
}

void loadCustomers()
{
    FILE *fp = fopen("customer.txt", "r");

    if (fp == NULL)
    {
        return;
    }

    while (fscanf(fp,
                  "%s %s",

                  customers[customerCount].username,
                  customers[customerCount].password) != EOF)
    {
        customerCount++;
    }

    fclose(fp);
}