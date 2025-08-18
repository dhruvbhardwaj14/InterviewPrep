#include "bits/stdc++.h"
using namespace std;
//Problem Statement
/*A path in a binary tree is a sequence of nodes where each pair of adjacent nodes in the sequence has an edge connecting them. A node can only appear in the sequence at most once. Note that the path does not need to pass through the root.
The path sum of a path is the sum of the node's values in the path.
Given the root of a binary tree, return the maximum path sum of any non-empty path.
*/
/*Approach- 
go traverse like u finding height of tree in a way that 
1. take max value of lhs only if it is greater than 0
2. take max value of rhs only if it is greater than 0
3. maxi variable is max of maxi + node->val+lhs+rhs
4. the function must return always the max(rhs+lhs)+node-> val to the upper function
*/
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
int getMaxPath(TreeNode* root,int& maxPath){
    if(!root) return 0;
    int lhs=max(0,getMaxPath(root->left,maxPath));
    int rhs=max(0,getMaxPath(root->right,maxPath));
    maxPath=max(maxPath,lhs+rhs+root->val);
    return root->val+max(lhs,rhs);
}
int maxPathSum(TreeNode* root) {
    int maxPath=INT_MIN;
    getMaxPath(root,maxPath);
    return maxPath;
}
int main(){
  
    return 0;
}