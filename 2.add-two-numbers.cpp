
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *l3=new ListNode();
        ListNode *head=l3;
        int val=0;
        int carry=0;
        while(l1!=nullptr||l2!=nullptr||carry!=0){
            val=0;
            // add if l1 not null
            if(l1){
                val+=l1->val;
                l1=l1->next;
            }
            if(l2){
                val+=l2->val;
                l2=l2->next;
            }
            // add carry also if exists
            if(carry!=0){
                val+=carry;
                carry=0;
            }
            // separate carry and last bit
            carry=val/10;
            val=val%10;
            l3->val=val;
            // create next only if necessary
            if(l1||l2||carry!=0){
                l3->next=new ListNode();
                l3=l3->next;
            }
        }
        return head;
    }
};
