#include<string.h>
#include<iostream>

using namespace std;

const int SIZE_ARR=26;

struct HashTable {
    string username, password;
}dataAkun [SIZE_ARR];

//function hash
int HashFunc(string password) {
    return tolower(password[0]) - 97;
}

void printAll() {
    for (int i;i<=26;i++) {
        cout << i << "||" << dataAkun;
    }
}

void Menu() {
    while (true) {
        int input_user;

        cout << "MENU" << endl;
        cout << "1. Register" << endl;
        cout << "2. Login" << endl;
        cout << "3. Exit" << endl;

        cin >> input_user;
        cout << endl;

        if (input_user == 1){
            string username, password;

            cout << "Input Username: " << endl;
            cin >> username;
            cout << "Input Password: " << endl;
            cin >> password;

            int index = HashFunc(password);
            dataAkun[index].username = username;
            dataAkun[index].password = password;
        }
        }
    
}

int main() {
    string password = "Gabriella";
    cout << HashFunc(password) << endl;
}