
class Solution {
    void rangebst(TreeNode* root, int low, int high, int &sum){
        if(!root) return;
        if( root -> val <= high && root -> val >= low){
            sum = sum + root -> val;
        }
        rangebst(root -> left,low,high,sum);
        rangebst(root -> right,low,high,sum);
    }
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        int sum = 0;
        rangebst(root,low,high,sum);
        return sum;
    }
};