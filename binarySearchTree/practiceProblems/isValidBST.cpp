#include "bits/stdc++.h"
using namespace std;
//Problem Statement
/*
Given the root of a binary tree, determine if it is a valid binary search tree (BST).
A valid BST is defined as follows:
The left subtree of a node contains only nodes with keys strictly less than the node's key.
The right subtree of a node contains only nodes with keys strictly greater than the node's key.
Both the left and right subtrees must also be binary search trees.*/
/*Approach- */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
bool validate(TreeNode* root,long lo,long hi){
    if(root->val>lo && root->val<hi){
        bool leftSubTree=(root->left)?validate(root->left,lo,root->val):true;
        bool rightSubTree=(root->right)?validate(root->right,root->val,hi):true;
        return leftSubTree&&rightSubTree;
    }
    return false;
}
bool isValidBST(TreeNode* root) {
    if(!root) return true;
    if(!root->left && !root->right) return true;
    return validate(root,LONG_MIN,LONG_MAX); 
}
int main(){
  
    return 0;
}