#include "bits/stdc++.h"
using namespace std;
//Problem Statement
/*
Given the head of a singly linked list, reverse the list, and return the reversed list.
*/
/*Approach-
1. take 3 pointers prev,temp,forward
2. make temp as head and move until temp is nullptr and keep swapping next of temp to prev, but before that store actual next node in forward , now move temp to forward  in the end prev will be at last node (new head) return it


Each head->next->next = head; flips one link backwards.
Each head->next = nullptr; breaks the original forward link.
The recursion works from end to start, building the reversed list as it unwinds.
*/
// Iterative
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};
// Iterative
ListNode* reverseList(ListNode* head) {
    if(head==nullptr || head->next==nullptr) return head;
    ListNode* temp=head;
    ListNode* prev=NULL;
    ListNode* forward=NULL;
    while (temp!=nullptr)
    {
        forward=temp->next;
        temp->next=prev;
        prev=temp;
        temp=forward;
    }
    head=prev;
    return head;
    
}
//Recursive
ListNode* reverseList(ListNode* head) {
    if(head==nullptr || head->next==nullptr) return head;
    ListNode* newHead = reverseList(head->next); // reverse the rest

    head->next->next = head; // make the next node point back to current
    head->next = nullptr;    // break the original link

    return newHead; // return new head from recursion
}
int main(){
  
    return 0;
}