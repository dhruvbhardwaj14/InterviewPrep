#include "bits/stdc++.h"
using namespace std;
//Problem Statement
/*
Given the head of a linked list, remove the nth node from the end of the list and return its head.
Follow up: Could you do this in one pass?
*/
/*Approach- 

-Using the two-pointer technique (also known as the "fast and slow" pointer approach). The key idea is to maintain a gap of n nodes between the two pointers.
- start both pointers from back of head of linked list from a dummy node
*/
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};
ListNode* removeNthFromEnd(ListNode* head, int n) {
    if(!head) return head;
    if(!head->next && n==1) return nullptr;
    ListNode* dummy=new ListNode(0);
    dummy->next=head;
    ListNode* prev=dummy;
    ListNode* forward=dummy;
    for(int i=0;i<=n;++i)
    {
        forward=forward->next;
    }
    while (forward)
    {
        forward=forward->next;
        prev=prev->next;
    }
    ListNode* temp=prev->next;
    prev->next=prev->next->next;
    delete temp;
    return dummy->next;
}
//  1 2 3 4 5
int main(){
  
    return 0;
}