#include "bits/stdc++.h"
using namespace std;
//Problem Statement
/*
Given the root of a binary tree, calculate the vertical order traversal of the binary tree.
For each node at position (row, col), its left and right children will be at positions (row + 1, col - 1) and (row + 1, col + 1) respectively. The root of the tree is at (0, 0).
The vertical order traversal of a binary tree is a list of top-to-bottom orderings for each column index starting from the leftmost column and ending on the rightmost column. There may be multiple nodes in the same row and same column. In such a case, sort these nodes by their values.
Return the vertical order traversal of the binary tree.
s*/
/*Approach- 
main thing is data structures we take!
1. Queue(node,vertical, level)
for every down-> level increase by 1
for every left-> vertical decreases by 1
for every right-> vertical increases by 1
2. map<vertical,map<level,multiset<TreeNode*>>> -> map that has for each vertical it's corresponding level by level mapping of Nodes-> and they can have same values as well so we use multiset
*/
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) return ans;
        queue<pair<TreeNode*,pair<int,int>>> q;
        map<int,map<int,multiset<int>>> mp;
        q.push({root,{0,0}});
        while (!q.empty())
        {
            auto curr=q.front();
            int vertical=curr.second.first;
            int level=curr.second.second;
            q.pop();
            if(curr.first->left) q.push({curr.first->left,{vertical-1,level+1}});
            if(curr.first->right) q.push({curr.first->right,{vertical+1,level+1}});
            mp[vertical][level].insert(curr.first->val);
        
        }
        for (auto p : mp)
        {
            vector<int> level;
            for (auto q : p.second)
            {
                level.insert(level.end(),q.second.begin(),q.second.end());
            }
            ans.push_back(level);
        }
        return ans;
}
int main(){
  
    return 0;
}