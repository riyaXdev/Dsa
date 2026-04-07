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
    ListNode* swapNodes(ListNode* head, int k) {
        vector<int> ans;
        ListNode* temp = head;
       // storing values in a array
        while(temp != NULL){
            ans.push_back(temp -> val);
            temp = temp -> next;
        }
        int n = ans.size();
        //swapping values
        swap(ans[k-1], ans[n-k]);
        //rebuilding linked lists

        ListNode* newnode = new ListNode(ans[0]);
        ListNode* tailnode = newnode;
        for(int i=1;i<n;i++){
            tailnode -> next = new ListNode(ans[i]);
            tailnode = tailnode -> next;
        }
        return newnode;
    }
};