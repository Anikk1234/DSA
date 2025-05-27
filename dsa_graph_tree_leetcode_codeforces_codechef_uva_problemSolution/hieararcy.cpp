//Problem: Finding minimum cost to establish a hierarchy
//Description: Given a set of employees and potential supervisor relationships with costs, find the minimum cost to establish a valid hierarchy.

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> Qualification(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> Qualification[i];
    }
    
    int m;
    cin >> m;
    
    vector<vector<pair<int, int>>> Subordinates(n + 1);  // [boss] -> [(subordinate, cost)]
    vector<bool> HasBoss(n + 1, false);
    
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        Subordinates[a].push_back({b, c});
        HasBoss[b] = true;
    }
    
    // Count employees without a boss (should be exactly 1 for a valid hierarchy)
    int RootCount = 0;
    for (int i = 1; i <= n; i++) {
        if (!HasBoss[i]) {
            RootCount++;
        }
    }
    
    if (RootCount != 1) {
        cout << -1 << endl;
        return 0;
    }
    
    // Find minimum cost for each employee to have a boss
    long long TotalCost = 0;
    for (int i = 1; i <= n; i++) {
        if (HasBoss[i]) {
            int MinCost = INT_MAX;
            for (int j = 1; j <= n; j++) {
                for (auto& Sub : Subordinates[j]) {
                    if (Sub.first == i) {
                        MinCost = min(MinCost, Sub.second);
                    }
                }
            }
            if (MinCost == INT_MAX) {
                cout << -1 << endl;
                return 0;
            }
            TotalCost += MinCost;
        }
    }
    
    cout << TotalCost << endl;
    
    return 0;
}

