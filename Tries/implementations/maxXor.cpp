#include "bits/stdc++.h"
using namespace std;
//Problem Statement
/*Given an integer array nums, return the maximum result of nums[i] XOR nums[j], where 0 <= i <= j < n.*/
/*Approach- 
arr1->insert into trie
check for each element of arr[2] and find what max xor u can get from the trie;
*/
struct Node{
    Node* links[2]={NULL,NULL};//either 0 or 1 is stored at each place of bit for 32 times(int)
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
    public:
    Trie(){
        root=new Node();
    }
    void insert(int num){
        Node* node=root;
        for (int i = 31; i>=0; i--)
        {
            //ith bit set or not 
            int bit=(num>>i)&1;
            if(!node->containsKey(bit)){
                node->put(bit,new Node());
            }
            node=node->get(bit);
        }
    }
    int getMax(int num){//from the trie tells which is the maximum number we can get
        Node* node=root;
        int maxNum=0;
        for (int i = 31; i >=0; i--)
        {
            int bit=(num>>i)&1;//get ith bit of num
            //check if it's opposite is contained
            if(node->containsKey(1-bit)){
                maxNum=maxNum | 1<<i;//add that bit to maxNum
                node=node->get(1-bit);
            }
            else{
                node=node->get(bit);
            }
        }
        return maxNum;
    }
};
int findMaximumXOR(vector<int>& nums) {
    Trie trie;
    for (auto it : nums)
    {
        trie.insert(it);
    }
    int ans=0;
    for (auto it : nums)
    {
        ans=max(ans,trie.getMax(it));
    }
    return ans;  
}
int main(){
  
    return 0;
}