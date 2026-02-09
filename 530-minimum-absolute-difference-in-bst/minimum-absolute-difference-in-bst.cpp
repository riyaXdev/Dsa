
class Solution {
    void intraversal(TreeNode* root, vector<int>& ans){
        if(!root) return;
        intraversal(root -> left,ans);
        ans.push_back(root -> val);
        intraversal(root -> right,ans);
    }
public:
    int getMinimumDifference(TreeNode* root) {
        vector<int> ans;
        intraversal(root,ans);
        int minn = INT_MAX;
        for(int i=1; i<ans.size(); i++){
            int aa = ans[i] - ans[i-1];
            if(aa < minn){
                minn = aa;
            }
        }
        return minn;
    }
};