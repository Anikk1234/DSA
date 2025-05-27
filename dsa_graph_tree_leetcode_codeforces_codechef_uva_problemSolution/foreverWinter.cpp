//Problem: Identifying a specific tree structure
//Description: Find parameters in a tree structure that follows a specific pattern.

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    
    vector<int> degree(n + 1, 0);
    
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        degree[u]++;
        degree[v]++;
    }
    
    map<int, int> freq;
    for (int i = 1; i <= n; i++) {
        if (degree[i] > 0) {
            freq[degree[i]]++;
        }
    }
    
    int x = 0, y = 0;
    
    // Find y (degree of central vertices)
    for (auto& [deg, count] : freq) {
        if (count == 1) {
            y = deg;
        }
    }
    
    // Find x (number of leaves connected to each branch vertex)
    for (auto& [deg, count] : freq) {
        if (deg == 1) {
            x = count / y;
            break;
        }
    }
    
    cout << x << " " << y << endl;
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}

