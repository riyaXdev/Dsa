
class Solution {
    void inorder(TreeNode* root,vector<int>& ans){
        if(!root) return;
        inorder(root -> left,ans);
        ans.push_back(root -> val);
        inorder(root -> right,ans);
    }
public:
    bool isValidBST(TreeNode* root) {
        vector<int> ans;
        inorder(root,ans);
        for(int i=0; i +1 <ans.size();i++){
            if(ans[i] >= ans[i+1]){
                return false;
            }
        }
        return true;

    }
};