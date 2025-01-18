#include <bits/stdc++.h>
using namespace std;

void deleteElement(int LA[], int &N, int K) {
    int ITEM = LA[K];

    for (int J = K; J < N; J++) {
        LA[J] = LA[J + 1];
    }

    N = N - 1;

    cout << "Deleted item: " << ITEM << endl;
}

int main() {
    int LA[100];
    int N, K;

    cout << "Enter the number of elements in the array: ";
    cin >> N;

    cout << "Enter the elements of the array: \n";
    for (int i = 1; i <= N; i++) {
        cin >> LA[i];
    }

    cout << "Enter the position (K) of the item to be deleted: ";
    cin >> K;



    deleteElement(LA, N, K);

    cout << "Array after deletion: \n";
    for (int i = 1; i <= N; i++) {
        cout << LA[i] << " ";
    }
    cout << endl;

    return 0;
}

