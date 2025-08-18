#include "bits/stdc++.h"
using namespace std;
//Problem Statement
/*
Given the root of a complete binary tree, return the number of the nodes in the tree.

According to Wikipedia, every level, except possibly the last, is completely filled in a complete binary tree, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.

Design an algorithm that runs in less than O(n) time complexity.*/
/*Approach- 
1. Understand the problem
   - We are given the root of a complete binary tree.
   - A complete binary tree has:
       * All levels completely filled except possibly the last.
       * The last level’s nodes are filled from left to right.
   - We must count the total number of nodes in LESS than O(n) time.

2. Key insight
   - In a complete binary tree:
       * If the left subtree’s height == right subtree’s height:
           → The left subtree is a perfect binary tree.
           → Node count in a perfect binary tree of height h = (2^h) - 1.
           → So we can skip counting it node-by-node.
       * If heights differ:
           → The right subtree is a perfect binary tree (one level smaller).
   - This lets us avoid traversing the whole tree.

3. Step-by-step logic
   - Compute leftHeight(root) → height by going only left.
   - Compute rightHeight(root) → height by going only right.
   - If both heights are equal:
       → Tree is perfect → return (2^h) - 1.
   - Else:
       → Count nodes recursively for left and right subtrees.

4. Complexity analysis
   - Height computation: O(log n)
   - Recursive calls happen O(log n) times.
   - Total: O(log² n) time.
   - Space: O(log n) recursion stack.

*/
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
int getLeftHeight(TreeNode* node) {
    int height = 0;
    while (node) {
        height++;
        node = node->left;
    }
    return height;
}

int getRightHeight(TreeNode* node) {
    int height = 0;
    while (node) {
        height++;
        node = node->right;
    }
    return height;
}
int countNodes(TreeNode* root) {
    if (!root) return 0;

    int leftH = getLeftHeight(root);
    int rightH = getRightHeight(root);

    if (leftH == rightH) {
        // Tree is perfect binary tree
        return (1 << leftH) - 1;
    } else {
        // Count recursively
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
}
int main(){
  
    return 0;
}