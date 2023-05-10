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
     if (HashTable[index] == NULL) return -1;
     else if (HashTable[index]->number == num) return index;
    else {
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
        } while (true);
    }
    return -1;
}
void deleteEvenNum() {
    for (int i = 0; i < SIZE_TABLE; i++) {
        if (HashTable[i] == NULL) continue;
        if (HashTable[i]->number % 2 == 0)
            HashTable[i] = NULL;
    }
    cout << "After delete : \n";
    PrintHashTable();
}