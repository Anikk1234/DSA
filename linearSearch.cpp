#include <bits/stdc++.h>
using namespace std;

void linearSearch(int DATA[], int &N, int ITEM, int &LOC) {
    DATA[N + 1] = ITEM;

    LOC = 1;

    while (DATA[LOC] != ITEM) {
        LOC = LOC + 1;
    }

    if (LOC == N + 1) {
        LOC = 0;
    }
}

int main() {
    int DATA[100], N, ITEM, LOC;

    cout << "Enter the number of elements in the array: ";
    cin >> N;

    cout << "Enter the elements of the array: \n";
    for (int i = 1; i <= N; i++) {
        cin >> DATA[i];
    }

    cout << "Enter the item to search for: ";
    cin >> ITEM;

    linearSearch(DATA, N, ITEM, LOC);

    if (LOC != 0) {
        cout << "Item found at position: " << LOC << endl;
    } else {
        cout << "Item not found in the array." << endl;
    }

    return 0;
}

