#include "bits/stdc++.h"
using namespace std;
//Problem Statement
/*
Given head, the head of a linked list, determine if the linked list has a cycle in it.
There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to. Note that pos is not passed as a parameter.
Return true if there is a cycle in the linked list. Otherwise, return false.
*/
/*Approach- 
slow and fast pointer again and if there is a cycle then they will surely eventually meet
*/
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};
bool hasCycle(ListNode *head) {
    if(head==nullptr || head->next==nullptr) return false;
    ListNode* slow=head;
    ListNode* fast=head;
    while (fast!=nullptr)
    {
        if(fast->next==nullptr) return false;
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast) return true;
    }
    return false;

}
int main(){
  
    return 0;
}