#include "bits/stdc++.h"
using namespace std;
//Problem Statement
/*
Ninja has to implement a data structure ”TRIE” from scratch. Ninja has to complete some functions.

1) Trie(): Ninja has to initialize the object of this “TRIE” data structure.

2) insert(“WORD”): Ninja has to insert the string “WORD”  into this “TRIE” data structure.

3) countWordsEqualTo(“WORD”): Ninja has to return how many times this “WORD” is present in this “TRIE”.

4) countWordsStartingWith(“PREFIX”): Ninjas have to return how many words are there in this “TRIE” that have the string “PREFIX” as a prefix.

5) erase(“WORD”): Ninja has to delete one occurrence of the string “WORD” from the “TRIE”.
Note:

1. If erase(“WORD”) function is called then it is guaranteed that the “WORD” is present in the “TRIE”.
2. If you are going to use variables with dynamic memory allocation then you need to release the memory associated with them at the end of your solution.
Can you help Ninja implement the "TRIE" data structure?
*/
/*Approach- */
// node structure is different since we have to count how many times a word comes
struct Node{
    Node* links[26];
    int countEndWith=0;// checks how many words ends with exact same word 
    int countPrefix=0;// check how many words has letters of current word as prefixes
    bool containsKey(char ch){
        return links[ch-'a'];
    }
    void put(char ch,Node* node){
        links[ch-'a']=node;
    }
    Node* get(char ch){
        return links[ch-'a'];
    }
    void increaseEnd(){
        countEndWith++;
    }
    void increasePrefix(){
        countPrefix++;
    }
    void deleteEnd(){
        countEndWith--;
    }
    void reducePrefix(){
        countPrefix--;
    }
    int getEnd(){
        return countEndWith;
    }
    int getPrefix(){
        return countPrefix;
    }
};
class Trie{
    private:
    Node* root;
    public:

    Trie(){
        root=new Node();
    }

    void insert(string &word){
        Node* node=root;
        for (int i = 0; i < word.length(); i++)
        {
            if(!node->containsKey(word[i])){
                node->put(word[i],new Node());
            }
            node=node->get(word[i]);
            node->increasePrefix();
        }
        node->increaseEnd();
    }

    int countWordsEqualTo(string &word){
        Node* node=root;
        for (int i = 0; i < word.size(); i++)
        {
            if(node->containsKey(word[i])){
                node=node->get(word[i]);
            }
            else{
                return 0;
            }
        }
        return node->getEnd();
    }

    int countWordsStartingWith(string &word){
        Node* node=root;
        for (int i = 0; i < word.size(); i++)
        {
            if(node->containsKey(word[i])){
                node=node->get(word[i]);
            }
            else{
                return 0;
            }
        }
        return node->getPrefix();
        
    }

    void erase(string &word){
        Node* node=root;
        for (int i = 0; i < word.size(); i++)
        {
            if(node->containsKey(word[i])){
                node=node->get(word[i]);
                node->reducePrefix();
            }
            else{
                return;
            }
        }
        node->deleteEnd();
    }
};
int main(){
  
    return 0;
}