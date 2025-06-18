#include "bits/stdc++.h"
using namespace std;
//Problem Statement
/*
Given the head of a linked list, return the list after sorting it in ascending order.
Follow up: Can you sort the linked list in O(n logn) time and O(1) memory (i.e. constant space)?
*/
/*Approach- 
Count length of the linked list.
Use iterative merge sort with sublists of size 1, 2, 4, 8, … up to n.
At each level, split the list into pairs of sublists and merge them.
Use dummy node technique to simplify list reconnections.

// Iterative
Steps:
1.Count the total length n of the list.
2.Use a dummy node pointing to head to manage merges.
3.For each step size step = 1, 2, 4, ...:
    -Traverse the list:
        --Split two consecutive sublists of length step (using split()).
        --Merge them using merge() and connect to previous merged result.
4.Continue until step >= n.

Helper Functions:
--split(head, n) → Cuts list after n nodes, returns next part.
--merge(l1, l2, prev) → Merges two sorted lists, attaches to prev, returns new tail.


// Recursive
Steps:
1. Base case: if list has 0 or 1 node, return it (already sorted).
2. Find the middle node using slow/fast pointer (getMid()).
3. Split the list into two halves: [head → mid-1] and [mid → end].
4. Recursively call sortList() on each half.
5. Merge both halves using merge() and return the result.

Helper Functions:
    getMid(head) → Returns middle node, and splits list into two.
    merge(l1, l2) → Merges two sorted lists into one.
*/
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};
// Iterative
ListNode* split(ListNode* head, int n) {
    while (--n && head)
        head = head->next;
    if (!head) return nullptr;
    ListNode* next = head->next;
    head->next = nullptr;
    return next;
}
ListNode* merge(ListNode* l1, ListNode* l2, ListNode* prev) {
    ListNode* curr = prev;
    while (l1 && l2) {
        if (l1->val < l2->val) {
            curr->next = l1;
            l1 = l1->next;
        } else {
            curr->next = l2;
            l2 = l2->next;
        }
        curr = curr->next;
    }
    curr->next = l1 ? l1 : l2;
    while (curr->next) curr = curr->next;
    return curr;
}
ListNode* sortList(ListNode* head) {
    if (!head || !head->next) return head;

    // Get length of list
    int length = 0;
    ListNode* node = head;
    while (node) {
        length++;
        node = node->next;
    }

    // creation of a dummy node
    ListNode dummy(0);
    dummy.next = head;  
    // Bottom-up merge sort
    for (int step = 1; step < length; step <<= 1) {
        ListNode* prev = &dummy;
        ListNode* curr = dummy.next;

        while (curr) {
            ListNode* left = curr;
            ListNode* right = split(left, step);
            curr = split(right, step);
            prev = merge(left, right, prev);
        }
    }
    return dummy.next;
}

// Recurisve
ListNode* getMid(ListNode* head) {
    ListNode* slow = head, *fast = head, *prev = nullptr;
    while (fast && fast->next) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    if (prev) prev->next = nullptr; // cut at mid
    return slow;
}
// Merge two sorted lists
ListNode* merge(ListNode* l1, ListNode* l2) {
    ListNode dummy(0);
    ListNode* tail = &dummy;
    while (l1 && l2) {
        if (l1->val < l2->val) {
            tail->next = l1;
            l1 = l1->next;
        } else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }
    tail->next = l1 ? l1 : l2;
    return dummy.next;
}
ListNode* sortList(ListNode* head) {
    if (!head || !head->next) return head;

    // Step 1: Split list into two halves
    ListNode* mid = getMid(head);
    ListNode* left = sortList(head);
    ListNode* right = sortList(mid);

    // Step 2: Merge the two sorted halves
    return merge(left, right);
}
int main(){
  
    return 0;
}