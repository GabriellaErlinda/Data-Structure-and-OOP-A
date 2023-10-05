#include<iostream>
#include<string>

using namespace std;

typedef struct
{
    string name;
    string gender;
    string nrp;
    int age;
} Mahasiswa;

//2. INPUT DATA
void inputMahasiswa(Mahasiswa mhs[], int &numStudents) 
{
    if (numStudents < 50) {
        cout << "Name: ";
        cin >> mhs[numStudents].name;
        cout << "Gender: ";
        cin >> mhs[numStudents].gender;
        cout << "NRP: ";
        cin >> mhs[numStudents].nrp;
        cout << "Age: ";
        cin >> mhs[numStudents].age;
        cout << endl;
        numStudents++;
    } else {
        cout << "Maximum number of students reached." << endl;
    }
}

//1. DISPLAY DATA
void printMahasiswa(const Mahasiswa mhs[], int numStudents)     
{
    for (int i = 0; i < numStudents; i++) {
        cout << "==== Student " << i+1 << ": ====" << endl;
        cout << "Name: " << mhs[i].name << endl;
        cout << "Gender: " << mhs[i].gender << endl;
        cout << "NRP: " << mhs[i].nrp << endl;
        cout << "Age: " << mhs[i].age << endl;
        cout << endl;
    }
}

//3. DELETE DATA
void deleteMahasiswa(Mahasiswa mhs[], int &numStudents)
{
    if (numStudents > 0) {
        string nameToDelete;
        cout << "Enter the name of the student to delete: ";
        cin.ignore();
        getline(cin, nameToDelete);

        bool found = false;
        for (int i = 0; i < numStudents; i++) {
            if (mhs[i].name == nameToDelete) {
                for (int j = i; j < numStudents - 1; j++) {
                    mhs[j] = mhs[j + 1];
                }

                numStudents--;
                cout << "Student with name '" << nameToDelete << "' has been deleted." << endl;
                found = true;
                break;
            }
        }

        if (!found) {
            cout << "No student with the name '" << nameToDelete << "' found." << endl;
        }
    } else {
        cout << "No students to delete." << endl;
    }
}

//4. CHANGE DATA
void changeMahasiswa(Mahasiswa mhs[], int numStudents)
{
    if (numStudents > 0) {
        string nameToChange;
        cout << "Enter the name of the student to change: ";
        cin.ignore();
        getline(cin, nameToChange);

        bool found = false;
        for (int i = 0; i < numStudents; i++) {
            if (mhs[i].name == nameToChange) {
                cout << "Enter new data for student '" << nameToChange << "':" << endl;
                cout << "Name: ";
                getline(cin, mhs[i].name);
                cout << "Gender: ";
                cin >> mhs[i].gender;
                cout << "NRP: ";
                cin >> mhs[i].nrp;
                cout << "Age: ";
                cin >> mhs[i].age;
                cout << "Data for student '" << nameToChange << "' has been changed." << endl;
                cout << endl;
                found = true;
                break;
            }
        }

        if (!found) {
            cout << "No student with the name '" << nameToChange << "' found." << endl;
        }
    } else {
            cout << "No students to change." << endl;
        }
}

//5. SEARCH DATA
void searchMahasiswa(const Mahasiswa mhs[], int numStudents)
{
    if (numStudents > 0) {
        string nameToSearch;
        cout << "Enter the name of the student to search for: ";
        cin.ignore(); 
        getline(cin, nameToSearch);

        bool found = false;
        for (int i = 0; i < numStudents; i++) {
            if (mhs[i].name == nameToSearch) {
                cout << "==== Data for student '" << nameToSearch << "': ====" << endl;
                cout << "Name: " << mhs[i].name << endl;
                cout << "Gender: " << mhs[i].gender << endl;
                cout << "NRP: " << mhs[i].nrp << endl;
                cout << "Age: " << mhs[i].age << endl;
                cout << endl;
                found = true;
                break; 
            }
        }

        if (!found) {
            cout << "No student with the name '" << nameToSearch << "' found." << endl;
        }
    } else {
        cout << "No students to search." << endl;
    }
}



int main()
{
    const int maxSize = 10;
    Mahasiswa mhs[maxSize];
    int numStudents = 0;

    while (true) {
        cout << "Options:" << endl;
        cout << "1: Display data" << endl;
        cout << "2: Input new data" << endl;
        cout << "3: Delete data" << endl;
        cout << "4: Change data" << endl;
        cout << "5: Search data" << endl;
        cout << "Enter your choice: ";
        
        int choice;
        cin >> choice;

        cout << endl;

        if (choice == 1) {
            printMahasiswa(mhs, numStudents);
        } else if (choice == 2) {
            inputMahasiswa(mhs, numStudents);
        } else if (choice == 3) {
            deleteMahasiswa(mhs, numStudents);
        } else if (choice == 4) {
            changeMahasiswa(mhs, numStudents);
        } else if (choice == 5) {
            searchMahasiswa(mhs, numStudents);
        }

    }

    return 0;
}
