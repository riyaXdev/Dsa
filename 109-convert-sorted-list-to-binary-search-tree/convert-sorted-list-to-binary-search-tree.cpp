
class Solution {
        TreeNode* makebst(int start, int end, vector<int>& ans){
            if(start > end){
                return NULL;
            }
            int mid = (start + end)/2;
            TreeNode*  root = new TreeNode(ans[mid]);
            root ->left = makebst(start,mid-1,ans);
            root -> right = makebst(mid+1,end,ans);
            return root;
        }
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if(!head) return NULL;
        vector<int>ans;
        ListNode* temp = head;
        while(temp != NULL){
            ans.push_back(temp -> val);
            temp = temp -> next;
        }
        return makebst(0,ans.size()-1,ans);
    }
};