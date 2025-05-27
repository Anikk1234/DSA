// Problem: Finding the maximum capacity path in a graph
// Description: Find the maximum weight path between two cities in a road network.

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <string>
#include <climits>
#include <algorithm>
using namespace std;

int main() {
    int n, r, scenario = 1;
    
    while (cin >> n >> r && (n != 0 || r != 0)) {
        unordered_map<string, int> cityIndex;
        vector<string> cityName;
        int cityCount = 0;
        
        vector<vector<int>> capacity(n, vector<int>(n, 0));
        
        for (int i = 0; i < r; i++) {
            string c1, c2;
            int cap;
            cin >> c1 >> c2 >> cap;
            
            if (cityIndex.find(c1) == cityIndex.end()) {
                cityIndex[c1] = cityCount++;
                cityName.push_back(c1);
            }
            
            if (cityIndex.find(c2) == cityIndex.end()) {
                cityIndex[c2] = cityCount++;
                cityName.push_back(c2);
            }
            
            int idx1 = cityIndex[c1];
            int idx2 = cityIndex[c2];
            
            capacity[idx1][idx2] = capacity[idx2][idx1] = max(capacity[idx1][idx2], cap);
        }
        
        string start, end;
        cin >> start >> end;
        int s = cityIndex[start];
        int e = cityIndex[end];
        
        // Dijkstra's algorithm for maximum capacity path
        vector<int> maxCapacity(n, 0);
        vector<bool> visited(n, false);
        maxCapacity[s] = INT_MAX;
        
        priority_queue<pair<int, int>> pq;
        pq.push({INT_MAX, s});
        
        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop();
            
            if (visited[u]) continue;
            visited[u] = true;
            
            if (u == e) break;
            
            for (int v = 0; v < n; v++) {
                if (capacity[u][v] > 0) {
                    int newCap = min(maxCapacity[u], capacity[u][v]);
                    if (newCap > maxCapacity[v]) {
                        maxCapacity[v] = newCap;
                        pq.push({newCap, v});
                    }
                }
            }
        }
        
        cout << "Scenario #" << scenario++ << endl;
        cout << maxCapacity[e] << " tons" << endl << endl;
    }
    
    return 0;
}

