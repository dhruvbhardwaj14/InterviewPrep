#include "bits/stdc++.h"
using namespace std;
//Problem Statement
/*
Given a linked list containing n head nodes where every node in the linked list contains two pointers:
(i) next points to the next node in the list.
(ii) bottom pointer to a sub-linked list where the current node is the head.
Each of the sub-linked lists nodes and the head nodes are sorted in ascending order based on their data.
Your task is to flatten the linked list such that all the nodes appear in a single level while maintaining the sorted order.

Note:
1. ↓ represents the bottom pointer and -> represents the next pointer.
2. The flattened list will be printed using the bottom pointer instead of the next pointer.
*/
/*Approach- 
// Brute Force
1. Add all elements to a array
2. sort using mergesort
3. create a new list jusing ConverToLL function having next as null and adding to bottom of each node the next node
4. return this new list head

// Optimised
1. Take two linked lists at a time and move in their bottom and create a one flattened link list out of two
    -Create a dummynode and add the smallest of two lists to the dummy node 
    -and keep adding to the bottom
2. Repeat
*/

struct Node{
    int data;
    struct Node * next;
    struct Node * bottom;

    Node(int x){
        data = x;
        next = NULL;
        bottom = NULL;
    }
};
// Brute Force 
// T.C-> O(n*mx2 + n*mxlog(n*m))
// S.C-> O(n*mx2)

void merge(vector<int>& arr1,vector<int>& arr2,vector<int>& arr){
    arr.clear();
    int l1=0,l2=0;
    while (l1<arr1.size() && l2<arr2.size())
    {
        if(arr1[l1]<arr2[l2]){
            arr.push_back(arr1[l1]);
            l1++;
        }
        else{
            arr.push_back(arr2[l2]);
            l2++;
        }
    }
    while (l1<arr1.size())
    {
        arr.push_back(arr1[l1]);
        l1++;
    }
    while (l2<arr2.size())
    {
        arr.push_back(arr2[l2]);
        l2++;
    }
}
vector<int> mergeSort(vector<int>& arr,int lo, int hi){
    if (hi - lo <= 1) {
        return vector<int>(arr.begin() + lo, arr.begin() + hi);
    }
    int mid=lo+((hi-lo)/2);
    vector<int> arr1=mergeSort(arr,lo,mid);
    vector<int> arr2=mergeSort(arr,mid,hi);
    vector<int> result;
    merge(arr1,arr2,result);
    return result;
}
Node *convertToLL(vector<int> arr) {
    if(arr.size()==0) return NULL;
    Node* head= new Node(arr[0]);
    Node* temp=head;
    for(int i=1;i<arr.size();i++){
        Node* newNode=new Node(arr[i]);
        temp->bottom=newNode;
        temp=newNode;
    }
    temp->bottom=NULL;
    return head;
}
Node *flatten(Node *root) {
    vector<int> arr;
    Node* temp=root;
    while (temp)
    {
        Node* temp1=temp;
        while(temp1){
            arr.push_back(temp1->data);
            temp1=temp1->bottom;
        }
        temp=temp->next;
    }
    arr=mergeSort(arr,0,arr.size());
    root=convertToLL(arr);
    return root;
    
}

// Optimised 
Node* MergeTwoLists(Node* list1,Node* list2){
    Node* dummyHead=new Node(-1);
    Node* ansHead=dummyHead;
    while(list1 && list2){
        if(list1->data<list2->data){
            dummyHead->bottom=list1;
            dummyHead=list1;
            list1=list1->bottom;
        }
        else{
            dummyHead->bottom=list2;
            dummyHead=list2;
            list2=list2->bottom;
        }
        dummyHead->next=NULL;
    }
    if(list1) dummyHead->bottom=list1;
    else dummyHead->bottom=list2;
    if(ansHead->bottom) ansHead->bottom->next=NULL;
    return ansHead->bottom;
}
Node *flatten(Node *root) {
    if(!root || !root->next) return root;
    Node* mergedHead=flatten(root->next);
    root=MergeTwoLists(root,mergedHead);
    return root;
}
int main(){
  
    return 0;
}