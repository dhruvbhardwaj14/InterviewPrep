#include "bits/stdc++.h"
using namespace std;
//Problem Statement
/*
A linked list of length n is given such that each node contains an additional random pointer, which could point to any node in the list, or null.

Construct a deep copy of the list. The deep copy should consist of exactly n brand new nodes, where each new node has its value set to the value of its corresponding original node. Both the next and random pointer of the new nodes should point to new nodes in the copied list such that the pointers in the original list and copied list represent the same list state. None of the pointers in the new list should point to nodes in the original list.

For example, if there are two nodes X and Y in the original list, where X.random --> Y, then for the corresponding two nodes x and y in the copied list, x.random --> y.

Return the head of the copied linked list.

The linked list is represented in the input/output as a list of n nodes. Each node is represented as a pair of [val, random_index] where:

val: an integer representing Node.val
random_index: the index of the node (range from 0 to n-1) that the random pointer points to, or null if it does not point to any node.
Your code will only be given the head of the original linked list.
*/
/*Approach- 
meaning:- Just copy the same linkedlist with same links and randoms

// Brute Force (tc-O(2n) sc-O(n)+O(n)->mandatory space for copy)
1. Store the original and copy as a key value pair of hashmap<node,node> so by this we have created just nodes without links for each original node
2. Move temp back to head of original list and new temp to head of copied list
3. For each of node of copied list take it's next to copy of next of original list temp
4. do same for random
5. list is done


// Optimised-without hashmap
1. Instead adding to the hashMap add the new copy nodes to original linked list by inserting copy node in between original of that node and next of that node
2. TO connect random pointers-> 
    -move temp back to head now
    -place temp->next->random = temp->random->next;
    -move temp to temp->next->next
    -repeat untill list ends
3. Change the next pointers of original list and extract the copied list
*/
class Node {
    public:
        int val;
        Node* next;
        Node* random;
        
        Node(int _val) {
            val = _val;
            next = NULL;
            random = NULL;
        }
};
// Brute force
Node* copyRandomList(Node* head) { 
    Node* temp=head;
    map<Node*,Node*> mp;
    while (temp)
    {
        Node* newNode=new Node(temp->val);
        mp[temp]=newNode;
        temp=temp->next;
    }
    temp=head;
    while (temp)
    {
        Node* copyNode=mp[temp];
        copyNode->next=mp[temp->next];
        copyNode->random=mp[temp->random];
        temp=temp->next;
    }
    return mp[head];
}

// Optimised
Node* copyRandomList(Node* head) { 
    Node* temp=head;
    // creating nodes
    while (temp)
    {
        Node* nextElement=temp->next;
        Node* newNode=new Node(temp->val);
        newNode->next=temp->next;
        temp->next=newNode;
        temp=nextElement;
    }
    // Next iteration- linking random pointers
    temp=head;
    while (temp)
    {
        Node* copyNode=temp->next;
        if(temp->random) copyNode->random=temp->random->next;
        else copyNode->random=NULL;
        temp=temp->next->next;
    }
    // extracting the copied list
    temp=head;
    Node* dummyHead=new Node(-1);
    Node* res=dummyHead;
    while (temp)
    {
        res->next=temp->next;
        res=res->next;
        temp->next=temp->next->next;
        temp=temp->next;
    }
    
    return dummyHead->next;
}

int main(){
  
    return 0;
}