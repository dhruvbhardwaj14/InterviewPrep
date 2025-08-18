#include "bits/stdc++.h"
using namespace std;
//Problem Statement
/*
Given a BST and a number X, find Ceil of X.
Note: Ceil(X) is a number that is either equal to X or is immediately greater than X.

If Ceil could not be found, return -1.*/
/*Approach- 
The ceil in a BST means:
If root->data == input → return root->data
If root->data < input → must be in right subtree
If root->data > input → could be in left subtree, but root is still a possible ceil if left has nothing better
*/
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};
int findCeil(Node* root, int input) {
    if(!root) return -1;
    if(root->data==input) return root->data;
    if(root->data<input) return findCeil(root->right,input);
    // root->data > input
    int leftCeil = findCeil(root->left, input);
    return (leftCeil >= input && leftCeil != -1) ? leftCeil : root->data;
}
int main(){
  
    return 0;
}