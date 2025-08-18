#include "bits/stdc++.h"
using namespace std;
//Problem Statement
/*
Given the roots of two binary trees p and q, write a function to check if they are the same or not.
Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.*/
/*Approach- 
check both values and if they match then go down the tree in both left and right at same time
*/
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
bool isSameTree(TreeNode* p, TreeNode* q) {
    if(!p && q) return false;
    if(p && !q) return false;
    if(!p && !q) return true;
    if(p->val==q->val)  return isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
    else return false;
}
int main(){
  
    return 0;
}