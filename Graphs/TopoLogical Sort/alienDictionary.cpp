#include "bits/stdc++.h"
using namespace std;
//Problem Statement
/*A new alien language uses the English alphabet, but the order of letters is unknown. You are given a list of words[] from the alien language’s dictionary, where the words are claimed to be sorted lexicographically according to the language’s rules.

Your task is to determine the correct order of letters in this alien language based on the given words. If the order is valid, return a string containing the unique letters in lexicographically increasing order as per the new language's rules. If there are multiple valid orders, return any one of them.

However, if the given arrangement of words is inconsistent with any possible letter ordering, return an empty string ("").

A string a is lexicographically smaller than a string b if, at the first position where they differ, the character in a appears earlier in the alien language than the corresponding character in b. If all characters in the shorter word match the beginning of the longer word, the shorter word is considered smaller.

Note: Your implementation will be tested using a driver code. It will print true if your returned order correctly follows the alien language’s lexicographic rules; otherwise, it will print false.*/

/*Approach- 
Create the directed graph for letters suggesting that for each letter if an edge is from u to v that means u comes before v in the dictionary of aliens and then run topological sort and get the answer vector.
*/
string findOrder(vector<string> &words) {
    int n=words.size();
    vector<vector<int>> graph(26);  
    vector<int> indeg(26,0);
    // Mark existing characters
    vector<bool> exists(26,false);
    for (const string& word : words) {
        for (char ch : word) {
            exists[ch - 'a'] = true;
        }
    }
    
    // Build the graph from adjacent words
    for (int i = 0; i + 1 < words.size(); ++i) {
        const string& w1 = words[i];
        const string& w2 = words[i + 1];
        int len = min(w1.length(), w2.length());
        int j = 0;

        while (j < len && w1[j] == w2[j]) ++j;

        if (j < len) {
            int u = w1[j] - 'a';
            int v = w2[j] - 'a';
            graph[u].push_back(v);
            indeg[v]++;
        } else if (w1.size() > w2.size()) {
            
            // Invalid input 
            return "";
        }
    }
   //run kahn's algo
    
    queue<int> q;
    string ans="";
    //push all initial 0 indeg nodes to queue
    for (int i = 0; i < 26; i++)
    {
        if(exists[i]&&indeg[i]==0){
            q.push(i);
        }
    }
    while (!q.empty())
    {
        int curr=q.front();
        ans+=(char)(curr+'a');
        q.pop();
        for(auto child:graph[curr]){
            indeg[child]--;
            if(indeg[child]==0){
                q.push(child);
            }
        }
    }
    // Check, there was a cycle or not
    for (int i = 0; i < 26; ++i) {
    if (exists[i] && indeg[i] != 0) {
            return "";
        }
    }

    return ans;
}
int main(){
    int n;
    cin>>n;
    vector<string> words(n);
    for (int i = 0; i < n; i++)
    {
        cin>>words[i];
    }
    cout<<findOrder(words)<<endl;
    return 0;
}