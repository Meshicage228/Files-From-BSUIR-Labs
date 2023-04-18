#include <iostream>
using namespace std;
struct Element {
    int number;
    Element* next;
    bool flag_to_delete;
};
int SIZE = 0; // SolveThis!!!!
typedef Element** head_of_list;
Element* FindEndOfList(head_of_list head) {
    Element* ptr = *head;
    while (ptr->next) ptr = ptr->next;
    return ptr;
}
void AddElementToList(head_of_list head, int num) {
    Element* ptr = new Element();
    ptr->number = num;
    ptr->next = NULL;
    ptr->flag_to_delete = false;
    SIZE++;
    if (*head == NULL)
        *head = ptr;
    else
        FindEndOfList(head)->next = ptr;
}
void PrintList(Element* head) {
    if (!head)
        cout << "the end of list \n";
    else {
        cout << head->number << endl;
        PrintList(head = head->next);
    }
}
void FindAndShowMinAndMaxNumber(head_of_list head) {
    if (*head) {
        Element* ptr = *head;
        Element* minptr = *head;
        Element* maxptr = *head;
        while (ptr) {
            if (minptr->number >= ptr->number) 
                minptr = ptr;
            if (maxptr->number <= ptr->number)
                maxptr = ptr;
            ptr = ptr->next;
        }
        cout << "Min is - " << minptr->number << endl;
        cout << "Max is - " << maxptr->number << endl;
    }
}
bool MarkRepetitions(head_of_list head) {
    Element* firstptr = *head;
    Element* checkptr;
    bool has_repetitions = false;
    while (firstptr) {
        checkptr = firstptr->next;
        while (checkptr) {
            if (firstptr->number == checkptr->number) {
                firstptr->flag_to_delete = true;
                checkptr->flag_to_delete = true;
                has_repetitions = true;
            }
            checkptr = checkptr->next;
        }
        firstptr = firstptr->next;
    }
    return has_repetitions;
}
void PushElementsToUniqueList(Element* source, head_of_list destination) {
    if (source) {
        if (source->flag_to_delete == false)
            AddElementToList(destination, source->number);
        PushElementsToUniqueList(source = source->next, destination);
    }
}
void CreateAndPrintNewList(head_of_list source, head_of_list destination) {
    if (MarkRepetitions(source)) {
        PushElementsToUniqueList(*source, destination);
        PrintList(*destination);
    }
    else cout << "No repetitions found...\n";
}
int CheckAndSetSize() {
    int size_of_list;
    do {
        cout << "Set size of Main List : ";
        cin >> size_of_list;
    } while (size_of_list <= 0);
    return size_of_list;
}
void WriteElementsToList(head_of_list destination) {
    int size_of_list = CheckAndSetSize();
    int element_to_push;
    cout << "Write elements :\n";
    for (int i = 0; i < size_of_list; i++) {
        cin >> element_to_push;
        AddElementToList(destination, element_to_push);
    }
}
int main() {
    setlocale(0, "rus");
    srand(time(NULL));
    Element* List = NULL;
    Element* ListNew = NULL;
    WriteElementsToList(&List);
    FindAndShowMinAndMaxNumber(&List);
    cout << "Main list : \n"; PrintList(List);
    cout << "List without repetitions : \n"; CreateAndPrintNewList(&List, &ListNew);
}
