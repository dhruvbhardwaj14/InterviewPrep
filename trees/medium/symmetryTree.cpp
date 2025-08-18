#include "bits/stdc++.h"
using namespace std;
//Problem Statement
/*
Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).*/
/*Approach- 
// Both null → symmetric
// One null, other not → not symmetric
// Values differ → not symmetric
*/
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
bool getSymmetry(TreeNode* root1, TreeNode* root2) {
    if (!root1 && !root2) return true;   
    if (!root1 || !root2) return false;  
    if (root1->val != root2->val) return false; 
    
    return getSymmetry(root1->left, root2->right) &&
           getSymmetry(root1->right, root2->left);
}
bool isSymmetric(TreeNode* root) {
    if(getSymmetry(root,root)) return true;
    return false;
}
int main(){
  
    return 0;
}