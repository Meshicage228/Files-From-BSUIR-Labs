#include "Header.h"
#include <iostream>
using namespace std;

struct Element {
    int number;
    int index;
    bool priority;
};
int SetSizeOfArray() {
    int size = 0;
    do {
        cout << "Enter the number of random numbers, which < 20 :";
        cin >> size;
    } while (size < 0 || size >= 20);
    return size;
}
void CreateHashTable(int size) {
    InitializeHashTable();

    Element* arr = new Element[size];

    PrintHashTable();

    cout << "Array : \n";
    for (int i = 0; i < size; i++) {
        arr[i].number = rand() % 1201 + 100;
        cout << i << " ---- " << arr[i].number << endl;
        PushElementToHashTable(&arr[i]);
    }
}
int main() {
    
    srand(time(NULL));
    setlocale(0, "rus");

    int size = SetSizeOfArray();
    CreateHashTable(size);

    do {
        cout << "1.Print HashTable\n2.Delete even nums\n3.Find number in HashTable\n4.Exit\nOption:";
        int option;
        cin >> option;
        cout << endl;
        switch (option) {
        case 1: PrintHashTable();
            break;
        case 2:  deleteEvenNum(); cout << endl;
            break; 
        case 3: { 
            cout << "Write number to search : ";
            int y; cin >> y;
            int index = SearchNumber(y);
            if (index == -1) cout << "There is no such number...\n";
            else cout << "Number " << y << " detected at index :  " << index << endl;
            break;
        }
        case 4: cout << "Exit..."; return 0;
        default: cout << "Wrong operation...\n";
            break;
        }
    } while (true);
}