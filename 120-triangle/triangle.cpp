class Solution {
public: //tabulation
    int minimumTotal(vector<vector<int>>& arr) {
        int m = arr.size();
        vector<vector<int>>dp(m,vector<int>(m,-1));
        //base case
        for(int i=0;i<m;i++){ 
            dp[m-1][i] = arr[m-1][i];
        }
        //other case
        for(int i=m-2;i>=0;i--){
            for(int j=i;j>=0;j--){
                int d = arr[i][j] + dp[i+1][j];
                int diag = arr[i][j] + dp[i+1][j+1];
                dp[i][j] = min(d,diag);
            }
        }
        return dp[0][0];
    }
};