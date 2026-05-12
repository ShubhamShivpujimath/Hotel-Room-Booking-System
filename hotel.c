/* ========================= hotel.c ========================= */

#include <stdio.h>
#include <string.h>

#include "hotel.h"
#include "file.h"

struct Booking hotel[MAX];
struct Customer customers[MAX];

int count = 0;
int customerCount = 0;

/* Check Room Availability */

int isRoomAvailable(int roomNumber)
{
    for (int i = 0; i < count; i++)
    {
        if (hotel[i].roomNumber == roomNumber)
        {
            return 0;
        }
    }

    return 1;
}

/* Auto Allocate Room */

int getAvailableRoom()
{
    for (int i = 101; i <= 110; i++)
    {
        if (isRoomAvailable(i))
        {
            return i;
        }
    }

    return -1;
}

/* Show Available Rooms */

void showAvailableRooms()
{
    printf("\nAvailable Rooms:\n");

    for (int i = 101; i <= 110; i++)
    {
        if (isRoomAvailable(i))
        {
            printf("%d ", i);
        }
    }

    printf("\n");
}

/* Calculate Bill */

float calculateBill(char type[],
                    char category[],
                    int totalDays)
{
    float price = 0;

    if (strcmp(type, "AC") == 0 &&
        strcmp(category, "Single") == 0)
    {
        price = 2000;
    }

    else if (strcmp(type, "AC") == 0 &&
             strcmp(category, "Duplex") == 0)
    {
        price = 3000;
    }

    else if (strcmp(type, "Non-AC") == 0 &&
             strcmp(category, "Single") == 0)
    {
        price = 1000;
    }

    else if (strcmp(type, "Non-AC") == 0 &&
             strcmp(category, "Duplex") == 0)
    {
        price = 1500;
    }

    return price * totalDays;
}

/* Add Booking */

void addBooking()
{
    int room;

    room = getAvailableRoom();

    if (room == -1)
    {
        printf("No Rooms Available\n");
        return;
    }

    hotel[count].roomNumber = room;

    printf("\nRoom Allocated : %d\n",
           hotel[count].roomNumber);

    printf("Enter Name: ");
    scanf(" %[^\n]", hotel[count].name);

    printf("Enter Phone Number: ");
    scanf("%s", hotel[count].phone);

    printf("Enter Check-In Date: ");
    scanf("%d", &hotel[count].checkIn);

    printf("Enter Check-Out Date: ");
    scanf("%d", &hotel[count].checkOut);

    if (hotel[count].checkOut <= hotel[count].checkIn)
    {
        printf("Invalid Dates\n");
        return;
    }

    hotel[count].totalDays =
        hotel[count].checkOut -
        hotel[count].checkIn;

    printf("Enter Room Type (AC / Non-AC): ");
    scanf("%s", hotel[count].type);

    if (strcmp(hotel[count].type, "AC") != 0 &&
        strcmp(hotel[count].type, "Non-AC") != 0)
    {
        printf("Invalid Room Type\n");
        return;
    }

    printf("Enter Room Category (Single / Duplex): ");
    scanf("%s", hotel[count].category);

    if (strcmp(hotel[count].category, "Single") != 0 &&
        strcmp(hotel[count].category, "Duplex") != 0)
    {
        printf("Invalid Category\n");
        return;
    }

    hotel[count].bill =
        calculateBill(hotel[count].type,
                      hotel[count].category,
                      hotel[count].totalDays);

    printf("\n========== BILL DETAILS ==========\n");

    printf("Room Number : %d\n",
           hotel[count].roomNumber);

    printf("Customer    : %s\n",
           hotel[count].name);

    printf("Check-In    : %d\n",
           hotel[count].checkIn);

    printf("Check-Out   : %d\n",
           hotel[count].checkOut);

    printf("Total Days  : %d\n",
           hotel[count].totalDays);

    printf("Bill        : %.2f\n",
           hotel[count].bill);

    count++;

    saveToFile();

    printf("\nBooking Added Successfully\n");
}

/* View Bookings */

