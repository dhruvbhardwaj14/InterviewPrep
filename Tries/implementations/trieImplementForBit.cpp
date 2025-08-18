#include "bits/stdc++.h"
using namespace std;
//Problem Statement
/*Implement trie for storing bits*/
/*Approach- store each number from LSB to MSB in trie from Top to bottom
*/
struct Node{
    Node* links[2];//either 0 or 1 is stored at each place of bit for 32 times(int)
    bool containsKey(int bit){
        return (links[bit]!=NULL);
    }
    Node* get(int bit){
        return links[bit];
    }
    void put(int bit,Node* node){
        links[bit]=node;
    }
};
class Trie{
    private:
    Node* root;
    Trie(){
        root=new Node();
    }
    public:
    void insert(int num){
        Node* node=root;
        for (int i = 31; i>=0; i--)
        {
            //ith bit set or not 
            int bit=(num>>i)&&1;
            if(!node->containsKey(bit)){
                node->put(bit,new Node());
            }
            node=node->get(bit);
        }
    }
};
int main(){
  
    return 0;
}