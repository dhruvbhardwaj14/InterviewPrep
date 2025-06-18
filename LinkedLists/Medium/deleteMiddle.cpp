#include "bits/stdc++.h"
using namespace std;
//Problem Statement
/*You are given the head of a linked list. Delete the middle node, and return the head of the modified linked list.
The middle node of a linked list of size n is the ⌊n / 2⌋th node from the start using 0-based indexing, where ⌊x⌋ denotes the largest integer less than or equal to x.
For n = 1, 2, 3, 4, and 5, the middle nodes are 0, 1, 1, 2, and 2, respectively.*/
/*Approach-
Turtle hare approach but here the fast pointer should not reach last but second last so as for the slow pointer not to reach the middle but one before the middle just
*/
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};
ListNode* deleteMiddle(ListNode* head) {
    if(!head || !head->next) return nullptr;
    ListNode* slow=head;
    ListNode* fast=head;
    while (fast->next->next && fast->next->next->next)
    {
        fast=fast->next->next;
        slow=slow->next;
    }
    ListNode* temp=slow->next;
    slow->next=temp->next;
    delete temp;
    return head;


}
int main(){

    return 0;
}