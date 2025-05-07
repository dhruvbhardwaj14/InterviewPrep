#include "bits/stdc++.h"
using namespace std;
//Problem Statement
/*
A transformation sequence from word beginWord to word endWord using a dictionary wordList is a sequence of words beginWord -> s1 -> s2 -> ... -> sk such that:

Every adjacent pair of words differs by a single letter.
Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to be in wordList.
sk == endWord
Given two words, beginWord and endWord, and a dictionary wordList, return the number of words in the shortest transformation sequence from beginWord to endWord, or 0 if no such sequence exists.

*/
/*Approach- 
1. first we send all wordList to unordered_set so that we can search for each word if it exists or not in amortised time complexity of O(n)
2. Remove beginWord from the set if it exists somehow in wordList
3. we use bfs modified approach where we are creating levels by 
-take each letter of given word and replace it by a-z all and check if formed word exists in set or not?
-if exists then push that word in queue with increased stepsize with current one 
-repeat until the pushed word is equal to endWord
4. Run bfs with beginword and stepsize of 1;
*/
int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    queue<pair<string,int>> q;
    unordered_set<string> s(wordList.begin(),wordList.end());
    s.erase(beginWord);
    q.push({beginWord,1});
    int cnt=1;
    while(!q.empty()){
        string wd=q.front().first;
        int steps=q.front().second;
        q.pop();
        if(wd==endWord) return steps;
        for(int i=0;i<wd.length();i++){
            char org=wd[i];
            for(char ch='a';ch<='z';ch++){
                wd[i]=ch;
                //it exists in the set
                if(s.find(wd)!=s.end()){
                    s.erase(wd);
                    q.push({wd,steps+1});
                }
            }
            wd[i]=org;
        }
    }
    return 0;
}
int main(){
    string beginWord, endWord;
    int n;
    cin >> n;
    cin >> beginWord;
    cin >> endWord;

    vector<string> wordList(n);
    for (int i = 0; i < n; i++) {
        cin >> wordList[i];
    }

    int result = ladderLength(beginWord, endWord, wordList);
    if (result == 0) {
        cout << "No transformation sequence possible." << endl;
    } else {
        cout << "Minimum transformation steps: " << result << endl;
    }
    return 0;
}