#include "Header.h"
#include <iostream>

using namespace std;
#define SIZE_TABLE 20

struct Element {
    int number;
    int index;
    bool priority;
};

Element* HashTable[SIZE_TABLE];

unsigned int HashingNumber(int num) {
    int hash_value = 0;
    hash_value = num % SIZE_TABLE;
    return hash_value;
}
void InitializeHashTable() {
    for (int i = 0; i < SIZE_TABLE; i++)
        HashTable[i] = NULL;
}
void PrintHashTable() {
    cout << "The begining of HashTable : \n";
    for (int i = 0; i < SIZE_TABLE; i++) {
        if (HashTable[i] == NULL) 
            cout << i << " ----------- \n";
        else
            cout << i << " " << HashTable[i]->number << endl;
    }
    cout << "The end...\n\n";
}
void PushElementToHashTable(Element* p) {
    int index = HashingNumber(p->number);
    bool flag = true;

    if (HashTable[index] == NULL) {
        HashTable[index] = p;
        HashTable[index]->priority = false;
        p->index = index;
    }
    else {
        do {
            while (index != SIZE_TABLE - 1) {
                if (HashTable[index] == NULL) {
                    HashTable[index] = p;
                    HashTable[index]->priority = false;
                    p->index = index;
                    flag = false;
                    break;
                }
                index++;
            }
            index = 0;
        } while (flag);

    }
}
int SearchNumber(int num) {
    int index = HashingNumber(num);
    bool flag = true;
    int tries = 0;
    do {
        while (index != SIZE_TABLE) {
            if (HashTable[index] == NULL) {
                index++;
                continue;
            }
            if (HashTable[index]->number == num)
                return index;
            index++;
        }
        index = 0;
        tries++;
        if (tries == 2) break;
    } while (flag);
    return NULL;
}
void DeleteNumber(int num) {
    int index = SearchNumber(num);
    if (index == NULL) cout << "The number wasnt found\n";
    else {
        HashTable[index] = NULL;
        cout << "HashTable after delete :\n";
        PrintHashTable();
    }
}
void WriteInDescendingOrder(int size) {
    for (int i = 0; i < size; i++) {
        int k = 0;
        while (k < SIZE_TABLE) {
            if (HashTable[k] == NULL || HashTable[k]->priority == true) k++;
            else if (HashTable[k] != NULL && HashTable[k]->priority == false) break;
            else k++;

        }
        Element* ptr = HashTable[k];
        while (k < SIZE_TABLE) {
            if (HashTable[k] != NULL && HashTable[k]->priority == false)
                if (ptr->number <= HashTable[k]->number)
                    ptr = HashTable[k];
            k++;
        }
        ptr->priority = true;
        cout << "     " << ptr->index << '\t' << '\t' << ptr->number << endl;
    }
    for (int i = 0; i < SIZE_TABLE; i++) {
        if (HashTable[i] != NULL)
            HashTable[i]->priority = false;
    }
}
