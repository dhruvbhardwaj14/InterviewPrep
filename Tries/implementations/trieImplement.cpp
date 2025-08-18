#include "bits/stdc++.h"
using namespace std;
//Problem Statement
/**/
/*Approach- */
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
            // move to reference trie
            node=node->get(word[i]);
        }
        node->setEnd();
    }

    // search if word exists in the trie
    // O(len)
    bool search(string word){
        Node* node=root;
        for (int i = 0; i < word.length(); i++)
        {
            if(!node->containsKey(word[i])){
                return false;
            }
            node=node->get(word[i]);
        }
        return node->isEnd();
        
    }
    // check if a word starts with a prefix
    // O(len)
    bool startsWith(string prefix){
        Node* node=root;
        for (int i = 0; i < prefix.length(); i++)
        {
            if(!node->containsKey(prefix[i])){
                return false;
            }
            node=node->get(prefix[i]);
        }
        return true;
        
    }
};
int main(){
  
    return 0;
}