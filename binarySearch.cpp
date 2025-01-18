#include <bits/stdc++.h>
using namespace std;

int binarySearch(int DATA[], int LB, int UB, int ITEM) {
    int BEG = LB, END = UB, MID;

    while (BEG <= END) {
        MID = (BEG + END) / 2;

        if (ITEM < DATA[MID]) {
            END = MID - 1;
        } else if (ITEM > DATA[MID]) {
            BEG = MID + 1;
        } else {
            return MID;
        }
    }

    return -1;
}

int main() {
    int DATA[100], N, ITEM;

    cout << "Enter the number of elements in the array: ";
    cin >> N;

    cout << "Enter the sorted elements of the array: \n";
    for (int i = 0; i < N; i++) {
        cin >> DATA[i];
    }

    cout << "Enter the item to search for: ";
    cin >> ITEM;

    int LOC = binarySearch(DATA, 0, N - 1, ITEM);

    if (LOC != -1) {
        cout << "Item found at position: " << LOC + 1 << endl;
    } else {
        cout << "Item not found in the array." << endl;
    }

    return 0;
}

