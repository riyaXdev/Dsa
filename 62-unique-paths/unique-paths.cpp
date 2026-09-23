class Solution {
    int solve(int i,int j,int m,int n,vector<vector<int>>&dp){
        if(i==m-1 && j==n-1) return 1;
        if(i+1>m || j+1>n) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int d = solve(i+1,j,m,n,dp);
        int r = solve(i,j+1,m,n,dp);
        return dp[i][j] =  d+r;
        
    }
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return solve(0,0,m,n,dp);
    }
};