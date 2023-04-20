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
        cout << "1.Print HashTable\n2.Write numbers in descending order\n3.Find number in HashTable\n4.Delete entered number\n5.Exit\nOption:";
        int option;
        cin >> option;
        cout << endl;
        switch (option) {
        case 1: PrintHashTable();
            break;
        case 2: { cout << "HashIndexes    Keys : \n";  WriteInDescendingOrder(size); cout << endl;
            break; }
        case 3: { cout << "Write number to search : ";
            int y; cin >> y;
            int index = SearchNumber(y);
            if (index == NULL) cout << "There is no such number...\n";
            else cout << "Number " << y << " detected at index :  " << index << endl;
            break;
        }
        case 4: cout << "Write number which you need to delete : "; int x; cin >> x;
            DeleteNumber(x);
            break;
        case 5: cout << "Exit..."; return 0;
        default: cout << "Wrong operation...\n";
            break;
        }
    } while (true);
}
