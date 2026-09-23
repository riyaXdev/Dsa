class Solution {
    int solve(int i,vector<int>&arr,vector<int>&dp){
             dp[0] = arr[0];
             for(int i=1;i<arr.size();i++){
                int pick = arr[i];
                if(i>1) pick += dp[i-2];
                int notpick = 0 + dp[i-1];
                dp[i] = max(pick,notpick);
             }
             return dp[arr.size()-1];
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n-1,-1);
        vector<int>temp1,temp2;
        if(n==1) return nums[0];
        for(int i=0;i<n;i++){
            if(i!=0) temp1.push_back(nums[i]); // do not include fist ele
            if(i!=n-1) temp2.push_back(nums[i]); // do not include last ele
        }
        return max(solve(n-2,temp1,dp),solve(n-2,temp2,dp));
    }
};