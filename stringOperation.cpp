//Write the functions of all string operation (Length,Substring,Indexing,Concatenation,Insertion,Deleation,Replacement) without using any build in functions.

#include <bits/stdc++.h>
using namespace std;

// Function prototypes
void getSubstring(const char* str, int start, int length);
char getIndexing(const char* str, int index);
void concatenate(char* str1, const char* str2);
void insertSubstring(char* str, const char* sub, int position);
void deleteSubstring(char* str, int start, int length);
void replaceSubstring(char* str, const char* sub, int start, int length);

int main() {
    char str1[100] = "Hello, World!";
    char str2[] = " C++ Programming.";


    cout << "Original String: " << str1 << endl;

    
    int length = 0;
    while (str1[length] != '\0') {
        length++;
    }
    cout << "Length of the string: " << length << endl;


    getSubstring(str1, 7, 5);


    cout << "Character at index 1: " << getIndexing(str1, 1) << endl;


    concatenate(str1, str2);
    cout << "After Concatenation: " << str1 << endl;


    insertSubstring(str1, " Amazing", 7);
    cout << "After Insertion: " << str1 << endl;


    deleteSubstring(str1, 7, 8);
    cout << "After Deletion: " << str1 << endl;


    replaceSubstring(str1, "Wonderful", 7, 5);
    cout << "After Replacement: " << str1 << endl;

    return 0;
}


void getSubstring(const char* str, int start, int length) {
    int strLength = 0;
    while (str[strLength] != '\0') {
        strLength++;
    }
    if (start >= 0 && start + length <= strLength) {
        for (int i = 0; i < length; i++) {
            cout << str[start + i];
        }
        cout << endl;
    } else {
        cout << "Invalid range for substring." << endl;
    }
}


char getIndexing(const char* str, int index) {
    int strLength = 0;
    while (str[strLength] != '\0') {
        strLength++;
    }
    if (index >= 0 && index < strLength) {
        return str[index];
    } else {
        cout << "Invalid index." << endl;
        return '\0';
    }
}


void concatenate(char* str1, const char* str2) {
    int length1 = 0;
    while (str1[length1] != '\0') {
        length1++;
    }
    int length2 = 0;
    while (str2[length2] != '\0') {
        length2++;
    }
    for (int i = 0; i < length2; i++) {
        str1[length1 + i] = str2[i];
    }
    str1[length1 + length2] = '\0';
}


void insertSubstring(char* str, const char* sub, int position) {
    int strLength = 0;
    while (str[strLength] != '\0') {
        strLength++;
    }
    int subLength = 0;
    while (sub[subLength] != '\0') {
        subLength++;
    }

    if (position >= 0 && position <= strLength) {
        for (int i = strLength - 1; i >= position; i--) {
            str[i + subLength] = str[i];
        }
        for (int i = 0; i < subLength; i++) {
            str[position + i] = sub[i];
        }
        str[strLength + subLength] = '\0';
    } else {
        cout << "Invalid position for insertion." << endl;
    }
}


void deleteSubstring(char* str, int start, int length) {
    int strLength = 0;
    while (str[strLength] != '\0') {
        strLength++;
    }
    if (start >= 0 && start + length <= strLength) {
        for (int i = start + length; i <= strLength; i++) {
            str[start + i - length] = str[i];
        }
    } else {
        cout << "Invalid range for deletion." << endl;
    }
}


void replaceSubstring(char* str, const char* sub, int start, int length) {
    int strLength = 0;
    while (str[strLength] != '\0') {
        strLength++;
    }
    int subLength = 0;
    while (sub[subLength] != '\0') {
        subLength++;
    }

    if (start >= 0 && start + length <= strLength) {
        deleteSubstring(str, start, length);
        insertSubstring(str, sub, start);
    } else {
        cout << "Invalid range for replacement." << endl;
    }
}
