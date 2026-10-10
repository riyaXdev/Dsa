class Solution {
    bool ispossible(string &s1,string &s2){
        int n = s1.size();
        int m = s2.size();
        if(n != m+1) return false;
        else{
            int i=0,j=0;
            while(i<n){
                if(s1[i] == s2[j]){
                    i++;
                    j++;
                }
                else i++;
            }
            if(i==n && j==m) return true;
            return false;
        }
    }

public:
    int longestStrChain(vector<string>& nums) {
        sort(nums.begin(),nums.end(),[](string &s1,string &s2){
            return s1.size()<s2.size(); // sort on  basis of length
        });
        int n = nums.size();
        vector<int>dp(n,1);
        int maxi = 0,max_ind=0;
        for(int i=0;i<n;i++){
            for(int prev=0;prev<i;prev++){
                if((ispossible(nums[i],nums[prev]))) {
                    dp[i] = max(dp[i],dp[prev] + 1);
                }
            }
           maxi = max(dp[i],maxi);
        }
        return maxi;;
    }
};