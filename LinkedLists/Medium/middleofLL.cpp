#include "bits/stdc++.h"
using namespace std;
//Problem Statement
/*Given the head of a singly linked list, return the middle node of the linked list.
If there are two middle nodes, return the second middle node.
*/
/*Approach-
use a slow and fast pointer and fast pointer moves 2 steps and slow moves 1 step only. 
1. if list is even length 2,4,6,8,..... -> then fast will reach null ptr as soon as slow is at middle
2. if list is odd length 3,5,7,9......-> then fast will reach last node as soon as slow is at middle
*/
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* middleNode(ListNode* head) {
    if(head==nullptr || head->next==nullptr) return head;
    ListNode* slow=head;
    ListNode* fast=head;
    while(fast!=nullptr){
        if(fast->next==nullptr){
            return slow;
        }
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}
int main(){
  
    return 0;
}