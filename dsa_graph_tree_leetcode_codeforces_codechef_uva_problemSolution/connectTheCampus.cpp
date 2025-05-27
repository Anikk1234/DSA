// Problem: Find the minimum cost to connect all buildings on a campus
// Description: Given buildings and some existing connections, find the minimum additional cost to connect all buildings.

#include <bits/stdc++.h>
using namespace std;

struct Building {
    int x, y;
};

struct Edge {
    int from, to;
    double weight;
    
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

double Dist(const Building& a, const Building& b) {
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

int main() {
    int n;
    while (cin >> n) {
        vector<Building> Buildings(n + 1);  // 1-indexed
        
        for (int i = 1; i <= n; i++) {
            cin >> Buildings[i].x >> Buildings[i].y;
        }
        
        int m;
        cin >> m;
        
        DisjointSet DS(n + 1);
        for (int i = 0; i < m; i++) {
            int a, b;
            cin >> a >> b;
            DS.UnionSets(a, b);
        }
        
        // Create all potential edges between buildings
        vector<Edge> Edges;
        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                double d = Dist(Buildings[i], Buildings[j]);
                Edges.push_back({i, j, d});
            }
        }
        
        // Sort edges by weight
        sort(Edges.begin(), Edges.end());
        
        // Kruskal's algorithm for MST, but only consider edges that don't already exist
        double AdditionalCost = 0.0;
        for (const Edge& Edge : Edges) {
            if (DS.UnionSets(Edge.from, Edge.to)) {
                AdditionalCost += Edge.weight;
            }
        }
        
        cout << fixed;
        cout.precision(2);
        cout << AdditionalCost << endl;
    }
    
    return 0;
}

