//Problem: Finding if there's a path from left to right of a 2-row grid avoiding obstacles
//Description: Determine if it's possible to move from the leftmost cell of a 2-row grid to the rightmost cell without stepping on obstacles.

#include <iostream>
#include <vector>
#include <string>
using namespace std;

void solve() {
    int n;
    cin >> n;
    
    string row1, row2;
    cin >> row1 >> row2;
    
    bool possible = true;
    for (int i = 0; i < n; i++) {
        if (row1[i] == '1' && row2[i] == '1') {
            possible = false;
            break;
        }
    }
    
    cout << (possible ? "YES" : "NO") << endl;
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}

