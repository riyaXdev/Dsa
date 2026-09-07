class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>>ans(n,vector<int>(n));
        vector<vector<int>>mat;

        int left = 0,right = n-1,bottom = n-1, top =0;
        int a = 1;
        while(top<=bottom && left <= right){
            //left tot right
            for(int i=left;i<=right;i++){
                ans[top][i] = a++;
            }
            top++;
            for(int i=top;i<=bottom;i++){
                ans[i][right] = a++;
            }
            right--;
            for(int i=right;i>=left;i--){
                ans[bottom][i] = a++;
            }
            bottom--;
            if(top <= bottom){
                for(int i=bottom;i>=top;i--){
                    ans[i][left] = a++;
                }
            }
            left++;
        }
        for(int i=0;i<n;i++){
            vector<int>vec;
            for(int j=0;j<n;j++){
                vec.push_back(ans[i][j]);
            }
            mat.push_back(vec);
        }
        return mat;
    } 
};