#include <iostream>
#include <string>
#include <vector>
#include <conio.h> // For hiding password input

using namespace std;

// Simple User class to store username and password
class User {
public:
    string username;
    string password;

    // Constructor to initialize user details
    User(string uname, string pword) {
        username = uname;
        password = pword;
    }
};

// UserManager class to manage users and their actions
class UserManager {
private:
    vector<User> users; // List of all registered users

public:
    // Function to register a new user
    void registerUser() {
        string username, password;

        cout << "Enter Username: ";
        cin >> username;

        // Secure password input
        cout << "Enter Password (hidden): ";
        password = inputPassword();

        // Create a new user and add to the list
        users.push_back(User(username, password));
        cout << "\nUser registered successfully!\n";
    }

    // Function for secure password input
    string inputPassword() {
        string password;
        char ch;
        while ((ch = _getch()) != '\r') { // Read until Enter key
            if (ch == '\b') { // Backspace
                if (!password.empty()) {
                    cout << "\b \b"; // Erase character on screen
                    password.pop_back(); // Remove last character
                }
            } else {
                password += ch; // Add character to password
                cout << '*'; // Display '*' for each character
            }
        }
        cout << endl;
        return password;
    }

    // Function to log in a user
    void loginUser() {
        string username, password;

        cout << "Enter Username: ";
        cin >> username;

        cout << "Enter Password (hidden): ";
        password = inputPassword();

        // Check if the entered username and password match any user
        for (User user : users) {
            if (user.username == username && user.password == password) {
                cout << "\nLogin successful! Welcome, " << username << "!\n";
                return;
            }
        }
        cout << "\nInvalid username or password.\n";
    }

    // Function to display all registered users
    void showUsers() {
        cout << "\nRegistered Users:\n";
        for (User user : users) {
            cout << "- " << user.username << endl;
        }
    }

    // Function to search for a user by username
    void searchUser() {
        string username;
        cout << "Enter Username to Search: ";
        cin >> username;

        for (User user : users) {
            if (user.username == username) {
                cout << "User " << username << " found!\n";
                return;
            }
        }
        cout << "User " << username << " not found.\n";
    }

    // Function to delete a user by username
    void deleteUser() {
        string username;
        cout << "Enter Username to Delete: ";
        cin >> username;

        for (size_t i = 0; i < users.size(); i++) {
            if (users[i].username == username) {
                users.erase(users.begin() + i); // Remove user from list
                cout << "User " << username << " deleted successfully!\n";
                return;
            }
        }
        cout << "User " << username << " not found.\n";
    }
};

// Main function
int main() {
    UserManager userManager; // Create UserManager object
    int choice;

    // Menu loop
    do {
        cout << "\n--- User Management System ---\n";
        cout << "1. Register User\n";
        cout << "2. Login\n";
        cout << "3. Show All Users\n";
        cout << "4. Search User\n";
        cout << "5. Delete User\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        // Perform actions based on user choice
        switch (choice) {
            case 1:
                userManager.registerUser();
                break;
            case 2:
                userManager.loginUser();
                break;
            case 3:
                userManager.showUsers();
                break;
            case 4:
                userManager.searchUser();
                break;
            case 5:
                userManager.deleteUser();
                break;
            case 6:
                cout << "Exiting program. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 6);

    return 0;
}
