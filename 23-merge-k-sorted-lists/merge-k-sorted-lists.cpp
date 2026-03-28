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
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;
        priority_queue<pair<int,ListNode*>, vector<pair<int,ListNode*>>, greater<pair<int,ListNode*>>> pq;
        for(int i=0; i<lists.size(); i++){
                if(lists[i] != NULL){
                 pq.push({lists[i] -> val, lists[i]});

                }
        }
        while(!pq.empty()){
             pair<int,ListNode*> p = pq.top();
             pq.pop();
             temp -> next = p.second;
            temp = temp -> next;
             if(p.second -> next){// agar uska next element exists kar rha h hai
                pq.push({p.second -> next -> val, p.second -> next});
             } 
        }
        return dummy -> next;
    }
};