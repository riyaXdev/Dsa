
class Solution {
public:
    int solve(TreeNode* root,int& maxsum){
        if(!root) return 0;
        int l = solve(root -> left,maxsum);
        int r = solve(root -> right,maxsum);

        int singlenode = root -> val;
        int eitherlorr = max(l,r) + root -> val;
        int bothincluded = l + r + root -> val;

        maxsum = max({maxsum, singlenode, eitherlorr, bothincluded});

        return max(singlenode,eitherlorr);
    }
    int maxPathSum(TreeNode* root) {
       int maxsum = INT_MIN;
        solve(root,maxsum);
        return maxsum;
    }
};