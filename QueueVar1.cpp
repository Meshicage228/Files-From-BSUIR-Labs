#include <iostream>
using namespace std;
struct Element {
     int data;
     Element* next;
};
struct QueueController {
     int size;
     Element* front;
     Element* rear;
};
void InitializeQueue(QueueController* queue) {
     queue->size = 0;
     queue->front = NULL;
     queue->rear = NULL;
}
int  QueueIsEmpty(QueueController* queue) {
     return (queue->size == NULL);
}
void AddElementToQueue(QueueController* queue, int num) {
     Element* new_element = new Element();
     new_element->data = num;
     new_element->next = NULL;
     if (!QueueIsEmpty(queue)) {
         queue->rear->next = new_element;
         queue->rear = new_element;
     }
     else
         queue->front = queue->rear = new_element;
     queue->size++;
 }
void DeleteQueue(QueueController* queue) {
     Element* ptr = queue->front;
     queue->front = queue->front->next;
     delete[] ptr;
}
void PrintQueue(Element* queue) {
     if (!queue)
         cout << "the end of queue \n";
     else {
         cout << queue->data << endl;
         PrintQueue(queue = queue->next);
     }
}
void AddEvenNumbersToNewQueue(Element* source, QueueController* destination) {
    if (source != NULL) { 
     if (source->data % 2 == 0)
         AddElementToQueue(destination, source->data);
     AddEvenNumbersToNewQueue(source = source->next, destination);
     }
}
int CheckAndSetSize() {
    int size_of_queue;
    do {
        cout << "Set size of Main Queue : ";
        cin >> size_of_queue;
    } while (size_of_queue <= 0);
    return size_of_queue;
}
void WriteElementsToQueue(QueueController* destination) {
     int size_of_queue = CheckAndSetSize();
     int element_to_push;
     cout << "Write elements :\n";
     for (int i = 0; i < size_of_queue; i++) {
         cin >> element_to_push;
         AddElementToQueue(destination, element_to_push);
     }
}
int main() {
    QueueController* MainQueue = new QueueController();
    QueueController* EvenQueue = new QueueController();
    InitializeQueue(MainQueue);
    InitializeQueue(EvenQueue);
    WriteElementsToQueue(MainQueue);
    AddEvenNumbersToNewQueue(MainQueue->front, EvenQueue);
    cout << "Main que : \n";
    PrintQueue(MainQueue->front);
    cout << "Even que : \n";
    PrintQueue(EvenQueue->front);
    return 0;
}
