class Solution {
public:
    int findNumberOfLIS(vector<int>& arr) {
        int n = arr.size();
        vector<int>dp(n,1),cnt(n,1);
        int maxi = 0,max_index=0;
        for(int i=0;i<n;i++){
            for(int prev=0;prev<i;prev++){
                if(arr[i] > arr[prev] && dp[i] < 1 + dp[prev]){
                    dp[i] = 1 + dp[prev];
                    cnt[i] = cnt[prev];
                }
                else if(arr[i] > arr[prev] && dp[i] == 1 + dp[prev]){
                    cnt[i] += cnt[prev];
                }
            }
          maxi = max(dp[i],maxi);
        }
        int count = 0;
       for(int i=0;i<n;i++){
        if(dp[i] == maxi) count += cnt[i];
       }
       return count;
    }
};