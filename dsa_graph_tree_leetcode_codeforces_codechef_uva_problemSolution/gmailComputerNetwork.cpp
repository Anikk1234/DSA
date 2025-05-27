// Problem: Finding the path from root to leaf in a tree
// Description: Given a tree where each node except the root has one parent, find the path from node 1 to node n.

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> Parent(n + 1);
    Parent[1] = 1;  // Root is its own parent
    
    for (int i = 2; i <= n; i++) {
        cin >> Parent[i];
    }
    
    vector<int> Path;
    int Current = n;
    
    while (Current != 1) {
        Path.push_back(Current);
        Current = Parent[Current];
    }
    
    Path.push_back(1);  // Add the root
    reverse(Path.begin(), Path.end());
    
    for (int Node : Path) {
        cout << Node << " ";
    }
    
    return 0;
}

