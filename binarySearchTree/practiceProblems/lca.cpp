#include "bits/stdc++.h"
using namespace std;
//Problem Statement
/*
Given a binary search tree (BST), find the lowest common ancestor (LCA) node of two given nodes in the BST.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”*/
/*Approach- 
different then binary tree LCA
start from root and check the value of both nodes p and q with value of root!
and if in any case p->value<root<q->value or vice versa it means it's a split point and it's LCA only
*/
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(!root) return nullptr;
    if(p->val>q->val) return lowestCommonAncestor(root,q,p);
    if(root->val>p->val && root->val<q->val) return root;
    else if(root->val>p->val && root->val>q->val) return lowestCommonAncestor(root->left,p,q);
    return lowestCommonAncestor(root->right,p,q);
}
int main(){
  
    return 0;
}