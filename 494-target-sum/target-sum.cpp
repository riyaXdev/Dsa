class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int total = 0;
        for(int it:nums) total += it;
        int s1 = (total + target)/2;
        if( (total + target) < 0 || (total + target) % 2 ) return 0;
        target = s1;
        vector<vector<int>>dp(n,vector<int>(target +1,0));

        // base case
        if(nums[0] == 0) dp[0][0] = 2;
        else dp[0][0] = 1;
        if(nums[0] != 0 && nums[0] <= target) dp[0][nums[0]] = 1;

        // other cases
        for(int i=1;i<n;i++){
            for(int k=0;k<=target;k++){
                int nottake = dp[i-1][k];
                int take = 0;
                if(nums[i] <=k) take = dp[i-1][k-nums[i]];
                dp[i][k] = take + nottake;
            }
        }
      return dp[n-1][target];
    }
};