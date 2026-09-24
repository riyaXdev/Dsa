//MEMOIZATION
class Solution {
    int f(int i,int j,vector<vector<int>>&matrix,vector<vector<int>>&dp,int n){
        if(i==0) return matrix[0][j];
        else if(dp[i][j] != 1e9) return dp[i][j];
        else{
        int s = matrix[i][j] + f(i-1,j,matrix,dp,n);
        int ul = INT_MAX, ur = INT_MAX;
        // see it should not go out of boundary
        if(j>0) ul = matrix[i][j] + f(i-1,j-1,matrix,dp,n);
        if(j<n-1) ur = matrix[i][j] + f(i-1,j+1,matrix,dp,n);
        return dp[i][j] = min(s,min(ul,ur));
        }
    }
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>>dp(n,vector<int>(n,1e9));
        int mini = INT_MAX;
        for(int i=0;i<n;i++){
            mini = min(f(n-1,i,matrix,dp,n),mini);
        }
        return mini;
    }
};