// Problem: Find the minimum cost to connect cities with roads or a state highway
// Description: Given cities and distances between them, find the minimum cost to connect all cities.

#include <bits/stdc++.h>
using namespace std;

struct City {
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
    
    void UnionSets(int x, int y) {
        int RootX = Find(x);
        int RootY = Find(y);
        
        if (RootX == RootY) {
            return;
        }
        
        if (Rank[RootX] < Rank[RootY]) {
            Parent[RootX] = RootY;
        } else if (Rank[RootX] > Rank[RootY]) {
            Parent[RootY] = RootX;
        } else {
            Parent[RootY] = RootX;
            Rank[RootX]++;
        }
    }
};

double Dist(const City& a, const City& b) {
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

int main() {
    int t;
    cin >> t;
    
    for (int Scenario = 1; Scenario <= t; Scenario++) {
        int n, r;
        cin >> n >> r;
        
        vector<City> Cities(n);
        for (int i = 0; i < n; i++) {
            cin >> Cities[i].x >> Cities[i].y;
        }
        
        // Create all edges between cities
        vector<Edge> Edges;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                double d = Dist(Cities[i], Cities[j]);
                Edges.push_back({i, j, d});
            }
        }
        
        // Sort edges by weight
        sort(Edges.begin(), Edges.end());
        
        // Kruskal's algorithm for MST
        DisjointSet DS(n);
        double RoadCost = 0.0;
        int StateComponents = n;
        
        for (const Edge& Edge : Edges) {
            if (DS.Find(Edge.from) != DS.Find(Edge.to)) {
                // If distance <= r, it's a road within a state
                if (Edge.weight <= r) {
                    DS.UnionSets(Edge.from, Edge.to);
                    RoadCost += Edge.weight;
                    StateComponents--;
                } else {
                    break;  // We'll connect remaining components using the state highway
                }
            }
        }
        
        // Calculate number of states needed (each connected component needs one state)
        int States = 0;
        for (int i = 0; i < n; i++) {
            if (DS.Find(i) == i) {
                States++;
            }
        }
        
        double RailwayCost = 0.0;
        if (States > 1) {
            // Create a new graph with states as nodes
            vector<int> StateRep(n);
            for (int i = 0; i < n; i++) {
                StateRep[DS.Find(i)] = i;
            }
            
            // Find minimum spanning tree for states
            vector<Edge> StateEdges;
            for (int i = 0; i < n; i++) {
                if (DS.Find(i) == i) {
                    for (int j = i + 1; j < n; j++) {
                        if (DS.Find(j) == j) {
                            double d = Dist(Cities[StateRep[i]], Cities[StateRep[j]]);
                            StateEdges.push_back({i, j, d});
                        }
                    }
                }
            }
            
            sort(StateEdges.begin(), StateEdges.end());
            
            DisjointSet StateDS(n);
            for (const Edge& Edge : StateEdges) {
                if (StateDS.Find(Edge.from) != StateDS.Find(Edge.to)) {
                    StateDS.UnionSets(Edge.from, Edge.to);
                    RailwayCost += Edge.weight;
                }
            }
        }
        
        cout << "Case #" << Scenario << ": " << States << " " << fixed;
        cout.precision(0);
        cout << round(RoadCost) << " " << round(RailwayCost) << endl;
    }
    
    return 0;
}

