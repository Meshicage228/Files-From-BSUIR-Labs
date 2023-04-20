#pragma once
struct Element;

void InitializeHashTable();
unsigned int HashingNumber(int);
void PushElementToHashTable(Element*);

void PrintHashTable();
int SearchNumber(int);
void DeleteNumber(int);

void WriteInDescendingOrder(int);
