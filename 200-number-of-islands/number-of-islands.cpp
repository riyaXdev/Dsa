class Solution {

    void dfs(int i,int j,vector<vector<char>>& grid, vector<vector<bool>>& visit, int m, int n){
        if(i<0 || j<0 || i>=m || j>=n || grid[i][j] == '0' || visit[i][j]){
            return;
        }
        visit[i][j] = true;


        dfs(i-1,j,grid,visit,m,n);
        dfs(i+1,j,grid,visit,m,n);
        dfs(i,j-1,grid,visit,m,n);
        dfs(i,j+1,grid,visit,m,n);
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;
        vector<vector<bool>>visit(m,vector<bool>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == '1' && !visit[i][j]){
                    count++; //found an isalnd
                    dfs(i,j,grid,visit,m,n);
                }
            }
        }
        return count;
    }
};