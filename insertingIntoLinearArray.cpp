#include <bits/stdc++.h>
using namespace std;

void insertElement(int LA[], int &N, int K, int ITEM) {
    int J = N;

    while (J >= K) {
        LA[J + 1] = LA[J];

        J = J - 1;
    }

    LA[K] = ITEM;

    N = N + 1;
}

int main() {
    int LA[100];
    int N, K, ITEM;

    cout << "Enter the number of elements in the array: ";
    cin >> N;

    cout << "Enter the elements of the array: \n";
    for (int i = 1; i <= N; i++) {
        cin >> LA[i];
    }

    cout << "Enter the position (K) where the item should be inserted: ";
    cin >> K;
    cout << "Enter the item (ITEM) to be inserted: ";
    cin >> ITEM;



    insertElement(LA, N, K, ITEM);

    cout << "Array after insertion: \n";
    for (int i = 1; i <= N; i++) {
        cout << LA[i] << " ";
    }
    cout << endl;

    return 0;
}

