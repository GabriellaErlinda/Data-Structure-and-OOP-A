#include <iostream>
#include <string>
#include <cstring> // Include cstring for string comparison

using namespace std;

const int SIZE_ARR = 26;

struct HashTable {
    string username, password;
};

HashTable dataAkun[SIZE_ARR];

// Function to compute the hash index
int HashFunc(string username) {
    return tolower(username[0]) - 'a';
}

void printAll() {
    for (int i = 1; i < SIZE_ARR; i++) {
        cout << i << "|" << dataAkun[i].username << " -- " << dataAkun[i].password  << "|"<< endl;
    }
}

void Menu() {
    while (true) {
        int input_user;

        cout << "MENU" << endl;
        cout << "1. Register" << endl;
        cout << "2. Login" << endl;
        cout << "3. Exit" << endl;

        cout << "Input your choice: " ;
        cin >> input_user;
        cout << endl;

        if (input_user == 1) {
            string username, password;

            cout << "Input Username: ";
            cin >> username;
            cout << "Input Password: ";
            cin >> password;

            int index = HashFunc(username);

            // Check username ada atau ngga
            if (dataAkun[index].username != "") {
                cout << "Username already exists. Please choose another username.\n";
            } else {
                // simpan username and password
                dataAkun[index].username = username;
                dataAkun[index].password = password;
                cout << "===== Registration successful! =====" << endl;
                cout << endl;
            }
        } else if (input_user == 2) {
            string username, password;

            cout << "Input Username: ";
            cin >> username;
            cout << "Input Password: ";
            cin >> password;

            int index = HashFunc(username);

            // Check if the username exists and the password matches
            if (dataAkun[index].username == username && dataAkun[index].password == password) {
                cout << "===== Login successful! =====" << endl;
            } else {
                cout << "WARNING: Incorrect username or password. Login failed." << endl;
            }
        } else if (input_user == 3) {
            printAll();
            cout << "Exiting program...\n";
            break;
        } else {
            cout << "Invalid choice. Please enter a valid option.\n";
        }
    }
}

int main() {
    Menu();
    return 0;
}
