class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        vector<int>dp(n,1),hash(n);
        for(int i=0;i<n;i++){
            hash[i] = i;
            for(int prev=0;prev<i;prev++){
                if(nums[i] % nums[prev] == 0 && dp[i] < dp[prev] + 1) {
                    dp[i] = dp[prev] + 1;
                    hash[i] = prev;
                }
            }
        }
        int maxi = 1;
        int max_ind =0;
        for(int i=0;i<n;i++){
            if(dp[i] > maxi){
                maxi = dp[i];
                max_ind =i;
            }
        }
        vector<int>temp;
        temp.push_back(nums[max_ind]);
        while(hash[max_ind] != max_ind){
            max_ind = hash[max_ind];
            temp.push_back(nums[max_ind]);
       }
       reverse(temp.begin(),temp.end());
       return temp;
    }
};