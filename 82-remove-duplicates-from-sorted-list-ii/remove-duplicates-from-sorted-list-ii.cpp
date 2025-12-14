
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* curr = head;
        ListNode* dummy = new ListNode(-1);
        ListNode* prev = dummy;
        dummy -> next = head;
        while(curr != NULL){
            if( curr -> next != NULL && curr -> val == curr -> next -> val){
                while(curr -> next != NULL && curr -> val == curr -> next -> val){
                    curr = curr -> next;
                }
                prev -> next = curr -> next;
                curr = curr -> next;
            }
            else{
                prev = curr;
                curr = curr -> next;
            }
        } 
        return dummy -> next;
    }
};