#include "bits/stdc++.h"
using namespace std;
//Problem Statement
/*
Given the root of a binary tree, return the length of the diameter of the tree.
The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.
The length of a path between two nodes is represented by the number of edges between them.*/
/*Approach- 
Consider each node as a curve point of the paths
The longest path from a node is :-
max height of left subtree + max height of right subtree
we compute this thing while traversing the tree in O(N) while computing height of tree for each node
*/
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
int getHeight(TreeNode* root,int& diameter){
    if(!root) return 0;
    int lh=getHeight(root->left,diameter);
    int rh=getHeight(root->right,diameter);
    diameter=max(diameter,lh+rh);
    return 1+max(lh,rh);
}
int diameterOfBinaryTree(TreeNode* root) {
    int diameter=INT_MIN;
    getHeight(root,diameter);
    return diameter;
}
int main(){
  
    return 0;
}