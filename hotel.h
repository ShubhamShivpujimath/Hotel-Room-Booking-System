/* ========================= hotel.h ========================= */

#ifndef HOTEL_H
#define HOTEL_H

#define MAX 100

struct Booking
{
    int roomNumber;

    char name[50];
    char phone[15];

    int checkIn;
    int checkOut;
    int totalDays;

    char type[20];
    char category[20];

    float bill;
};

struct Customer
{
    char username[50];
    char password[50];
};

extern struct Booking hotel[MAX];
extern struct Customer customers[MAX];

extern int count;
extern int customerCount;

/* Booking Functions */
void addBooking();
void viewBookings();
void searchBooking();
void cancelBooking();

/* Room Functions */
void showAvailableRooms();
int isRoomAvailable(int roomNumber);
int getAvailableRoom();

/* Bill */
float calculateBill(char type[],
                    char category[],
                    int totalDays);

/* Menu Functions */
void adminMenu();
void customerMenu();

/* Customer Functions */
void customerSignup();
void customerLogin();

#endif