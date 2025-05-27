// Problem: Finding a minimum spanning tree (MST) to save maximum energy
// Description: Calculate the maximum amount of energy that can be saved by disconnecting some roads.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
    int from, to, weight;
    bool operator<(const Edge& other) const {
        return weight < other.weight;
    }
};

class DisjointSet {
private:
    vector<int> parent, rank;
    
public:
    DisjointSet(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }
    
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    
    bool unionSets(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        
        if (rootX == rootY) return false;
        
        if (rank[rootX] < rank[rootY]) {
            parent[rootX] = rootY;
        } else if (rank[rootX] > rank[rootY]) {
            parent[rootY] = rootX;
        } else {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
        
        return true;
    }
};

int main() {
    int m, n;
    while (cin >> m >> n && (m != 0 || n != 0)) {
        vector<Edge> edges(n);
        int totalCost = 0;
        
        for (int i = 0; i < n; i++) {
            cin >> edges[i].from >> edges[i].to >> edges[i].weight;
            totalCost += edges[i].weight;
        }
        
        // Sort edges by weight for Kruskal's algorithm
        sort(edges.begin(), edges.end());
        
        DisjointSet ds(m);
        int mstCost = 0;
        int edgesAdded = 0;
        
        for (const Edge& edge : edges) {
            if (ds.unionSets(edge.from, edge.to)) {
                mstCost += edge.weight;
                edgesAdded++;
                if (edgesAdded == m - 1) break; // MST is complete
            }
        }
        
        cout << totalCost - mstCost << endl;
    }
    
    return 0;
}