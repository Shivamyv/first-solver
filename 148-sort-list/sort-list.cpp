/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* TwoList(ListNode* list1 , ListNode* list2){
        ListNode* res = new ListNode(0);
        ListNode* temp = res;
        ListNode* temp1 = list1;
        ListNode* temp2 = list2;

        while (temp1 != NULL && temp2 != NULL) {
            if (temp1->val < temp2->val) {
                temp->next = temp1;
                temp1 = temp1->next;
            } else {
                temp->next = temp2;
                temp2 = temp2->next;
            }
            temp = temp->next;
        }

        if (temp1 != NULL) temp->next = temp1;
        if (temp2 != NULL) temp->next = temp2;

        return res->next; 
    }

   
    ListNode* sortList(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;

        
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast->next != NULL && fast->next->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        
        ListNode* a = head;
        ListNode* b = slow->next;
        slow->next = NULL;

        
        a = sortList(a);
        b = sortList(b);

       
        return TwoList(a, b);
    }
};