#include <iostream>
using namespace std;

struct ElementOfStack {
    int number;
    ElementOfStack* next;
};

ElementOfStack* MainStack = NULL;
ElementOfStack* PositiveStack = NULL;
ElementOfStack* NegativeStack = NULL;

void PushElementToStack(ElementOfStack** top, int num) {
    ElementOfStack* chisl = new ElementOfStack();
    chisl->number = num;
    if (*top == NULL)
        *top = chisl;
    else {
        chisl->next = *top;
        *top = chisl;
    }
}
void DeleteStack(ElementOfStack* top) {
    ElementOfStack* ptr = top;
    while (ptr) {
        top = ptr->next;
        delete[] ptr;
        ptr->next = NULL;
        ptr->number = NULL;
        ptr = ptr->next;
    }
}
void CreationOfPositiveAndNegativeStacks() {
    ElementOfStack* ptr = MainStack;
    while (ptr) {
        if (ptr->number >= 0)
            PushElementToStack(&PositiveStack, ptr->number);
        else 
            PushElementToStack(&NegativeStack, ptr->number);
        ptr = ptr->next;
    }
}
void ShowStack(ElementOfStack* top) {
    ElementOfStack* begin = top;
    if (!begin)
        cout << "The end of stack\n";
    else {
        cout << begin->number << endl;
        ShowStack(top = top->next);
    }
}
void ShowAllStacks() {
    cout << "Main Stack is \n";
    ShowStack(MainStack);
    cout << "Positive Stack is \n";
    ShowStack(PositiveStack);
    cout << "Negative Stack is \n";
    ShowStack(NegativeStack);
} 
int CheckAndSetSize() {
    int size_of_stack;
    do {
        cout << "Set size of Main Stack : ";
        cin >> size_of_stack;
    } while (size_of_stack <= 0);
    return size_of_stack;
}
void SetSizeAndPushElementsToStack() {
    int size_of_stack = CheckAndSetSize();
    int element_to_push;
    cout << "Write elements :\n";
    for (int i = 0; i < size_of_stack; i++) {
        cin >> element_to_push;
        PushElementToStack(&MainStack, element_to_push);
    }
}
int main() {
    SetSizeAndPushElementsToStack();
    CreationOfPositiveAndNegativeStacks();
    ShowAllStacks();
    return 0;
}
