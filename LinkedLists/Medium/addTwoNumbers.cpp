#include "bits/stdc++.h"
using namespace std;
//Problem Statement
/*
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.
You may assume the two numbers do not contain any leading zero, except the number 0 itself.
*/
/*Approach- 
1. Take two pointers each pointing to one of linkedLists and take a value carry with it
2. Sum , carry , int sum=(a+b+carry)%10; carry=(a+b+carry)/10;
3. Make a new node and add this value to it and make a new node to next to it. and return this new list.
*/
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ptr1=l1;
        ListNode* ptr2=l2;
        ListNode* ans=new ListNode(0);
        ListNode* ansHead=ans;
        int carry=0;
        while (ptr1 || ptr2)
        {
            int a=(ptr1)?ptr1->val:0;
            int b=(ptr2)?ptr2->val:0;
            int sum=(a+b+carry)%10;
            carry=(a+b+carry)/10;
            ListNode* temp=new ListNode(sum);
            ans->next=temp;
            ans=ans->next;
            ptr1=(ptr1)?ptr1->next:nullptr;
            ptr2=(ptr2)?ptr2->next:nullptr;
        }
        if(carry){
            ans->next=new ListNode(carry);
        }
        return ansHead;
}
int main(){
  
    return 0;
}