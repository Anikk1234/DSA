// Problem: Finding the maximum depth in an employee hierarchy
// Description: Given the supervisor relationships, determine the minimum number of groups needed.

#include <bits/stdc++.h>
using namespace std;

int DFS(int Node, const vector<vector<int>>& Subordinates) {
    int MaxDepth = 0;
    for (int Sub : Subordinates[Node]) {
        MaxDepth = max(MaxDepth, DFS(Sub, Subordinates));
    }
    return MaxDepth + 1;
}

int main() {
    int n;
    cin >> n;
    
    vector<int> Managers(n + 1);
    vector<vector<int>> Subordinates(n + 1);
    
    for (int i = 1; i <= n; i++) {
        cin >> Managers[i];
        if (Managers[i] != -1) {
            Subordinates[Managers[i]].push_back(i);
        }
    }
    
    int MaxDepth = 0;
    for (int i = 1; i <= n; i++) {
        if (Managers[i] == -1) {  // This is a root employee
            MaxDepth = max(MaxDepth, DFS(i, Subordinates));
        }
    }
    
    cout << MaxDepth << endl;
    
    return 0;
}

