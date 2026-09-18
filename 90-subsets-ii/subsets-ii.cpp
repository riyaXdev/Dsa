class Solution {
    void f(int idx,vector<int>&nums,vector<vector<int>>& ans,vector<int>&ds){
            ans.push_back(ds);
           for(int i=idx;i<nums.size();i++){
            if(i>idx && nums[i] == nums[i-1]) continue;
            ds.push_back(nums[i]);
            f(i+1,nums,ans,ds);
            ds.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>ds;
        //set<vector<int>>st;
        sort(nums.begin(),nums.end());
        f(0,nums,ans,ds);
        return ans;
    }
};