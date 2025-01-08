#include <iostream>
#include <string>
using namespace std;

// Pattern matching based on Algorithm 3.3
int patternMatching(const string& text, const string& pattern) {
    int R = pattern.length();
    int S = text.length();
    int K = 0; // Initialize K to 0 (1-based indexing in algorithm -> 0-based here)
    int MAX = S - R; // Maximum starting point for matching

    while (K <= MAX) {
        bool match = true;
        for (int L = 0; L < R; L++) { // Check each character of the pattern
            if (pattern[L] != text[K + L]) {
                match = false;
                break; // Mismatch, move to next K
            }
        }
        if (match) {
            return K; // Return the index if pattern is found
        }
        K++; // Increment K
    }
    return -1; // Return -1 if pattern is not found
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

