#include "bits/stdc++.h"
using namespace std;
//Problem Statement
/*
Given the root of a binary search tree and an integer k, return true if there exist two elements in the BST such that their sum is equal to k, or false otherwise.
*/
/*Approach- 
Use next(reverse=false) and before(reverse=true) from BSTITERATOR
which will run for the root and find it's next and before and keep checking if their sum is equal to k or not
*/
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class BSTIterator {
    private: 
    stack<TreeNode*> st;
    bool reverse=true;
    void pushAll(TreeNode* root){
        while(root){
            st.push(root);
            if(reverse==true){
                root=root->right;
            }
            else
            root=root->left;
        }
    }
    public:
        BSTIterator(TreeNode* root,bool isReverse) {
            reverse=isReverse;
            pushAll(root);
        }
        
        int next() {
            TreeNode* tmpNode=st.top();//next guy
            st.pop();
            if(!reverse)pushAll(tmpNode->right);
            else pushAll(tmpNode->left);
            return tmpNode->val;
        }
        
        bool hasNext() {
            return !st.empty();
        }
    };
bool findTarget(TreeNode* root, int k) {
    if(!root) return false;
    BSTIterator l(root,false);//next
    BSTIterator r(root,true);//before

    int i=l.next();
    int j=r.next();//r.before
    while (i<j)
    {
        if(i+j==k) return true;
        else if(i+j<k) i=l.next();
        else j=r.next();
    } 
    return false;
}
int main(){
  
    return 0;
}