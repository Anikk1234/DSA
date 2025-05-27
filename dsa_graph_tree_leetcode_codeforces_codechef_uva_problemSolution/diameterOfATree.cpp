// Problem: Find the diameter (longest path) in an undirected tree
// Description: Diameter of a tree is the length of the longest path between any two nodes in the tree.

#include <bits/stdc++.h>
using namespace std;

void DFS(int Node, vector<vector<pair<int, int>>>& Tree, vector<int>& Dist) {
    for (auto& P : Tree[Node]) {
        int Next = P.first;
        int Weight = P.second;
        
        if (Dist[Next] == -1) {
            Dist[Next] = Dist[Node] + Weight;
            DFS(Next, Tree, Dist);
        }
    }
}

pair<int, int> FarthestNode(int Start, vector<vector<pair<int, int>>>& Tree, int n) {
    vector<int> Dist(n + 1, -1);
    Dist[Start] = 0;
    
    DFS(Start, Tree, Dist);
    
    int MaxDist = 0;
    int Farthest = Start;
    
    for (int i = 1; i <= n; i++) {
        if (Dist[i] > MaxDist) {
            MaxDist = Dist[i];
            Farthest = i;
        }
    }
    
    return {Farthest, MaxDist};
}

int main() {
    int n;
    cin >> n;
    
    vector<vector<pair<int, int>>> Tree(n + 1);
    
    for (int i = 1; i < n; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        Tree[u].push_back({v, w});
        Tree[v].push_back({u, w});
    }
    
    // Find the farthest node from any node (e.g., node 1)
    auto P1 = FarthestNode(1, Tree, n);
    
    // Find the farthest node from P1.first
    auto P2 = FarthestNode(P1.first, Tree, n);
    
    cout << P2.second << endl;
    
    return 0;
}
