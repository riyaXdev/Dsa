
class Solution {
    void dfss(TreeNode* root, int&sum){
        if(!root) return;
        dfss(root -> right,sum);
        sum += root -> val;
        root -> val = sum;
        dfss(root -> left,sum);
    }
public:
    TreeNode* convertBST(TreeNode* root) {
        int sum = 0;
        dfss(root,sum);
        return root;

    }
};