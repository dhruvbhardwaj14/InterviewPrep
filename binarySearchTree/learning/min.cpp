#include "bits/stdc++.h"
using namespace std;
//Problem Statement
/*
You are given a Binary Search Tree.
Find the minimum value in it.
*/
/*Approach- min is the leftmost child of root*/
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node() : data(0), left(nullptr), right(nullptr){};
    Node(int x) : data(x), left(nullptr), right(nullptr) {}
    Node(int x, Node *left, Node *right) : data(x), left(left), right(right) {}
};
int minVal(Node* root){
    if(!root) return -1;
	if(!root->left) return root->data;
    return minVal(root->left);
}
int main(){

    return 0;
}