void viewBookings()
{
    if (count == 0)
    {
        printf("No Bookings Available\n");
        return;
    }

    for (int i = 0; i < count; i++)
    {
        printf("\n========== BOOKING ==========\n");

        printf("Room Number : %d\n",
               hotel[i].roomNumber);

        printf("Name        : %s\n",
               hotel[i].name);

        printf("Phone       : %s\n",
               hotel[i].phone);

        printf("Check-In    : %d\n",
               hotel[i].checkIn);

        printf("Check-Out   : %d\n",
               hotel[i].checkOut);

        printf("Total Days  : %d\n",
               hotel[i].totalDays);

        printf("Type        : %s\n",
               hotel[i].type);

        printf("Category    : %s\n",
               hotel[i].category);

        printf("Bill        : %.2f\n",
               hotel[i].bill);
    }
}

/* Search Booking */

void searchBooking()
{
    int room;

    printf("Enter Room Number: ");
    scanf("%d", &room);

    for (int i = 0; i < count; i++)
    {
        if (hotel[i].roomNumber == room)
        {
            printf("\n========== BOOKING FOUND ==========\n");

            printf("Room Number : %d\n",
                   hotel[i].roomNumber);

            printf("Name        : %s\n",
                   hotel[i].name);

            printf("Phone       : %s\n",
                   hotel[i].phone);

            printf("Bill        : %.2f\n",
                   hotel[i].bill);

            return;
        }
    }

    printf("Booking Not Found\n");
}

/* Cancel Booking */

void cancelBooking()
{
    int room;

    printf("Enter Room Number To Cancel: ");
    scanf("%d", &room);

    for (int i = 0; i < count; i++)
    {
        if (hotel[i].roomNumber == room)
        {
            for (int j = i; j < count - 1; j++)
            {
                hotel[j] = hotel[j + 1];
            }

            count--;

            saveToFile();

            printf("Booking Cancelled Successfully\n");

            return;
        }
    }

    printf("Booking Not Found\n");
}

/* Admin Menu */

void adminMenu()
{
    int choice;

    while (1)
    {
        printf("\n========== ADMIN PANEL ==========\n");

        printf("1. View All Bookings\n");
        printf("2. View Available Rooms\n");
        printf("3. Search Booking\n");
        printf("4. Cancel Booking\n");
        printf("5. Logout\n");

        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                viewBookings();
                break;

            case 2:
                showAvailableRooms();
                break;

            case 3:
                searchBooking();
                break;

            case 4:
                cancelBooking();
                break;

            case 5:
                return;

            default:
                printf("Invalid Choice\n");
        }
    }
}

/* Customer Signup */

void customerSignup()
{
    printf("\n========== CUSTOMER SIGNUP ==========\n");

    printf("Create Username: ");
    scanf("%s", customers[customerCount].username);

    printf("Create Password: ");
    scanf("%s", customers[customerCount].password);

    customerCount++;

    saveCustomers();

    printf("Signup Successful\n");
}

/* Customer Login */

void customerLogin()
{
    char username[50];
    char password[50];

    int found = 0;

    printf("\n========== CUSTOMER LOGIN ==========\n");

    printf("Enter Username: ");
    scanf("%s", username);

    printf("Enter Password: ");
    scanf("%s", password);

    for (int i = 0; i < customerCount; i++)
    {
        if (strcmp(username,
                   customers[i].username) == 0 &&

            strcmp(password,
                   customers[i].password) == 0)
        {
            found = 1;
            break;
        }
    }

    if (found)
    {
        printf("Login Successful\n");

        customerMenu();
    }

    else
    {
        printf("Invalid Username Or Password\n");
    }
}

/* Customer Menu */

void customerMenu()
{
    int choice;

    while (1)
    {
        printf("\n========== CUSTOMER PANEL ==========\n");

        printf("1. Book Room\n");
        printf("2. Search Booking\n");
        printf("3. Cancel Booking\n");
        printf("4. Logout\n");

        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                addBooking();
                break;

            case 2:
                searchBooking();
                break;

            case 3:
                cancelBooking();
                break;

            case 4:
                return;

            default:
                printf("Invalid Choice\n");
        }
    }
}