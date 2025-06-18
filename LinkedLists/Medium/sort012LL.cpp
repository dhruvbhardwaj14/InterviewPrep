#include "bits/stdc++.h"
using namespace std;
//Problem Statement
/*
Sort a LL of 0's 1's and 2's by changing links
*/
/*
Approach- 
1. Take three dummy nodes and call it zerohead, onehead and twohead.
2. Traverse whole list using temp pointer
3. if temp val is 0 add it to zerohead's next similarly do for 1 and 2
4. Take one one each more pointers as zerotail,onetail,twotail etc
5. in end connect zerotail to onehead, onetail to twohead and return zerohead
*/
struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};
Node* segregate(Node* head) {
    if(head==NULL ||head->next==NULL){
        return head;
    }
    Node* temp=head;
    Node* zerohead=new Node(-1);
    Node* onehead=new Node(-1);
    Node* twohead=new Node(-1);
    Node* zerotail=zerohead;
    Node* onetail=onehead;
    Node* twotail=twohead;
    while (temp)
    {
        switch(temp->data){
            case 0:
                zerotail->next=temp;
                zerotail=zerotail->next;
                break;
            case 1:
                onetail->next=temp;
                onetail=onetail->next;
                break;
            default:
                twotail->next=temp;
                twotail=twotail->next;
                break;
        }
        temp=temp->next;
    }
    twotail->next=NULL;
    zerotail->next=(onehead->next)?onehead->next:twohead->next;
    onetail->next=(twohead->next)?twohead->next:nullptr;
    return zerohead->next;
    
}
int main(){
  
    return 0;
}