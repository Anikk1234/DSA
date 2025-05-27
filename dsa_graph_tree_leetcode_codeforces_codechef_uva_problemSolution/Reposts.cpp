// Problem: Finding the maximum depth in a repost chain
// Description: Given a chain of reposts, find the maximum chain length.

#include <bits/stdc++.h>
using namespace std;

string ToLower(string s) {
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    return s;
}

int DFS(string Node, unordered_map<string, vector<string>>& Graph) {
    int MaxDepth = 0;
    for (const string& Child : Graph[Node]) {
        MaxDepth = max(MaxDepth, DFS(Child, Graph));
    }
    return MaxDepth + 1;
}

int main() {
    int n;
    cin >> n;
    
    unordered_map<string, vector<string>> Graph;
    
    for (int i = 0; i < n; i++) {
        string Name1, Reposted, Name2;
        cin >> Name1 >> Reposted >> Name2;
        
        Name1 = ToLower(Name1);
        Name2 = ToLower(Name2);
        
        Graph[Name2].push_back(Name1);
    }
    
    cout << DFS("polycarp", Graph) << endl;
    
    return 0;
}
