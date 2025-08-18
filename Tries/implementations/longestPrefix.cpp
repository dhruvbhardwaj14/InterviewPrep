#include "bits/stdc++.h"
using namespace std;
//Problem Statement
/*
Given an array of strings words[], find the longest string such that every prefix of it is also present in words[]. If multiple strings have the same maximum length, return the lexicographically smallest one.
If no such string is found, return an empty string.*/
/*Approach- 
if in the trie for a particular string all it's prefixes has flag set as true that means all it prefixes exist in the vector of string hence it is the longest string
*/
struct Node{
    Node* links[26];//assuming only lowercase letters
    bool flag=false;
    bool containsKey(char ch){
        return (links[ch-'a']!=NULL);
    }
    void put(char ch,Node* node){
        links[ch-'a']=node;
    }
    Node* get(char ch){
        return links[ch-'a'];
    }
    void setEnd(){
        flag=true;
    }
    bool isEnd(){
        return flag;
    }
};
class Trie{
    private:
    Node* root;
    public:
    Trie(){
        root=new Node();
    }
    // inserts the word in the trie
    // O(len)
    void insert(string word){
        Node* node=root;
        for (int i = 0; i < word.length(); i++)
        {
            if(!node->containsKey(word[i])){
                node->put(word[i],new Node());
            }
            node=node->get(word[i]);
        }
        node->setEnd();
    }
    bool checkIfPrefixExists(string word){
        Node* node=root;
        for (int i = 0; i < word.size(); i++)
        {
            if(node->containsKey(word[i])){
                node=node->get(word[i]);
                if(!node->isEnd()){
                    return false;
                }
            }
            else{
                return false;
            }

        }
        return true;
    }
};
string longestValidWord(vector<string>& words) {
    Trie trie;
    for (auto it : words)
    {
        trie.insert(it);
    }
    string longestString="";
    for (auto it : words)
    {
        if(trie.checkIfPrefixExists(it)){
            if(longestString.length()<it.length()){
                longestString=it;
            }
            else if(longestString.length()==it.length() && it<longestString){
                longestString=it;
            }
        }
    }
    return longestString;
}
int main(){
  
    return 0;
}