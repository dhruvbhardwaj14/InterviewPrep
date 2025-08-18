#include "bits/stdc++.h"
using namespace std;
//Problem Statement
/*Given a node of a binary tree get the complete path of that node from root */
/*Approach- 
1. Go to left subtree and add all the nodes in path of subtree 
-> if u found node return ans from there only
-> if u do not found node go back to parent while removing that node from ans arrays
*/
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
bool findPath(TreeNode* root,vector<int>& arr,int x){
    if(!root) return false;
    arr.push_back(root->val);
    if(root->val==x) return true;
    if(findPath(root->left,arr,x)||findPath(root->right,arr,x)) return true;
    arr.pop_back();
    return false;
}
vector<int> getPath(TreeNode* root,int x){
    vector<int> ans;
    if(!root) return ans; 
    findPath(root,ans,x);
    return ans;
}
int main(){
  
    return 0;
}