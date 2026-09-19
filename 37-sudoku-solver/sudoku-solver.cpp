class Solution {
    bool solve(vector<vector<char>>&board){
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j] == '.'){
                    for(char c='1'; c<='9'; c++){ // try for all no from 1 to 9
                        if(issafe(board,i,j,c) == true){ // only place when it's safe
                            board[i][j] = c;
                            if(solve(board) == true){ //if get atleast one answer so stop. do not proceed further
                                return true;
                            }
                            else board[i][j] = '.';
                        }
                    }
                    return false; //when not able to place any char in board
                }
            }
        }
        return true; // when do not get any empty space that means all spaces filled correctly
    }
    bool issafe(vector<vector<char>>&board,int row,int col,char c){
        for(int i=0;i<9;i++){
            if(board[i][col] == c) return false; // checking for entire col
            if(board[row][i] == c) return false; // for row
            if(board[3*(row/3) + i/3][3*(col/3) + i%3] == c) return false;
        }
        return true; // if none of the cond true
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};