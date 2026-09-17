class Solution {
public:
void f(int i,vector<vector<int>>& ans, vector<int>& nums,vector<int>&temp){
    if(i>=nums.size()){
        ans.push_back(temp);
        return;

    }
    temp.push_back(nums[i]);
    f(i+1,ans,nums,temp); // take it
    temp.pop_back();
    f(i+1,ans,nums,temp); // not take it
}
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>temp;
        f(0,ans,nums,temp);
        return ans;
    }
};