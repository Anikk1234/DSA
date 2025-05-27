//Problem: Counting paths in a tree where the number of consecutive cats doesn't exceed a given value
//Description: Count the number of leaf nodes that can be reached from the root without encountering more than m consecutive cats.

#include <iostream>
#include <vector>
using namespace std;

void dfs(int node, int parent, vector<vector<int>>& tree, vector<int>& cats, 
         int consecutive_cats, int max_cats, int& count) {
    
    // Update consecutive cats
    if (cats[node] == 1) {
        consecutive_cats++;
    } else {
        consecutive_cats = 0; // Reset consecutive count
    }
    
    // Too many consecutive cats
    if (consecutive_cats > max_cats) {
        return;
    }
    
    // Check if it's a leaf node (other than parent)
    bool is_leaf = true;
    for (int neighbor : tree[node]) {
        if (neighbor != parent) {
            is_leaf = false;
            dfs(neighbor, node, tree, cats, consecutive_cats, max_cats, count);
        }
    }
    
    // If it's a leaf, increment the count
    if (is_leaf && node != 1) { // Not the root
        count++;
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<int> cats(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> cats[i];
    }
    
    vector<vector<int>> tree(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        tree[x].push_back(y);
        tree[y].push_back(x);
    }
    
    int count = 0;
    dfs(1, -1, tree, cats, 0, m, count);
    
    cout << count << endl;
    
    return 0;
}

