/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
     if(headA==nullptr || headB==nullptr) return nullptr;
     ListNode*d1=headA;
     ListNode*d2=headB;
     while(d1!=d2){
        d1=d1->next;
        d2=d2->next;
        if(d1==d2) return d2;
     
     if(d1==nullptr) d1=headB;
     if(d2==nullptr) d2=headA;
     
     }


        return d2;


    }
};