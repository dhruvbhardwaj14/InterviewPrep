#include "bits/stdc++.h"
using namespace std;
//Problem Statement
/*
Given the head of a singly linked list, group all the nodes with odd indices together followed by the nodes with even indices, and return the reordered list.
The first node is considered odd, and the second node is even, and so on.
Note that the relative order inside both the even and odd groups should remain as it was in the input.
You must solve the problem in O(1) extra space complexity and O(n) time complexity.*/

/*Approach- 
Initialize odd and even pointers to the first and second nodes respectively.
Save the head of the even list in evenHead.
Traverse the list:
-Link current odd node's next to even.next.
-Move odd forward.
-Link current even node's next to odd.next.
-Move even forward.
Once done, attach evenHead to the end of the odd list.
*/
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};
ListNode* oddEvenList(ListNode* head) {
    if(head==nullptr || head->next==nullptr) return head;
    ListNode* eve=head->next;
    ListNode* odd=head;
    ListNode* evenHead = eve;
    while(eve && eve->next){
        odd->next=eve->next;
        odd=odd->next;
        
        eve->next=odd->next;
        eve=eve->next;
    }
    odd->next=evenHead;
    return head;
}
int main(){
  
    return 0;
}