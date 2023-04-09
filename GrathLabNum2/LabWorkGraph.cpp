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
        deleteNodes(gr, key);
    }
    else if (option == 2) {
        deleteVerx(gr, key);
    }
    cout << "Ïîêàçàòü ãðàô ? \n1.Äà\n2.Íåò\nÎïöèÿ: ";
    cin >> choice;
    if (choice == 1) {
        cout << "Ïîëó÷èâøèéñÿ ãðàô : \n";
        printGrath(gr);
    }
    cout << "Ïîêàçàòü ìàòðèöó ñìåæíîñòè ? \n1.Äà\n2.Íåò\nÎïöèÿ: ";
    cin >> choice;
    if (choice == 1) {
        cout << "Ìàòðèöà : \n";
        ShowMatrix(gr);
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
    LinkedGrath* grathnew = createGrath(edges, number_of_elements);
    cout << "Èçíà÷àëüíûé ãðàô : \n";
    printGrath(grathnew);
    cout << "Èçíà÷àëüíàÿ ìàòðèöà ñìåæíîñòè : \n";
    ShowMatrix(grathnew);
    int choice = 0;
    int show_grath;
    do {
        cout << "1.Óäàëèòü ðåáðî 2\n2.Óäàëèòü âåðèøíó N7\nÎïöèÿ:";
        cin >> choice;
        cout << endl;
        switch (choice) {
        case 1: {
            ImplementAndShow(grathnew, 2, 1);
            break;
        }
        case 2: {
            ImplementAndShow(grathnew, 7, 2);
            break;
        }
        default: cout << "No option" << endl; return 0;

        }
    } while (choice > 0 && choice < 4);
    return 0;
}
