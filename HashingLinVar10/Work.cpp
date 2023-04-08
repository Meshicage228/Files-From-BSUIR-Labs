#include "Header.h"
#include <iostream>
using namespace std;

struct box {
    int num;
    int index;
    bool priority;
};

int main()
{
    init_hash_table();
    srand(time(NULL));
    cout << "Number of nums <20 : ";
    int n; cin >> n;
    box* arr = new box[n];
    print_table();
    cout << "Array : \n";
    for (int i = 0; i < n; i++) {
        arr[i].num = rand() % 901 + 100;
        cout << i << " ---- " << arr[i].num << endl;
        hash_table_instert(&arr[i]);
    }
    cout << "HashTable :\n";
    print_table();
    cout << "From top to niz : \n"; 
    show_priority(n);
    cout << endl;
    int y;
    cin >> y;
    search_for_box(y);
    return 0;
}