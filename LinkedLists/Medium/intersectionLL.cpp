#include "bits/stdc++.h"
using namespace std;
//Problem Statement
/*
Given the heads of two singly linked-lists headA and headB, return the node at which the two lists intersect. If the two linked lists have no intersection at all, return null.
The test cases are generated such that there are no cycles anywhere in the entire linked structure.
Note that the linked lists must retain their original structure after the function returns.
Custom Judge:
The inputs to the judge are given as follows (your program is not given these inputs):
intersectVal - The value of the node where the intersection occurs. This is 0 if there is no intersected node.
listA - The first linked list.
listB - The second linked list.
skipA - The number of nodes to skip ahead in listA (starting from the head) to get to the intersected node.
skipB - The number of nodes to skip ahead in listB (starting from the head) to get to the intersected node.
The judge will then create the linked structure based on these inputs and pass the two heads, headA and headB to your program. If you correctly return the intersected node, then your solution will be accepted.
*/
/*Approach- 
1. Move both pointers one by one as soon as one  reaches end
2. Move it to head of other list and again move as soon as other also reaches end
3. Move it to head of other list and now move both pointers together if they are same return and still not then return nullptr

*/
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode* ptrA=headA;
    ListNode* ptrB=headB;
    while (ptrA || ptrB)
    {
        if(ptrA==ptrB){
            return ptrA;
        }
        if(!ptrA){
            ptrA=headB;
            while (ptrB)
            {
                ptrA=ptrA->next;
                ptrB=ptrB->next;
            }
            ptrB=headA;
            break;
        }
        else if(!ptrB){
            ptrB=headA;
            while (ptrA)
            {
                ptrA=ptrA->next;
                ptrB=ptrB->next;
            }
            ptrA=headB;
            break;
        }
        ptrA=ptrA->next;
        ptrB=ptrB->next;
    }

    while((ptrA && ptrB)){
        if(ptrA==ptrB){
            return ptrA;
        }
        ptrA=ptrA->next;
        ptrB=ptrB->next;
    }
    return nullptr;
}
int main(){
  
    return 0;
}