//Problem: Finding connected components in an undirected graph
// Description: Count the number of connected components in an undirected graph.

#include <iostream>
#include <vector>
#include <string>
using namespace std;

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
    
    void unionSets(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        
        if (rootX == rootY) return;
        
        if (rank[rootX] < rank[rootY]) {
            parent[rootX] = rootY;
        } else if (rank[rootX] > rank[rootY]) {
            parent[rootY] = rootX;
        } else {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
    }
    
    int countComponents(int n) {
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (parent[i] == i) {
                count++;
            }
        }
        return count;
    }
};

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        char maxNode;
        cin >> maxNode;
        cin.ignore(); // Consume newline
        
        int n = maxNode - 'A' + 1;
        DisjointSet ds(n);
        
        string line;
        while (getline(cin, line) && !line.empty()) {
            int u = line[0] - 'A';
            int v = line[1] - 'A';
            ds.unionSets(u, v);
        }
        
        cout << ds.countComponents(n) << endl;
        
        if (t > 0) cout << endl;
    }
    
    return 0;
}
