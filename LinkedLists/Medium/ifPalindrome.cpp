#include "bits/stdc++.h"
using namespace std;
//Problem Statement
/*
Given the head of a singly linked list, return true if it is a palindrome or false otherwise.
Follow up: Could you do it in O(n) time and O(1) space?
*/
/*Approach-
1.Find the middle of the linked list using slow and fast pointers.
2.Reverse the second half of the list.
3.Compare the first and reversed second half node by node.
4.(Optional but good practice) Restore the original list by reversing the second half again.
*/
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};
ListNode* reverseList(ListNode* head) {
    if(head==nullptr || head->next==nullptr) return head;
    ListNode* newHead = reverseList(head->next); // reverse the rest
    head->next->next = head; // make the next node point back to current
    head->next = nullptr;    // break the original link
    return newHead; // return new head from recursion
}
bool isPalindrome(ListNode* head) {
    if(head==nullptr || head->next==nullptr) return true;
    ListNode* slow=head;
    ListNode* fast=head;
    // Step 1: Find middle
    while (fast->next && fast->next->next)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    // Step 2: Reverse second half
    ListNode* secondHalfStart=reverseList(slow->next);
    // Step 3: Compare both halves
    ListNode* p1 = head;
    ListNode* p2 = secondHalfStart;
    bool palindrome = true;
    while (p2) {
        if (p1->val != p2->val) {
            palindrome = false;
            break;
        }
        p1 = p1->next;
        p2 = p2->next;
    }
    // Step 4: Restore list (optional)
    slow->next = reverseList(secondHalfStart);
    return palindrome;
}
int main(){

    return 0;
}