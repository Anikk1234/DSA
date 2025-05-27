// Problem: Finding a node that is trusted by all other nodes but trusts nobody
// Description: Identify the person who is trusted by everyone else but doesn't trust anyone.

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> trustCount(n + 1, 0);
        
        for (auto& relation : trust) {
            trustCount[relation[0]]--; // Person who trusts others
            trustCount[relation[1]]++; // Person who is trusted
        }
        
        for (int i = 1; i <= n; i++) {
            if (trustCount[i] == n - 1) {
                return i;
            }
        }
        
        return -1;
    }
};

// Example usage
int main() {
    Solution sol;
    vector<vector<int>> trust = {{1,3},{2,3}};
    cout << sol.findJudge(3, trust) << endl;  // Output: 3
    return 0;
}
