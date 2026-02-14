
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL) return NULL;
        int cnt = 0;
        ListNode* curr = head;
        //check if k nodes exists or not
        while(cnt<k){
            if(!curr) return head;
            curr = curr -> next;
            cnt++;
        }
         curr = head;
         ListNode* prev = NULL;
         ListNode* forward = NULL;
         cnt = 0;
         while(curr != NULL && cnt <k){
            forward = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = forward;
            cnt++;
         }
         if(forward != NULL){
            head -> next = reverseKGroup(forward,k);
         }
         return prev;
    }
};