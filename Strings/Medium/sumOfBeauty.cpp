#include "bits/stdc++.h"
using namespace std;
//Problem Statement
/*The beauty of a string is the difference in frequencies between the most frequent and least frequent characters.

For example, the beauty of "abaacc" is 3 - 1 = 2.
Given a string s, return the sum of beauty of all of its substrings.
*/
/*Approach- 
1. Iterate through all substrings of the string.
2. For each substring, maintain a frequency array (freq[26] for lowercase letters).
3.For every new character in the substring:
4. Update frequency.
5.Find max_freq and min_freq (excluding 0s).
6.Add beauty = max_freq - min_freq to the total sum.
*/
int beautySum(string s) {
    int n = s.size();
    int totalBeauty = 0;

    for (int i = 0; i < n; ++i) {
        vector<int> freq(26, 0); // Frequency array for a-z

        for (int j = i; j < n; ++j) {
            freq[s[j] - 'a']++;

            int maxFreq = 0, minFreq = INT_MAX;
            for (int k = 0; k < 26; ++k) {
                if (freq[k] > 0) {
                    maxFreq = max(maxFreq, freq[k]);
                    minFreq = min(minFreq, freq[k]);
                }
            }

            totalBeauty += (maxFreq - minFreq);
        }
    }

    return totalBeauty;
}
int main() {
    string s;
    cin >> s;
    cout << beautySum(s) << endl;
    return 0;
}
