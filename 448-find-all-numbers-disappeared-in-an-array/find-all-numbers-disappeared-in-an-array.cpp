class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int>ans;
        int n=nums.size();
        unordered_map<int,int>mpp;
        for(int i=0;i<n;i++) mpp[nums[i]]++;
        for(int i=0;i<n;i++){
           if(mpp[i+1] == 0) ans.push_back(i+1);
        }
        return ans;
    }
};