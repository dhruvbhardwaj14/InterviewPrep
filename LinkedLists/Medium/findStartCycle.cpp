#include "bits/stdc++.h"
using namespace std;
//Problem Statement
/*
Given the head of a linked list, return the node where the cycle begins. If there is no cycle, return null.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to (0-indexed). It is -1 if there is no cycle. Note that pos is not passed as a parameter.

Do not modify the linked list.

Can you solve it using O(1) (i.e. constant) memory?
*/
/*
Approach- 
1.Detect if a cycle exists using two pointers:
-slow moves 1 step at a time.
-fast moves 2 steps at a time.
-If they meet → there is a cycle.

2. Find the start of the cycle:
-Reset slow to head.
-Move both slow and fast one step at a time.
-The node where they meet again is the start of the cycle.

If the cycle exists:
Let’s say:
Distance from head to start of cycle = a
Distance from start of cycle to meeting point = b
Length of cycle = c
After some algebra from the Floyd’s logic:
When pointers meet:
2(a + b) = a + b + n*c → so a = n*c - b
That means if one pointer starts from head and another from the meeting point, they’ll meet at the start of the cycle.
*/
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};
ListNode* detectCycle(ListNode* head) {
    if (!head || !head->next) return nullptr;

    ListNode* slow = head;
    ListNode* fast = head;

    // Step 1: Detect if a cycle exists
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            // Step 2: Find the start of the cycle
            slow = head;
            while (slow != fast) {
                slow = slow->next;
                fast = fast->next;
            }
            return slow; // Cycle start node
        }
    }
    return nullptr; // No cycle
}

int main(){
  
    return 0;
}