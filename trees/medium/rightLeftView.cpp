#include "bits/stdc++.h"
using namespace std;
//Problem Statement
/*
Given the root of a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.
*/
/*Approach- 
Traversal Level by Level but not level order-> since it stores every Node 
recrusive approach
right view->move from (root,right,left) rightward direction at first and at each level first node of right side is the right view and it will be equal to current vectors size then only add to vector
left view->move from (root,left,left) leftward direction at first and at each level first node of left side is the left view and it will be equal to current vectors size then only add to vector
*/
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
void getRightView(TreeNode* root,vector<int>& ans,int level){
    if(!root) return;
    if(level==ans.size()) ans.push_back(root->val);
    if(root->right) getRightView(root->right,ans,level+1);
    if(root->left) getRightView(root->left,ans,level+1);
}
void getLeftView(TreeNode* root,vector<int>& ans,int level){
    if(!root) return;
    if(level==ans.size()) ans.push_back(root->val);
    if(root->left) getRightView(root->left,ans,level+1);
    if(root->right) getRightView(root->right,ans,level+1);
}
vector<int> rightSideView(TreeNode* root) {
    vector<int> ans;
    getRightView(root,ans,0);
    return ans;
}
int main(){
  
    return 0;
}