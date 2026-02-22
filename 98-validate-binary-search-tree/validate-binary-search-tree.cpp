
class Solution {
    bool isbst(TreeNode* root,long long min,long long max){
        if(!root) return true;
        if(root -> val <= min || root -> val >= max){
            return false;
        }
        return isbst(root -> left,min,root -> val) && isbst(root -> right,root -> val,max);
    }
public:
    bool isValidBST(TreeNode* root) {
        return isbst(root,LLONG_MIN,LLONG_MAX);
    }
};