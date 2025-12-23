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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        > pq;
      for(int i=0;i<lists.size();i++){
        if(lists[i]!=nullptr){
            pq.push({lists[i]->val,i});
            lists[i]=lists[i]->next;
        }
      }
      ListNode* dummy=new ListNode(-1);
      ListNode* tail=dummy;
      while(!pq.empty()){
        auto[val,idx]=pq.top();
        pq.pop();

      tail->next=new ListNode(val);
      tail=tail->next;
      if(lists[idx]!=nullptr){
        pq.push({lists[idx]->val,idx});
        lists[idx]=lists[idx]->next;
      }

      }

     return dummy->next;

    }
};