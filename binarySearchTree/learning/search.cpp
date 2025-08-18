#include "bits/stdc++.h"
using namespace std;
//Problem Statement
/*
You are given the root of a binary search tree (BST) and an integer val.

Find the node in the BST that the node's value equals val and return the subtree rooted with that node. If such a node does not exist, return null.*/
/*Approach- simple searching logic*/
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
 TreeNode* searchBST(TreeNode* root, int val) {
    if(!root ||  root->val==val )  return root;
    TreeNode* ans=new TreeNode();
    if(root->val<val) ans= searchBST(root->right,val);
    if(root->val>val) ans= searchBST(root->left,val);
    return ans;
}
int main(){
  
    return 0;
}