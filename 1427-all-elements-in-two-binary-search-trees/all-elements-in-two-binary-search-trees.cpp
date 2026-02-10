
class Solution {
    void inorderr(TreeNode* root, vector<int> &sum){
        if(!root) return;
        inorderr(root -> left,sum);
        sum.push_back(root -> val);
        inorderr(root -> right,sum);
    }
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> ans1;
        vector<int> ans2;
        inorderr(root1,ans1);
        inorderr(root2,ans2);
        int m = ans1.size() - 1 ;
        int n = ans2.size() - 1 ;
        int k = ans1.size() + ans2.size() - 1;
        vector<int> ans3(k+1);
        while(m>=0 && n >=0){
            if(ans1[m] > ans2[n]){
                ans3[k--] = ans1[m--];
            }
            else{
                ans3[k--] = ans2[n--];
            }
        }
        //copy remaining elements
        while(m>=0) ans3[k--] = ans1[m--];
        while(n>=0) ans3[k--] = ans2[n--];
    return ans3;
    }
};