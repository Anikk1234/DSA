#include <bits/stdc++.h>

using namespace std;


void buildPatternTable(const string& pattern, vector<int>& table) {
    int m = pattern.length();
    table[0] = 0;
    int j = 0;

    for (int i = 1; i < m; i++) {
        if (pattern[i] == pattern[j]) {
            j++;
            table[i] = j;
        } else {
            if (j != 0) {
                j = table[j - 1];
                i--;
            } else {
                table[i] = 0;
            }
        }
    }
}

int fastPatternMatching(const string& text, const string& pattern) {
    int n = text.length();
    int m = pattern.length();

    vector<int> table(m);
    buildPatternTable(pattern, table);

    int i = 0;
    int j = 0;
    while (i < n) {
        if (text[i] == pattern[j]) {
            i++;
            j++;
        }

        if (j == m) {

            return i - j;
        } else if (i < n && text[i] != pattern[j]) {
            if (j != 0) {
                j = table[j - 1];
            } else {
                i++;
            }
        }
    }

    return -1;
}

int main() {
    string text = "Hello, this is a simple example.";
    string pattern = "simple";

    cout << "Text: " << text << endl;
    cout << "Pattern: " << pattern << endl;

    int index = fastPatternMatching(text, pattern);
    if (index != -1) {
        cout << "Pattern found at index " << index << endl;
    } else {
        cout << "Pattern not found." << endl;
    }

    return 0;
}

