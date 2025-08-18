#include "bits/stdc++.h"
using namespace std;
//Problem Statement
/*Given the root of a binary tree, return the preorder traversal of its nodes' values.*/
/*Approach- 
Preorder -> DFS(recursive+iterative)
INorder -> DFS(recursive+iterative)
Postorder -> DFS(recursive+iterative)
Level Order-> BFS
*/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
// Preorder
// recursive
void getPreorder(TreeNode* root,vector<int>& vec){
    if(root==nullptr){
        return;
    }
    vec.push_back(root->val);
    getPreorder(root->left,vec);
    getPreorder(root->right,vec);
}
vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        getPreorder(root,ans);
        return ans;
}
// Iterative-> for all nodes in stack currently first pop the top and push it's value to answer then push right and left for Left on top and right at bottom
vector<int> preorderTraversal(TreeNode* root) {
    if(root==nullptr){
        return {};
    }
    vector<int> ans;
    stack<TreeNode*> st;
    st.push(root);
    while (!st.empty())
    {
        int size=st.size();
        for (int i = 0; i < size; i++)
        {
            TreeNode* curr=st.top();
            st.pop();
            
            // root is added to vector
            ans.push_back(curr->val);

            // move to leftSubtree so Push right value in stack first and then the left value so left is at top 
            if(curr->right!=nullptr)st.push(curr->right);
            // move to rightSubtree
            if(curr->left!=nullptr)st.push(curr->left);

        }
    }
    return ans;
}



// Inorder
// recursive
void getInorder(TreeNode* root,vector<int>& vec){
    if(root==nullptr){
        return;
    }
    getInorder(root->left,vec);
    vec.push_back(root->val);
    getInorder(root->right,vec);
}
vector<int> inorderTraversal(TreeNode* root) {
    vector<int> ans;
    getInorder(root,ans);
    return ans;
}

// iterative-> first push all left nodes and as soon as left nodes are over push the root to ans and move to right nodes
vector<int> inorderTraversal(TreeNode* root) {
    if(root==nullptr) return {};
    vector<int> ans;
    stack<TreeNode*> st;
    TreeNode* curr=root;
    while (true)
    {
        if(curr){
            st.push(curr);
            curr=curr->left;
        }
       else{
        if(st.empty()) break;
            curr=st.top();
            st.pop();
            ans.push_back(curr->val);
            curr=curr->right;
       }
    }
    return ans;
}
// postorder
// recursive
void getPostorder(TreeNode* root,vector<int>& vec){
    if(root==nullptr){
        return;
    }
    getPostorder(root->left,vec);
    getPostorder(root->right,vec);
    vec.push_back(root->val);
}
vector<int> postorderTraversal(TreeNode* root) {
    vector<int> ans;
    getPostorder(root,ans);
    return ans;
}
// iterative-> using 2 stack= push current into stack2 and then push first left and then right to stack1
vector<int> postorderTraversal(TreeNode* root) {
    if(root==nullptr) return {};
    vector<int> ans;
    stack<TreeNode*> st1,st2;
    st1.push(root);
    while (!st1.empty())
    {
        root=st1.top();
        st1.pop();
        st2.push(root);
        // first right subtree so push left one
        if(root->left!=nullptr) st1.push(root->left);
        // then left subtree so push right one
        if(root->right!=nullptr) st1.push(root->right);
    }
    while (!st2.empty())
    {

        ans.push_back(st2.top()->val);
        st2.pop(); 
    } 
    return ans;
}
// iterative-> using 1 stack= two variables curr and temp, curr handles all left operations and temp handles all right ones
vector<int> postorderTraversal(TreeNode* root) {
    if(root==nullptr) return {};
    vector<int> ans;
    stack<TreeNode*> st;
    TreeNode* curr=root;
    while (curr!=nullptr || !st.empty())
    {
        if(curr!=nullptr){
            st.push(curr);
            curr=curr->left;
        }
        else{
            TreeNode* temp=st.top()->right;
            if(temp==nullptr){
                temp=st.top();
                st.pop();
                ans.push_back(temp->val);
                while (!st.empty() && temp==st.top()->right)
                {
                    temp=st.top();
                    st.pop();
                    ans.push_back(temp->val);
                } 
            }
            else{
                curr=temp;
            }
        }
    }
    
    return ans;
}
// Level Order-> We need Queue Data structure for BFS
vector<vector<int>> levelOrder(TreeNode* root) {
    if (root == nullptr) return {};
    queue<TreeNode*> q;
    vector<vector<int>> ans;
    q.push(root);
    while (!q.empty())
    {
        vector<int> level;
        int size=q.size();
        for (int i = 0; i < size; i++)
        {
            TreeNode* curr=q.front();
            q.pop();
            if(curr->left!=nullptr){
                q.push(curr->left);
            }
            if(curr->right!=nullptr){
                q.push(curr->right);
            }
            level.push_back(curr->val);
        }
        ans.push_back(level);
    }
    return ans;    
}




int main(){
  
    return 0;
}