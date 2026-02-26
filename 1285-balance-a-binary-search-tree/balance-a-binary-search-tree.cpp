
class Solution {
    /*int checkheight(TreeNode* root){
        if(!root) return 0;
        int left = checkheight(root -> left);
        if(left==-1){
            return -1;
        } 
        int right = checkheight(root -> right);
        if(right == -1){
            return -1;
        }
        if(abs(left-right)>1){
            return -1;
        }
        return 1 + max(left,right);
        
    }
    */
    void inorder(TreeNode* root,vector<int>& ans){
        if(!root) return;
        inorder(root -> left,ans);
        ans.push_back(root -> val);
        inorder(root -> right,ans);
    }
TreeNode* makebst(int s,int e,vector<int>& ans){
    if(s>e){
        return NULL;
    }
    int mid = (s+e)/2;
    TreeNode* root = new TreeNode(ans[mid]);
    root -> left = makebst(s,mid-1,ans);
    root -> right = makebst(mid+1,e,ans);
    return root;
}
public:
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> ans;
        inorder(root,ans);
        return makebst(0,ans.size()-1,ans);
    }
};