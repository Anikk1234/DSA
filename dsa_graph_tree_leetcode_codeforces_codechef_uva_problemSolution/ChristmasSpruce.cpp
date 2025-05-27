// Problem: Checking if a tree is a spruce
// Description: A vertex is a leaf if it has no children. A tree is a spruce if every non-leaf vertex has at least 3 leaf children.

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<vector<int>> Children(n + 1);
    
    for (int i = 2; i <= n; i++) {
        int Parent;
        cin >> Parent;
        Children[Parent].push_back(i);
    }
    
    for (int i = 1; i <= n; i++) {
        if (!Children[i].empty()) {  // Non-leaf vertex
            int LeafCount = 0;
            for (int Child : Children[i]) {
                if (Children[Child].empty()) {  // Child is a leaf
                    LeafCount++;
                }
            }
            if (LeafCount < 3) {
                cout << "No" << endl;
                return 0;
            }
        }
    }
    
    cout << "Yes" << endl;
    
    return 0;
}

