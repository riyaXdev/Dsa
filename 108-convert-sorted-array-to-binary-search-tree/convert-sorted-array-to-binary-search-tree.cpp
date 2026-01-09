
class Solution {
    TreeNode* createbst(vector<int>& nums,int start,int end){
        if(start > end) return NULL;
        int mid = start + (end - start)/2;
        TreeNode* root = new TreeNode(nums[mid]);
            
        root -> left = createbst(nums,start,mid-1);
        root -> right = createbst(nums,mid+1,end);

        return root;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
       return createbst(nums,0,nums.size()-1);
    }
};