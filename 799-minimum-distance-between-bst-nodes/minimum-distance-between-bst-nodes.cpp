
class Solution {
    void inordertra(TreeNode* root, vector<int>& ans){
        if(!root) return;
        inordertra(root -> left,ans);
        ans.push_back(root -> val);
        inordertra(root -> right, ans);
    }
public:
    int minDiffInBST(TreeNode* root) {
        vector<int> ans;
        inordertra(root,ans);
        int minn = INT_MAX;
        for(int i=1; i<ans.size(); i++){
            int va = ans[i] - ans[i-1];
            if(va < minn){
                minn = va;
            }
        }
        return minn;
    }
};