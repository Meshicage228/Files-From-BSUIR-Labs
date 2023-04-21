#include "Header.h"
#include <iostream>
using namespace std;

bool** adjacency_array = new bool* [N];

struct Element {
    int source;
    int destination;
    Element* next;
    int priority;
};
struct LinkedGrath {
    Element* head[N];
};
struct Edge {
    int source_num, dest_num, edge;
};
LinkedGrath* CreateGrath(Edge edges[], int n) {
    LinkedGrath* ptr = new LinkedGrath();
    for (int i = 0; i < N; i++) {
        ptr->head[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        Element* newNode = new Element();

        int main_vertex = edges[i].source_num,
            neighboring_vertex = edges[i].dest_num,
            node = edges[i].edge;

        newNode->destination = neighboring_vertex;
        newNode->source = main_vertex;
        newNode->priority = node;
        newNode->next = ptr->head[main_vertex];
        ptr->head[main_vertex] = newNode;
    }
    return ptr;
}
void PrintGrath(LinkedGrath* LinkedGrath) {

    for (int i = 0; i < N; i++) {
        Element* ptr = LinkedGrath->head[i];
        while (ptr != NULL) {
            cout << i << " -> " << ptr->destination << "(" << ptr->priority << ")" << "  ";
            ptr = ptr->next;
        }
        cout << endl;
    }
    cout << endl;
  
}
void CreateEmptyMatrix() {
    for (int i = 1; i < N; i++) {
        adjacency_array[i] = new bool[N];
        for (int j = 1; j < N; j++) {
            adjacency_array[i][j] = false;
        }
    }
}
void FillMatrixWithData(LinkedGrath* grath){
    for (int i = 1; i < N; i++) {
        if (grath->head[i] == NULL) continue;
        Element* ptr = grath->head[i];
        while (ptr) {
            adjacency_array[i][ptr->destination] = true;
            ptr = ptr->next;
        }
    }
}
void PrintAdjacencyMatrix() {
    for (int i = 1; i < N; i++) {
        for (int j = 1; j < N; j++) {
            cout << adjacency_array[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
void CreateAndShowAdjacencyMatrix(LinkedGrath* grath) {
    CreateEmptyMatrix();
    FillMatrixWithData(grath);
    PrintAdjacencyMatrix();
}
Element* DeleteNodeOrVertexAroundHead(Element* ptrs, int key) {
    Element* ptr = ptrs;
    if (key == DELETE_NODE) {
        while (ptr->priority == key && ptr->next)
            ptr = ptr->next;
        if (ptr->next == NULL && ptr->priority == key)
            ptr = NULL;
    }
    else {
        while ((ptr->source == key || ptr->destination == key) && ptr->next)
            ptr = ptr->next;
        if (ptr->next == NULL && (ptr->source == key || ptr->destination == key))
            ptr = NULL;
    }
     ptrs = ptr;
    return ptrs;
}
void DeleteNode(Element* ptrs, int key) {
    Element* ptr = ptrs;
    Element* nextp = NULL;
        while (ptr->next) {
            nextp = ptr->next;
            if (nextp->priority == key && nextp) {
                while (nextp->priority == key && nextp->next)
                    nextp = nextp->next;
                if (nextp->next == NULL && nextp->priority == key) {
                    ptr->next = NULL; break;
                }
                else {
                    ptr->next = nextp;
                    ptr = nextp;
                }
            }
            else
                ptr = ptr->next;
        }
}
void DeleteVertex(Element* ptrs, int key){
    Element* ptr = ptrs;
    Element* nextp = NULL;
    while (ptr->next) {
        nextp = ptr->next;
        if ((nextp->source == key || nextp->destination == key) && nextp) {
            while ((nextp->source == key || nextp->destination == key) && nextp->next)
                nextp = nextp->next;
            if (nextp->next == NULL && (nextp->source == key || nextp->destination == key)) {
                ptr->next = NULL; break;
            }
            else {
                ptr->next = nextp;
                ptr = nextp;
            }
        }
        else
            ptr = ptr->next;
    }
}
void DeleteVertexOrNode(LinkedGrath* grath, int key) {
    for (int i = 0; i < 10; i++) {
        if (grath->head[i] == NULL)
            continue;
        if (grath->head[i]->priority == key || grath->head[i]->source == key || grath->head[i]->destination== key)
            grath->head[i] = DeleteNodeOrVertexAroundHead(grath->head[i], key);
        if (grath->head[i] != NULL) {
            if (DELETE_NODE == key)
                DeleteNode(grath->head[i], key);
            else 
                DeleteVertex(grath->head[i], key);
        }
    }
}



