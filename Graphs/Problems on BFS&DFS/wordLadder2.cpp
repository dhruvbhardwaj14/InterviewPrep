#include "bits/stdc++.h"
using namespace std;
//Problem Statement
/*
A transformation sequence from word beginWord to word endWord using a dictionary wordList is a sequence of words beginWord -> s1 -> s2 -> ... -> sk such that:

Every adjacent pair of words differs by a single letter.
Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to be in wordList.
sk == endWord
Given two words, beginWord and endWord, and a dictionary wordList, return all the shortest transformation sequences from beginWord to endWord, or an empty list if no such sequence exists. Each sequence should be returned as a list of the words [beginWord, s1, s2, ..., sk].

*/
/*Approach- 
Initialize Data Structures:
1.Convert wordList into an unordered_set for O(1) look-up time.
2.Create a queue q to store paths and initialize it with the beginWord.
3.Use usedOnLevel to track words visited at each level and prevent revisiting them.
4.Initialize a vector ans to store all the valid sequences that lead from beginWord to endWord.
5.Start BFS with level set to 0.

BFS Traversal:
1.For each level, check if the current word's transformation is at a new level by comparing vec.size() with level.
2.If at a new level, clear the usedOnLevel and update level.
3.For each word in the queue, if it equals endWord, store the sequence (since it’s a valid transformation path).
4.For every word, generate all possible transformations by replacing each character with a-z and check if the transformed word exists in the set. If it exists:
-Add the transformed word to the current path.
-Push the path to the queue for further processing.
-Mark the word as visited on the current level by adding it to usedOnLevel.

Termination:
BFS terminates when all paths are explored, and we return all the valid transformation sequences stored in ans.
*/
vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
    unordered_set<string> s(wordList.begin(),wordList.end());
    queue<vector<string>> q;
    q.push({beginWord});
    vector<string> usedOnLevel;
    usedOnLevel.push_back(beginWord);
    int level=0;
    vector<vector<string>> ans;
    while(!q.empty()){
        vector<string> vec=q.front();
        q.pop();
        //erase all words that has been used in previous level to transform
        if(vec.size()>level){
            level++;
            for(auto it:usedOnLevel){
                s.erase(it);
            }
            usedOnLevel.clear();
        }
        string word=vec.back();
        //store the answer
        if(word==endWord){
            //the first sequence where we reached end
            if(ans.size()==0){
                ans.push_back(vec);
            }
            else if(ans[0].size()==vec.size()){
                ans.push_back(vec);
            }
        }
        for(int i=0;i<word.length();i++){
            char org=word[i];
            for(char ch='a';ch<='z';ch++){
                word[i]=ch;
                if(s.count(word)>0){
                    vec.push_back(word);
                    q.push(vec);
                    //mark as visited the word on the level
                    usedOnLevel.push_back(word);
                    vec.pop_back();
                }
            }
            word[i]=org;
        }
    }
    return ans;
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

    vector<vector<string>> result = findLadders(beginWord,endWord,wordList);
    for (auto i : result)
    {
        for(auto j: i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}