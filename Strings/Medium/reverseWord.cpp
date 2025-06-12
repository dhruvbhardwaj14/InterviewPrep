#include "bits/stdc++.h"
using namespace std;
//Problem Statement
/*Given an input string s, reverse the order of the words.

A word is defined as a sequence of non-space characters. The words in s will be separated by at least one space.

Return a string of the words in reverse order concatenated by a single space.

Note that s may contain leading or trailing spaces or multiple spaces between two words. The returned string should only have a single space separating the words. Do not include any extra spaces.*/
/*Approach- 
stringstream reads words one by one (skipping extra spaces).
We collect all valid words in a vector.
Reverse the vector.
Concatenate with a single space between words.
*/
string reverseWords(string s) {
    stringstream ss(s);
    string word;
    vector<string> words;

    // Extract words (ignores multiple spaces automatically)
    while (ss >> word) {
        words.push_back(word);
    }

    // Reverse the word vector
    reverse(words.begin(), words.end());

    // Join with single space
    string result;
    for (int i = 0; i < words.size(); ++i) {
        if (i > 0) result += " ";
        result += words[i];
    }

    return result;
}

int main() {
    string input;
    getline(cin, input);
    cout << '"' << reverseWords(input) << '"' << endl;
    return 0;
}
