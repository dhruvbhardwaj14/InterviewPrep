#include "bits/stdc++.h"
using namespace std;
//Problem Statement
/*
Given a string of length N of lowercase alphabet characters. The task is to complete the function countDistinctSubstring(), which returns the count of total number of distinct substrings of this string.
Input:
The first line of input contains an integer T, denoting the number of test cases. Then T test cases follow. Each test case contains a string str.
Output:
For each test case in a new line, output will be an integer denoting count of total number of distinct substrings of this string.
User Task:
Since this is a functional problem you don't have to worry about input, you just have to complete the function countDistinctSubstring().s*/
/*Approach- */
// only for short inputs
struct Node{//flag not needed
    Node* links[26];//assuming only lowercase letters
    bool containsKey(char ch){
        return (links[ch-'a']!=NULL);
    }
    void put(char ch,Node* node){
        links[ch-'a']=node;
    }
    Node* get(char ch){
        return links[ch-'a'];
    }
};
/* Your original code used:
Node* links[26]; // fixed array for each node
This creates 26 pointers for every Trie node, regardless of how many children that node actually has. For large strings (like > 10,000 characters), the number of substrings is O(n²), which leads to millions of nodes — and:
millions of nodes × 26 pointers = hundreds of MBs or even GBs of memory!
Thus, you got Memory Limit Exceeded.
*/
// for longer input sizes

/* When you change to:
unordered_map<char, Node*> links;
you're using a sparse representation:
Only allocate memory when needed.
Most nodes have only a few children — usually just 1 or 2.
So, instead of always reserving space for 26 pointers, it stores only what is used.
Example:
Say your string is "abcabcabc".
A node for 'a' might only need 1 child (for 'b').
In the array approach: memory used = 26 pointers.
In the unordered_map approach: memory used = only 1 entry!
This leads to drastically lower memory usage, especially in long but low-branching strings.
*/
struct Node {
    std::unordered_map<char, Node*> links;
    bool containsKey(char ch){
        return links.find(ch) != links.end();
    }
    void put(char ch, Node* node){
        links[ch] = node;
    }
    Node* get(char ch){
        return links[ch];
    }
};
int countDistinctSubstring(string s) {
    int cnt=0;
    Node* root=new Node();
    for (int i = 0; i < s.size(); i++)
    {
        Node* node=root;
        for (int j = i; j < s.size(); j++)
        {
            if(!node->containsKey(s[j])){
                node->put(s[j],new Node());
                cnt++;
            }
            node=node->get(s[j]);
        }
    }
    return cnt+1;//+1 is for empty string one   
}
int main(){
  
    return 0;
}