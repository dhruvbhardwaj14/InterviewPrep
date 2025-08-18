#include "bits/stdc++.h"
using namespace std;
//Problem Statement
/*
Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.
According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”
*/
/*Approach- 
Traverse tree node by node from root into left and right subtree
for every node if it is leaf! return nullptr
return p->value or q->value as soon as u get that value in the recursion
if for any node either of left subtree or right subtree it returns something other than nullptr then we say it has atleast one of p and q 
but if for any node it's left and right subtree return the p->value and q->value then it means that is lca

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
        if(root==p || root==q) return root;
        TreeNode* left=lowestCommonAncestor(root->left,p,q);
        TreeNode* right=lowestCommonAncestor(root->right,p,q);
       if (left && right) return root; // p and q found in different subtrees
       return left ? left : right;     // either one side has both or is null
}
int main(){
  
    return 0;
}