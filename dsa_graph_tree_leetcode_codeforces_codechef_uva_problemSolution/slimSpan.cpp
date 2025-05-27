// Problem: Finding a spanning tree with minimum difference between maximum and minimum edge weights
// Description: For a given graph, find a spanning tree such that the difference between maximum and minimum edge weights is minimized.

#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int from, to, weight;
    
    bool operator<(const Edge& other) const {
        return weight < other.weight;
    }
};

class DisjointSet {
private:
    vector<int> Parent, Rank;
    
public:
    DisjointSet(int n) {
        Parent.resize(n);
        Rank.resize(n, 0);
        
        for (int i = 0; i < n; i++) {
            Parent[i] = i;
        }
    }
    
    int Find(int x) {
        if (Parent[x] != x) {
            Parent[x] = Find(Parent[x]);
        }
        return Parent[x];
    }
    
    bool UnionSets(int x, int y) {
        int RootX = Find(x);
        int RootY = Find(y);
        
        if (RootX == RootY) {
            return false;
        }
        
        if (Rank[RootX] < Rank[RootY]) {
            Parent[RootX] = RootY;
        } else if (Rank[RootX] > Rank[RootY]) {
            Parent[RootY] = RootX;
        } else {
            Parent[RootY] = RootX;
            Rank[RootX]++;
        }
        
        return true;
    }
};

int main() {
    int n, m;
    
    while (cin >> n >> m && (n || m)) {
        vector<Edge> Edges(m);
        
        for (int i = 0; i < m; i++) {
            cin >> Edges[i].from >> Edges[i].to >> Edges[i].weight;
        }
        
        sort(Edges.begin(), Edges.end());
        
        int MinSpan = INT_MAX;
        
        // Try each edge as the starting edge for a MST
        for (int i = 0; i <= m - n + 1; i++) {
            DisjointSet DS(n + 1);  // 1-indexed
            int EdgesAdded = 0;
            int MinWeight = INT_MAX, MaxWeight = 0;
            
            for (int j = i; j < m && EdgesAdded < n - 1; j++) {
                if (DS.UnionSets(Edges[j].from, Edges[j].to)) {
                    EdgesAdded++;
                    MinWeight = min(MinWeight, Edges[j].weight);
                    MaxWeight = max(MaxWeight, Edges[j].weight);
                }
            }
            
            // Check if a spanning tree was formed
            if (EdgesAdded == n - 1) {
                MinSpan = min(MinSpan, MaxWeight - MinWeight);
            }
        }
        
        if (MinSpan == INT_MAX) {
            cout << -1 << endl;
        } else {
            cout << MinSpan << endl;
        }
    }
    
    return 0;
}
