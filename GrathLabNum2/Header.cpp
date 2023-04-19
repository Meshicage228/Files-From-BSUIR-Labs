#include "Header.h"
#include <iostream>
using namespace std;

#define N 9

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
        ptr->head[i] = NULL;
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
// TODO create new delete algorithm for Vertex and Node functions
void DeleteNodes(LinkedGrath* grath, int key) {
    for (int i = 1; i < N; i++) {
        cout << "pip " << endl;
        if (grath->head[i] == NULL) continue;
        Element* ptr = grath->head[i];
        Element* nextp = ptr;
        bool flag = true;
        while (true) {
            nextp = ptr->next;
            if (nextp->priority == key) {
                do {
                    cout << "pio" << endl;
                    nextp = nextp->next;             
                } while (nextp->priority == key && nextp->next); 
                if (nextp->next == NULL) {
                    if (ptr->next->priority == key && nextp->priority == key) {
                        ptr->next = NULL;
                        break;
                    }
                }
                if(nextp->next == NULL && nextp->priority != key) {
                    ptr->next = nextp;
                    cout << "pio2" << endl;
                    ptr = ptr->next;
                }
            }
            else {
                ptr = ptr->next;
            }
            if (ptr == NULL || nextp->next == NULL) break;
        }
    }
}
void DeleteVertex(LinkedGrath* grath, int key) {
    for (int i = 1; i < N; i++) {
        cout << "pip " << endl;
        if (grath->head[i] == NULL) continue;
        Element* ptr = grath->head[i];
        Element* nextp = ptr->next;
        if (ptr->source == key) {
            grath->head[i] = NULL;
        }
        else {
            while (true) {
                nextp = ptr->next;
                if (nextp->destination == key) {
                    do {
                        cout << "pio" << endl;
                        nextp = nextp->next;
                    } while (nextp->destination == key && nextp);
                    ptr->next = nextp;
                    cout << "pio2" << endl;
                    ptr = ptr->next;
                }
                else {
                    ptr = ptr->next;
                }
                if (ptr == NULL || nextp->next == NULL) break;
            }
        }
    }
}


