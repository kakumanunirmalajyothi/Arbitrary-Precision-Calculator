# Arbitrary Precision Calculator

An **Arbitrary Precision Calculator (APC)** developed in **C Programming** using **Data Structures** to perform arithmetic operations on integers of unlimited length. Unlike standard C data types, this calculator can process very large numbers by storing each digit in a linked list.

---

## 📌 Overview

The project implements arithmetic operations on numbers that exceed the storage capacity of built-in data types (`int`, `long`, `long long`). Each digit is stored in a node of a linked list, enabling calculations with numbers of virtually any size.

---

## ✨ Features

* Addition of large integers
* Subtraction of large integers
* Multiplication of large integers
* Division of large integers
* Supports numbers of arbitrary length
* Handles positive and negative integers
* Efficient digit-by-digit arithmetic using linked lists
* Dynamic memory allocation for large numbers

---

## 🛠 Technologies Used

* C Programming
* Data Structures
* Doubly Linked List
* Dynamic Memory Allocation
* Pointers
* Functions
* Modular Programming
* GCC Compiler

---

## 📂 Project Structure

```text
Arbitrary-Precision-Calculator/
│── main.c
│── apc.c
│── add.c
│── subtract.c
│── multiply.c
│── divide.c
│── list.c
│── list.h
│── Makefile
└── README.md
```

> **Note:** The file names may vary depending on your implementation.

---

## 🚀 How to Compile

Using GCC:

```bash
gcc *.c -o apc
```

or using a Makefile:

```bash
make
```

---

## ▶️ How to Run

```bash
./apc
```

---

## 💻 Sample Execution

```text
Enter First Number  : 987654321987654321987654321
Enter Operator      : +
Enter Second Number : 123456789123456789123456789

Result :
1111111111111111111111111110
```

### Multiplication

```text
Enter First Number  : 999999999999999999
Enter Operator      : *
Enter Second Number : 999999999999999999

Result :
999999999999999998000000000000000001
```

---

## ⚙️ Data Structure Used

The calculator stores each digit of a number in a **Doubly Linked List**.

Example:

```text
Number : 123456

HEAD
 ↓
1 ⇄ 2 ⇄ 3 ⇄ 4 ⇄ 5 ⇄ 6
                     ↑
                   TAIL
```

This representation allows efficient traversal from either end while performing arithmetic operations.

---

## 📖 Learning Outcomes

* Doubly Linked List implementation
* Dynamic Memory Allocation
* Pointer manipulation
* Large integer arithmetic
* Algorithm design
* Modular programming
* Efficient memory management
* Problem-solving using data structures

---

## 🎯 Applications

* Scientific Computing
* Cryptography
* Financial Calculations
* Compiler Design
* High-Precision Mathematical Software
* Competitive Programming
* Big Integer Libraries

---

## 👩‍💻 Author

**Nirmala Jyothi**

* Electronics and Communication Engineering (ECE) Graduate
* Embedded Software Enthusiast
* Skilled in C Programming, Data Structures, Embedded C, Firmware Development, and Microcontrollers

---

## 📄 License

This project is intended for educational and learning purposes.
