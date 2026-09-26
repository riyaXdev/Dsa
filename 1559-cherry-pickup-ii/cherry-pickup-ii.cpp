class Solution {
    int f(int r,int c1,int c2,int m,int n,vector<vector<int>>&grid,vector<vector<vector<int>>>&dp){
        //base case
        //boundary cond
        if(c1<0 || c1>=n || c2<0 || c2>=n) return -1e9;
        //destination
        if(r==m-1){
            if(c1==c2) return grid[r][c1];
            else return grid[r][c1] + grid[r][c2];
        }
        if(dp[r][c1][c2] != -1) return dp[r][c1][c2];
        //maximum of 9 combination
        int maxi = -1e9;
        for(int j1=-1; j1<=1;j1++){
            for(int j2=-1; j2<=1; j2++){
                  int solve = f(r+1, c1+j1, c2+j2,m,n,grid,dp);
                  maxi = max(maxi,solve);
            }
        }
        //add current row's cherries/value
        if(c1==c2) maxi += grid[r][c1];
        else maxi += grid[r][c1] + grid[r][c2];

        return dp[r][c1][c2] = maxi;
    }
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<vector<int>>>dp(m,vector<vector<int>>(n,vector<int>(n,-1)));
        return f(0,0,n-1,m,n,grid,dp);
    }
};