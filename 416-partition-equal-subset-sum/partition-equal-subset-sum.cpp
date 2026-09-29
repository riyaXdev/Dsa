class Solution {
    //TABULATION
public:
    bool canPartition(vector<int>& nums) {
        int total = 0;
        int n = nums.size();
        for(int i:nums) total += i;    
        if(total % 2 == 0) {
            int target = total / 2;
            vector<vector<bool>>dp(n,vector<bool>(target+1,0));
            //base case
            for(int i=0;i<n;i++) dp[i][0] = true;
            if(nums[0] <= target) dp[0][nums[0]] = true;
            //other cases 1,2,3....n
            for(int ind = 1; ind<n ;ind++){
                for(int k = 1; k<=target; k++){
                    bool nottake = dp[ind-1][k];
                    bool take = false;
                    if(k >= nums[ind]) take = dp[ind-1][k - nums[ind]];
                    dp[ind][k] = take | nottake;
                }
            }
            return dp[n-1][target];
        }
        return false; // total is odd

    }
};