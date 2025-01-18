#include <bits/stdc++.h>
using namespace std;

void bubbleSort(int DATA[], int N) {
    for (int K = 1; K <= N - 1; K++) {
        int PTR = 1;

        while (PTR <= N - K) {
            if (DATA[PTR] < DATA[PTR + 1]) {
                int temp = DATA[PTR];
                DATA[PTR] = DATA[PTR + 1];
                DATA[PTR + 1] = temp;
            }

            PTR = PTR + 1;
        }
    }
}

int main() {
    int DATA[100], N;

    cout << "Enter the number of elements in the array: ";
    cin >> N;

    cout << "Enter the elements of the array: \n";
    for (int i = 1; i <= N; i++) {
        cin >> DATA[i];
    }

    bubbleSort(DATA, N);

    cout << "Sorted array in descending order: \n";
    for (int i = 1; i <= N; i++) {
        cout << DATA[i] << " ";
    }
    cout << endl;

    return 0;
}

