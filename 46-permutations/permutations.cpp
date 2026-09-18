class Solution {
    void f(vector<int>& nums,vector<vector<int>>&ans,vector<int>& ds,unordered_map<int,int>&mpp){
        if(ds.size() == nums.size()){  //base case
            ans.push_back(ds); 
            return;
        }
        for(int i=0; i<nums.size(); i++){
            if(mpp[i] == 0){
                ds.push_back(nums[i]);
                mpp[i] = 1;
                f(nums,ans,ds,mpp);
                ds.pop_back(); // remove ele while going back
                mpp[i] = 0; // mark it as not present since it is now removed
            }
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>ds;
        unordered_map<int,int>mpp;
        f(nums,ans,ds,mpp);
        return ans;
    }
};