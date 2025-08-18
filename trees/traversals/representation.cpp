#include "bits/stdc++.h"
using namespace std;
//Problem Statement
/*Representation of Binary Tree*/
/*Approach- */
struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int num){
        data=num;
        left=right=NULL;

    }
};
int main(){
    Node* root=new Node(1);
    root->right=new Node(2);
    root->left=new Node(3);
    root->left->right=new Node(4);
    return 0;
}