# 🏨 Hotel Hogwarts - Hotel Room Booking System in C

## 📌 Project Overview

Hotel Hogwarts is a command line based Hotel Room Booking System developed using the C programming language. The application provides separate Admin and Customer modules with secure login functionality. It supports automatic room allocation, room booking, booking search, cancellation, bill calculation based on room type and category, and permanent data storage using file handling. The project was developed using core C concepts such as structures, arrays, functions, header files, string handling, and modular programming.

The system supports:
- Customer Signup/Login
- Admin Login
- Automatic Room Allocation
- Booking Management
- Search and Cancellation
- File Handling for Data Storage
- Bill Calculation Based on Room Type

---

# 🚀 Features

## 👨‍💼 Admin Module
- Secure Admin Login
- View All Bookings
- View Available Rooms
- Search Booking
- Cancel Booking

---

## 👤 Customer Module
- Customer Signup
- Customer Login
- Book Room
- Search Booking
- Cancel Booking

---

# 🏨 Room Features

## Room Types
- AC
- Non-AC

## Room Categories
- Single
- Duplex

---

# 🤖 Automatic Room Allocation

The system automatically allocates the lowest available room number in ascending order.

Example:

101 → 102 → 103 ...

This avoids duplicate bookings and improves booking management.

---

# 💰 Billing System

Bill is calculated based on:
- Room Type
- Room Category
- Total Stay Duration

## Pricing Table

| Room Type | Category | Price Per Day |
|------------|-----------|----------------|
| AC | Single | 2000 |
| AC | Duplex | 3000 |
| Non-AC | Single | 1000 |
| Non-AC | Duplex | 1500 |

---

# 📅 Date-Based Booking

The project uses:
- Check-In Date
- Check-Out Date

Total days are calculated automatically.

---

# 🧠 Concepts Used

- Structures
- Arrays
- Functions
- File Handling
- Header Files
- String Handling
- Authentication
- Modular Programming

---

# 📂 Project Structure

```text
Hotel_Hogwarts/
│
├── main.c
├── hotel.c
├── hotel.h
├── file.c
├── file.h
│
├── hotel.txt
├── customer.txt
└── README.md
<<<<<<< HEAD
```

=======
>>>>>>> 162284e18f1a161b958b5008f9140b7e07f9e4c5
