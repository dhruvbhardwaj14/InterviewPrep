#include "bits/stdc++.h"
using namespace std;
//Problem Statement
/*Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.
k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.
You may not alter the values in the list's nodes, only nodes themselves may be changed.*/
/*Approach- 
Step 1: Initialize pointers:
temp to iterate through the list.
prevLast to track the last node of the previous reversed group.

Step 2: For each group:
Use getKthNode(temp, k) to check if at least k nodes exist.
If not, connect the remaining part as-is and break.
Store nextNode = kthNode->next to reconnect later.
Disconnect the group: kthNode->next = nullptr.

Step 3: Reverse the group using reverseList(passHead).

Step 4: Reconnect:
If it's the first group, update head to new head of reversed group.
Else, connect prevLast->next to new head.
Update prevLast = passHead (which is now the tail of reversed group).

Step 5: Move temp = nextNode and repeat.
Return: The updated head of the modified list.
*/
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};
ListNode* reverseList(ListNode* head){
        if(!head || !head->next) return head;
        ListNode* newHead=reverseList(head->next);
        head->next->next=head;
        head->next=nullptr;
        return newHead;
}
ListNode* getKthNode(ListNode* head, int k) {
    k-=1;
    while (head && k>0)
    {
        head=head->next;
        k--;
    }
    return head;
    
}
ListNode* reverseKGroup(ListNode* head, int k) {
    ListNode* temp=head;
    ListNode* prevLast=nullptr;
    while (temp)
    {
        ListNode* passHead=temp;
        ListNode* kthNode=getKthNode(temp,k);
        if(!kthNode){
            if(prevLast) prevLast->next=temp;
            break;
        }
        ListNode* nextNode=kthNode->next;
        kthNode->next=nullptr;
        ListNode* newHead=reverseList(passHead);
        if(passHead==head){
            head=kthNode;
        }
        else{
            prevLast->next=kthNode;
        }
        prevLast=temp;
        temp=nextNode;

    }
    return head;
    
}
int main(){
  
    return 0;
}