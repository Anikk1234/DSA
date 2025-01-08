#include <bits/stdc++.h>
using namespace std;


int patternMatching(const string& text, const string& pattern) {
    int R = pattern.length();
    int S = text.length();
    int K = 0; 
    int MAX = S - R;

    while (K <= MAX) {
        bool match = true;
        for (int L = 0; L < R; L++) { 
            if (pattern[L] != text[K + L]) {
                match = false;
                break; 
            }
        }
        if (match) {
            return K;
        }
        K++; 
    }
    return -1;  
}

int main() {
    string text = "Hello, this is a simple example.";
    string pattern = "simple";

    cout << "Text: " << text << endl;
    cout << "Pattern: " << pattern << endl;

    int index = patternMatching(text, pattern);
    if (index != -1) {
        cout << "Pattern found at index " << index << endl;
    } else {
        cout << "Pattern not found." << endl;
    }

    return 0;
}

