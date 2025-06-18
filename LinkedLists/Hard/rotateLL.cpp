#include "bits/stdc++.h"
using namespace std;
//Problem Statement
/*Given the head of a linked list, rotate the list to the right by k places.

Constraints:
The number of nodes in the list is in the range [0, 500].
-100 <= Node.val <= 100
0 <= k <= 2 * 109
*/
/*Approach- 
1. Find the length of the list (n)
2. Update k as k%n and if k==0 return head
3. Update last node next to head
4. Move from head to (n-k)-1 times to a node
5. Make this node's next as head and then update this node's next as nullptr
6. Return head.
*/
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};
ListNode* rotateRight(ListNode* head, int k) {
    if(!head || !head->next) return head;
    ListNode* tail=head;
    int n=1;
    // 1 2 3 4 5
    while (tail->next)
    {
        tail=tail->next;
        n++;
    }
    k=k%n;
    if(!k) return head;
    tail->next=head;
    tail=head;
    for (int i = 0; i < (n-k)-1; i++)
    {
        tail=tail->next;
    }
    head=tail->next;
    tail->next=nullptr;
    return head;
}
int main(){
  
    return 0;
}