#include <iostream>
#include "Header.h"
using namespace std;
#define N 9
struct Edge {
    int source_num, dest_num, prior;
};
void ImplementAndShow(LinkedGrath* gr, int key, int option) {
    int choice;
    if (option == 1) {
        DeleteNodes(gr, key);
    }
    else if (option == 2) {
        DeleteVertex(gr, key);
    }
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
        {1, 2, 3}, {1, 7, 2}, {1, 8, 4},
        {2, 1, 3}, {2, 7, 2}, {2, 3, 1}, {2, 5 ,4},
        {7, 1, 2}, {7, 2, 2}, {7, 8, 2}, {7, 5, 7},
        {3, 2, 1}, {3, 5, 4}, {3, 4, 3},
        {4, 3, 3}, {4, 5, 2}, {4, 6, 1},
        {5, 3, 4}, {5, 4, 2}, {5, 6, 7}, {5, 7, 7}, {5, 8, 6}, {5, 2 ,4},
        {6, 8, 3}, {6, 4, 1}, {6, 5, 7},
        {8, 1, 4}, {8, 7, 2}, {8, 6, 3}, {8, 5, 6},
    };
    int number_of_elements = sizeof(edges) / sizeof(edges[0]);
    LinkedGrath* grathnew = CreateGrath(edges, number_of_elements);
    cout << "The original graph : \n";
    PrintGrath(grathnew);
    cout << "The original adjancency matrix : \n";
    CreateAndShowAdjacencyMatrix(grathnew);
    int choice = 0;
    do {
        cout << "1.Delete Nodes Number 2 \n2.Delete Vertex N7\n3.Exit\nOption :";
        cin >> choice; cout << endl;
        switch (choice) {
        case 1: {
            ImplementAndShow(grathnew, 2, 1);
            break;
        }
        case 2: {
            ImplementAndShow(grathnew, 7, 2);
            break;
        }
        default: cout << "No option" << endl; break;
        case 3: cout << "Exist..."; return 0;
        }
    } while (true);
}
