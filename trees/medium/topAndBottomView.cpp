#include "bits/stdc++.h"
using namespace std;
//Problem Statement
/*
Top view
You are given a binary tree, and your task is to return its top view. The top view of a binary tree is the set of nodes visible when the tree is viewed from the top.

Note: 

Return the nodes from the leftmost node to the rightmost node.
If two nodes are at the same position (horizontal distance) and are outside the shadow of the tree, consider the leftmost node only. 

Bottom View
Given a binary tree, return an array where elements represent the bottom view of the binary tree from left to right.

Note: If there are multiple bottom-most nodes for a horizontal distance from the root, then the later one in the level order traversal is considered. For example, in the below diagram, 7 and 34 both are the bottommost nodes at a horizontal distance of 0 from the root, here 34 will be considered.
*/
/*Approach-
Top view
Data structures:-
1. Queue(Node,vertical line)
2. Map<vertical line, Node)

add root to Queue and traverse level by level
on each level for each vertical if mp[vertical] not exist that means we have got a new vertical which will be visible from the top view so add it to map
but if it exists that means a node at top already exists so it's not visible in the top view

Bottom View
We keep overWriting so just remove the already exists condition from the map
*/
struct Node
{
    int data;
    Node* left;
    Node* right;
};
vector<int> topView(Node *root) {
    vector<int> ans;
    if(!root) return ans;
    map<int,int> mp;//map is already sorted
    queue<pair<Node*,int>> q;
    
    q.push({root,0});
    while (!q.empty())
    {
        auto curr=q.front();
        q.pop();
        Node* currNode=curr.first;
        int verticalLine=curr.second;
        if(mp.find(verticalLine)==mp.end()){
            mp[verticalLine]=currNode->data;
        }
        if(currNode->left) q.push({currNode->left,verticalLine-1});
        if(currNode->right) q.push({currNode->right,verticalLine+1});
    }
    for (auto it : mp)
    {
        ans.push_back(it.second);
    }
    return ans;
}
vector<int> bottomView(Node *root) {
    vector<int> ans;
    if(!root) return ans;
    map<int,int> mp;//map is already sorted
    queue<pair<Node*,int>> q;
    
    q.push({root,0});
    while (!q.empty())
    {
        auto curr=q.front();
        q.pop();
        Node* currNode=curr.first;
        int verticalLine=curr.second;
        mp[verticalLine]=currNode->data;
        if(currNode->left) q.push({currNode->left,verticalLine-1});
        if(currNode->right) q.push({currNode->right,verticalLine+1});
    }
    for (auto it : mp)
    {
        ans.push_back(it.second);
    }
    return ans;  
}
int main(){
  
    return 0;
}