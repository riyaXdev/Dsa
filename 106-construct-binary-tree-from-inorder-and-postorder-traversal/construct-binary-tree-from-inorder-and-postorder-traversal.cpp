
class Solution {
    TreeNode* solve(vector<int>& inorder, vector<int>& postorder, int &postindex,int instart, int inend,
                     unordered_map<int, int>& mapping){
        if(postindex < 0 || instart > inend) return NULL;
        int element = postorder[postindex];
        postindex--;
        TreeNode* root = new TreeNode(element);
        int pos = mapping[element];
        root -> right = solve(inorder,postorder,postindex,pos +1,inend, mapping);
        root -> left = solve(inorder,postorder,postindex,instart,pos -1,mapping);
        return root;
    
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int> mapping;
        for(int i=0; i<inorder.size(); i++){
            mapping[inorder[i]] = i;
        }
        int postindex = postorder.size() -1;
        TreeNode* ans = solve(inorder,postorder,postindex,0,postorder.size() -1, mapping);
        return ans;
    }
};