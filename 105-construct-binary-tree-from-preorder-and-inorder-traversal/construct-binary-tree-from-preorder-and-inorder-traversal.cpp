class Solution {
    void inordermap(vector<int>& inorder,unordered_map<int , int>& inordelemep){
        for(int i=0; i<inorder.size(); i++){
            inordelemep[inorder[i]] = i;
        }
    }

TreeNode* solve(vector<int>& preorder, vector<int>& inorder, int &preIndex, int inordstart,
                           int inordend, int n,unordered_map<int , int> &inordelemep){
    //base case
    if(preIndex >= n || inordstart > inordend){
        return NULL;
    }
    int element = preorder[preIndex];
    preIndex++;
    TreeNode* root = new TreeNode(element);
    int pos = inordelemep[element]; 
    root -> left = solve(preorder,inorder, preIndex,inordstart,pos -1,n,inordelemep);
    root -> right = solve(preorder, inorder, preIndex, pos +1, inordend,n,inordelemep);

    return root;
}
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preIndex = 0;
        int n = inorder.size();
        unordered_map<int , int> inordelemep;
        inordermap(inorder,inordelemep);
        TreeNode* ans = solve(preorder,inorder,preIndex,0,n-1,n,inordelemep);
        return ans;
    }
};