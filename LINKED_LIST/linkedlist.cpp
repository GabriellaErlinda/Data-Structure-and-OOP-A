#include <iostream>

using namespace std;

struct Node {
    int data; //data = angka yang disimpan ke node
    Node* next; //pointer ke next node

    Node(int value) : data(value), next(NULL) {}
};

// define kelas dari linked list
class LinkedList {
private:
    Node* head;
public:
    LinkedList() : head(NULL) {}

    //insert a new element at the end of the list
    void insert(int value) {
        Node* newNode = new Node(value); //make new node
        if (head == NULL) { //if the linked list is empty
            head = newNode; //new node set as the first element
        } else { //if the linked list is not empty
            Node* current = head; //the current set as head
            while (current->next != NULL) { //check throughout the linked list
                current = current->next;
            } //the loop ends when the current->next is NULL, 
              //means that we're at the end of the list
            current->next = newNode; //to connect the last element in linked list to the new element
                                     //so that the new element became the last
        }
    }

    //to insert a value to the desire index
    void insertAt(int value, int index) {
        Node* newNode = new Node(value); //make new node containing value we want to insert
        if (index == 0) { //it means that the user wants to input the element in index 0
            newNode->next = head;
            head = newNode;
        } else { //if user wants to put it in the other index
            Node* current = head; //to points the first element
            int currentIndex = 0; //to track current position in our linked list
            while (current != NULL && currentIndex < index - 1) {
            //the loop goes on to find the position before the index that user's input
                current = current->next;
                currentIndex++;
            }
            newNode->next = current->next;
            current->next = newNode;
        }
    }

    // display the list
    void display() {
        Node* current = head;
        while (current != NULL) {
            cout << current->data << " - ";
            current = current->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    LinkedList myList;
    int choice;

    while (true) {
        cout << "Linked List Options:" << endl;
        cout << "1. Display Linked List" << endl;
        cout << "2. Insert a Number at a Specific Index" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cout << "=========================================" << endl;

        if (choice == 1) {
            cout << "Linked List: ";
            myList.display();
            cout << "=========================================" << endl;
        } else if (choice == 2) {
            int value, index;
            cout << "Enter the number to insert: ";
            cin >> value;
            cout << "Choose the index to put the new number: ";
            cin >> index;
            myList.insertAt(value, index);
            cout << endl;
        } else if (choice == 3) {
            cout << "========== Exiting the program ==========" << endl;
            break;
        } else {
            cout << "BUDAYAKAN MEMBACA PILIHAN" << endl;
        }
    }

    return 0;
}
