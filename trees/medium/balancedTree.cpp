#include "bits/stdc++.h"
using namespace std;
//Problem Statement
/*Given a binary tree, determine if it is height-balanced.*/
/*Approach- 
At each node:

Ask: "Are my left and right subtrees balanced?"
If not → I’m not balanced either → return -1.
If yes → "What are their heights?"
If their height difference is ≤ 1 → I’m balanced → return 1 + max(leftHeight, rightHeight)
If not → return -1.
This idea of “bubbling up an error (-1) immediately” makes the algorithm efficient.
*/
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
int checkHeight(TreeNode* root) {
    if (!root) return 0;
    int left = checkHeight(root->left);
    if (left == -1) return -1; // not balanced
    int right = checkHeight(root->right);
    if (right == -1) return -1; // not balanced

    if (abs(left - right) > 1) return -1;
    return 1 + max(left, right);
}

bool isBalanced(TreeNode* root) {
    return checkHeight(root) != -1;
}
int main(){
  
    return 0;
}