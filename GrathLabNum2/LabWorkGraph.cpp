#include <iostream>
#include "Header.h"
using namespace std;

struct Edge {
    int source_num, dest_num, prior;
};
void ImplementAndShow(LinkedGrath* gr, int key, int option) {
    int choice;
    if (option == 1) 
        DeleteVertexOrNode(gr, key);   
    else if (option == 2) 
        DeleteVertexOrNode(gr, key);

    cout << "Show Grath ? \n1.Yes\n2.No\nOption: ";
    cin >> choice;
    if (choice == 1) {
        cout << "Generated Grath : \n";
        PrintGrath(gr);
    }
    cout << "Show adjancency matrix for that Grath ? \n1.Yes\n2.No\nOption: ";
    cin >> choice;
    if (choice == 1) {
        cout << "Matrix : \n";
        CreateAndShowAdjacencyMatrix(gr);
    }
    cout << endl;
}
int main() {
    setlocale(0, "rus");
    Edge edges[] = {
        {1, 2, 3}, {1, 7, 1}, {1, 8, 4}, 
        {2, 1, 3}, {2, 6, 4}, {2, 3, 5}, {2, 7 ,2},
        {3, 2, 5}, {3, 6, 6}, {3, 4, 3},
        {4, 3, 3}, {4, 6, 4}, {4, 5, 8}, {4, 9, 7},
        {5, 1, 3}, {5, 6, 6}, {5, 4, 8}, {5, 9, 7},
        {6, 1, 2}, {6, 2, 4}, {6, 3, 6}, {6, 4, 4}, {6, 5, 4},
        {7, 8, 7}, {7, 1, 2}, {7, 2, 2}, {7, 6, 2}, {7, 5, 3},
        {8, 1, 4}, {8, 7, 7},
        {9, 5, 7}, {9, 4, 3}
    };
    int number_of_elements = sizeof(edges) / sizeof(edges[0]);
    LinkedGrath* grathnew = CreateGrath(edges, number_of_elements);
    cout << "The original graph : \n";
    PrintGrath(grathnew);

    cout << "The original adjancency matrix : \n";
    CreateAndShowAdjacencyMatrix(grathnew);
    int choice = 0;
    do {
        cout << "1.Delete Nodes Number " << DELETE_NODE << "\n2.Delete Vertex Number " << DELETE_VERTEX << "\n3.Exit\nOption :";
        cin >> choice; cout << endl;
        switch (choice) {
        case 1: {
            ImplementAndShow(grathnew, DELETE_NODE, 1);
            break;
        }
        case 2: {
            ImplementAndShow(grathnew, DELETE_VERTEX, 2);
            break;
        }
        default: cout << "No option" << endl; break;
        case 3: cout << "Exist..."; return 0;
        }
    } while (true);
}
