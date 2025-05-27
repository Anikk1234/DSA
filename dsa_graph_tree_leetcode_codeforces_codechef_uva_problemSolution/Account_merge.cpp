#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;

class DSU {
public:
    vector<int> parent;

    DSU(int n) {
        parent.resize(n);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]); // Path compression
        return parent[x];
    }

    void unite(int x, int y) {
        int xp = find(x);
        int yp = find(y);
        if (xp != yp)
            parent[yp] = xp;
    }
};

vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
    unordered_map<string, int> emailToID;
    unordered_map<string, string> emailToName;
    int id = 0;

    // Step 1: Assign ID and map email to name
    for (auto& account : accounts) {
        string name = account[0];
        for (int i = 1; i < account.size(); i++) {
            string email = account[i];
            if (emailToID.find(email) == emailToID.end()) {
                emailToID[email] = id++;
            }
            emailToName[email] = name;
        }
    }

    // Step 2: Union emails within the same account
    DSU dsu(id);
    for (auto& account : accounts) {
        int firstEmailID = emailToID[account[1]];
        for (int i = 2; i < account.size(); i++) {
            dsu.unite(firstEmailID, emailToID[account[i]]);
        }
    }

    // Step 3: Group emails by their root parent
    unordered_map<int, vector<string>> groups;
    for (auto& [email, idx] : emailToID) {
        int parent = dsu.find(idx);
        groups[parent].push_back(email);
    }

    // Step 4: Build result
    vector<vector<string>> result;
    for (auto& [_, emails] : groups) {
        sort(emails.begin(), emails.end());
        string name = emailToName[emails[0]];
        emails.insert(emails.begin(), name);
        result.push_back(emails);
    }

    return result;
}

// For testing
int main() {
    vector<vector<string>> accounts1 = {
        {"John","johnsmith@mail.com","john_newyork@mail.com"},
        {"John","johnsmith@mail.com","john00@mail.com"},
        {"Mary","mary@mail.com"},
        {"John","johnnybravo@mail.com"}
    };

    vector<vector<string>> result1 = accountsMerge(accounts1);
    cout << "Merged Accounts:\n";
    for (auto& account : result1) {
        for (auto& email : account)
            cout << email << " ";
        cout << endl;
    }

    return 0;
}
