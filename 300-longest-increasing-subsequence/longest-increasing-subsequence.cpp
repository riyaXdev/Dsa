class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n,1);
        for(int i=0;i<n;i++){
            for(int prev=0;prev<i;prev++){
                if(nums[i] > nums[prev] && dp[i] < dp[prev] + 1) dp[i] = dp[prev] + 1;
            }
        }
        int maxilen=0;
        for(int i=1;i<n;i++){
            if(dp[i] > dp[maxilen]) maxilen = i;
        }
        return dp[maxilen] ;
    }
};