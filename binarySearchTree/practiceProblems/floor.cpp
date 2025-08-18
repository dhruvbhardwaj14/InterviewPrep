#include "bits/stdc++.h"
using namespace std;
//Problem Statement
/*
You are given a BST(Binary Search Tree) with n number of nodes and value x. your task is to find the greatest value node of the BST which is smaller than or equal to x.
Note: when x is smaller than the smallest node of BST then returns -1.
*/
/*Approach- 
The floor in a BST means:
If root->data == input → return root->data
If root->data > input → must be in left subtree
If root->data < input → could be in right subtree, but root is still a possible ceil if right has nothing better
*/
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};
int floor(Node* root, int x) {
    if(!root) return -1;
    if(root->data==x) return root->data;
    if(root->data>x) return floor(root->left,x);
    int rightFloor=floor(root->right,x);
    return (rightFloor<=x && rightFloor!=-1)?rightFloor:root->data;
}
int main(){
  
    return 0;
}