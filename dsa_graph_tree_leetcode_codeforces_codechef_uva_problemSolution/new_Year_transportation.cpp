// Problem: Following a fixed path in a graph to check if a specific cell can be reached
// Description: Determine if it's possible to reach a specific cell by following a fixed sequence of jumps.

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, t;
    cin >> n >> t;
    
    vector<int> portals(n);
    for (int i = 1; i < n; i++) {
        cin >> portals[i];
    }
    
    int current = 1;
    while (current < t) {
        current += portals[current];
    }
    
    cout << (current == t ? "YES" : "NO") << endl;
    
    return 0;
}

