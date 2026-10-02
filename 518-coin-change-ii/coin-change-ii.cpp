class Solution {
    int f(int i,int amount,vector<int>&coins,vector<vector<int>>&dp){
        if(i==0) return (amount % coins[0] == 0); // returns 1 if it is divisible else returns 0
        if(dp[i][amount] != -1) return dp[i][amount];
        int nottake = f(i-1,amount,coins,dp);;
        int take = 0;
        if(amount>=coins[i]) take = f(i,amount-coins[i],coins,dp);
        return dp[i][amount] = take + nottake;
    }
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        return f(n-1,amount,coins,dp);
    }
};
