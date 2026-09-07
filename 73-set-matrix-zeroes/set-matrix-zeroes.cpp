class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int>row;
        vector<int>colm;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j] == 0){
                    row.push_back(i);
                    colm.push_back(j);
                }
            }
        }
        for(int el:row){
            for(int i=0;i<m;i++){
                if(i==el){
                    for(int j=0;j<n;j++){
                        matrix[i][j] = 0;
                    }
                }
            }
        }
        for(int sl:colm){
            for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                    if(j==sl){
                        matrix[i][j] = 0;
                    }
                }
            }
        }
    }
};