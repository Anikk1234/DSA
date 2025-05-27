// Problem: Track positions of cards with specific colors in a deck
//Description: Simulate operations on a card deck, where querying a color brings the card to the front.

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    
    vector<int> Deck(n);
    unordered_map<int, int> FirstPos;
    
    for (int i = 0; i < n; i++) {
        cin >> Deck[i];
        if (FirstPos.find(Deck[i]) == FirstPos.end()) {
            FirstPos[Deck[i]] = i + 1;  // 1-indexed position
        }
    }
    
    for (int i = 0; i < q; i++) {
        int Color;
        cin >> Color;
        
        int Position = FirstPos[Color];
        cout << Position << " ";
        
        // Update positions for all colors that were before the current one
        for (auto& Pair : FirstPos) {
            if (Pair.second < Position) {
                Pair.second++;
            }
        }
        
        // Move the current color to the front
        FirstPos[Color] = 1;
    }
    
    return 0;
}

