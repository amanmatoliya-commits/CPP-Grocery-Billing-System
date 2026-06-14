# 🛒 Apna Grocery Store Billing System

A console-based Grocery Store Billing System developed in **C++** using **Object-Oriented Programming (OOP)** principles.

This project simulates a real grocery store billing workflow where customers can purchase products, specify quantities, receive discounts, and generate detailed bills that are automatically stored for future reference.

---

## ✨ Features

* Product-based billing system
* Quantity and unit management (kg, litre, packet, piece)
* Automatic subtotal calculation
* Discount calculation for eligible purchases
* Grand total generation
* Date and time stamped bills
* Bill history storage using file handling
* Structured OOP design with multiple classes

---

## 🏗️ Project Structure

```text
Cpp-Billing-System
│
├── include
│   ├── product.hpp
│   └── Store.hpp
│
├── src
│   ├── main.cpp
│   ├── product.cpp
│   └── Store.cpp
│
├── bill.txt
├── README.md
└── .gitignore
```

---

## 🧠 Concepts Used

* Classes and Objects
* Encapsulation
* Constructors
* STL Containers
* File Handling
* Modular Programming
* Header and Source File Separation

---

## 🛍️ Available Products

* Sugar
* Milk
* Poha
* Tea
* Coffee
* Tata Salt
* Refined Oil
* Maida
* Amul Butter
* Eggs

---

## 📋 Sample Bill

```text
=========== APNA GROCERY STORE BILL ===========

Sugar               Qty: 2 kg      Price: Rs. 90
Milk                Qty: 1 litre   Price: Rs. 65
Poha                Qty: 2 kg      Price: Rs. 110

-----------------------------------------------
Subtotal: Rs. 265
Discount: Rs. 0
Grand Total: Rs. 265
===============================================
```

---

## 🚀 How to Run

```bash
g++ src/*.cpp -o billing.exe
billing.exe
```

---

## 🎓 Academic Information

**Subject:** Object Oriented Programming Methodology (OOPM)

**Language:** C++

**Purpose:** College mini-project demonstrating practical application of OOP concepts, file handling, and billing system implementation.

---

## 👨‍💻 Author

**Aman Matoliya**

B.Tech Computer Science Engineering
