# User Management System in C++

## Overview
The **User Management System** is a mini-project designed to demonstrate the use of **Object-Oriented Programming (OOP)** concepts in C++. The program provides basic functionality for user account management, including registration, login, and user data persistence through file handling. The project also includes secure password masking to enhance usability.

This project is ideal for showcasing beginner to intermediate skills in C++ programming and can be integrated into portfolios to highlight knowledge of OOP and file handling.

---

## Features
1. **Register Users**: Create a new user account with a unique username and password.
2. **Login**: Authenticate users by verifying their credentials with secure password masking.
3. **List Users**: Display all registered usernames.
4. **Search User**: Check if a specific user exists in the system.
5. **Delete User**: Remove an existing user account from the system.
6. **Data Persistence**: Save and load user data to/from a file (`users.txt`).

---

## Technologies Used
- **C++**
  - Classes and Objects
  - Encapsulation and Abstraction
  - Vectors for dynamic data storage
  - File handling for data persistence (`fstream`)
  - Password masking using `_getch()` from `<conio.h>`

---

## Code Highlights

### Object-Oriented Programming Concepts
1. **Encapsulation**: The `User` class ensures username and password are private, with access managed through public methods.
2. **Dynamic Data Management**: The `UserManager` class uses a `vector` to manage a dynamic list of users.
3. **Modularity**: Each operation (e.g., registration, login, search, delete) is implemented as a separate method for clarity and reusability.

### File Handling
- The project uses a file (`users.txt`) to persist user data between program runs:
  - **Write Operation**: When a user registers, their details are appended to the file.
  - **Read Operation**: When the program starts, existing user data is loaded into memory.

### Secure Password Input
The `_getch()` function from `<conio.h>` is used to hide password input by displaying `*` instead of the actual characters typed.

---
## Full Source Code
 - Add an admin panel for managing users.
 -  Encrypt passwords to enhance security.
 - Allow users to update their profile information.
 - Add a GUI for better user interaction.

## Example Usage

### Main Menu:
--- User Management System ---

1.Register User
2.Login
3.Show All Users
4.Search User
5.Delete User
6.Exit Enter your choice: 1
Register a User:
Enter Username: alice Enter Password (hidden): ******** User registered successfully!
### Sample `users.txt` File
Below is an example of how the user data is stored in the file:
```plaintext
alice 1234
bob password123

---
