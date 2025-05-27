//Problem: Create a tree where certain vertices are not direct ancestors of specific vertices
//Description: Construct any valid tree such that for each constraint (a,b,c), vertex b is not on the path from a to c.

#include <bits/stdc++.h>
using namespace std;

void Solve() {
    int n, m;
    cin >> n >> m;
    
    vector<bool> MiddleNode(n + 1, false);
    
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        MiddleNode[b] = true;  // Mark b as a middle node in a constraint
    }
    
    // Find a node that doesn't appear as a middle node in any constraint
    int Center = 1;
    for (int i = 1; i <= n; i++) {
        if (!MiddleNode[i]) {
            Center = i;
            break;
        }
    }
    
    // Create a star tree with center as the root
    for (int i = 1; i <= n; i++) {
        if (i != Center) {
            cout << Center << " " << i << endl;
        }
    }
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        Solve();
    }
    
    return 0;
}

