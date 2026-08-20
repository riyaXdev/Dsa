class Solution {
public:

    bool sear(vector<vector<int>>& mat,int target,int m,int n,int i,int j){
        while(i<m && j>=0){
            
            if(target == mat[i][j]) return true;
            if(target < mat[i][j]){
               return sear(mat,target,m,n,i,j-1);
            }
            if(target > mat[i][j]){
               return sear(mat,target,m,n,i+1,j);
            }
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        return sear(matrix,target,m,n,0,n-1);
    }
};