#include "bits/stdc++.h"
using namespace std;
//Problem Statement
/*
Given the root of a binary tree, return the maximum width of the given tree.
The maximum width of a tree is the maximum width among all levels.
The width of one level is defined as the length between the end-nodes (the leftmost and rightmost non-null nodes), where the null nodes between the end-nodes that would be present in a complete binary tree extending down to that level are also counted into the length calculation.
It is guaranteed that the answer will in the range of a 32-bit signed integer.
*/
/*Approach-
Index all nodes of tree with the formula that at each level L
the index of the nodes will be 
(0-indexing)"if current node has index i left child has index 2*i+1 and right child has index 2*i+2"
(1-indexing)"if current node has index i left child has index 2*i and right child has index 2*i+1"
and the max width thus becomes at every level (lastindex-firstindex+1)

but the catch is 2*i at each step will overflow it for 10^5 levels
so what we will do is we will subtract minimal from that i and make all child in range 
1 2 3 4......

1. Start by taking a queue<node,index> for level order traversal
*/
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
int widthOfBinaryTree(TreeNode* root) {
    if(!root) return 0;
    int ans=INT_MIN;
    queue<pair<TreeNode*,int>> q;
    q.push({root,0});
    while (!q.empty())
    {
        int size=q.size();
        int minIdx=0;
        int firstIdx = q.front().second; // normalize starting point for this level
        int maxIdx=0;
        for (int i = 0; i < size; i++)
        {
            TreeNode* currNode=q.front().first;
            int idx=q.front().second-firstIdx;
            q.pop();
            if (i == 0) minIdx = idx;
            if (i == size - 1) maxIdx = idx;
          if(currNode->left)  q.push({currNode->left,(2*(idx)+1)});
          if(currNode->right)q.push({currNode->right,(2*(idx)+2)});
        }
        ans=max(ans,maxIdx-minIdx+1);
    }
    return ans;
}
int main(){
  
    return 0;
}