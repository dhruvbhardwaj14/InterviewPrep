#include "bits/stdc++.h"
using namespace std;
//Problem Statement
/*
Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. (i.e., from left to right, then right to left for the next level and alternate between).
*/
/*Approach- Order Level by level but keep a counter when it is 1 move from right then left if it is 0 move from left then right while pushing in to the level array that means push from back in counter=1 and from front in counter =0*/
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>> ans;
    if(!root) return ans;
    queue<TreeNode*> q;
    q.push(root);
    int counter=0;
    while (!q.empty())
    {
        int size=q.size();
        vector<int> level(size);
        for (int i = 0; i < size; i++)
        {
            TreeNode* curr=q.front();
            q.pop();
            int index=(counter)?size-1-i:i;
            level[index]=curr->val;
            if(curr->left) q.push(curr->left);
            if(curr->right) q.push(curr->right);
        }
        ans.push_back(level);
        counter=!counter;
    }
    return ans;
}
int main(){

    return 0;
}
// 3 ->0
// 20 9-->1 start from back
// 14 12 15 7->0 start from front
// 
//      3
//    9 20
// 14 12 15 7
// 1 2 4 5 6 8 10 11