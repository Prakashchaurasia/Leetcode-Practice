class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n=board.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                for(int k=j+1;k<n;k++){
                   if(board[i][j]==board[i][k] && board[i][j]!='.') return false;
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                for(int k=j+1;k<n;k++){
                   if(board[j][i]==board[k][i] && board[j][i]!='.') return false;
                }
            }
        }
        for(int row=0; row<3; row++){
            for(int col=0; col<3; col++){
                vector<bool> seen(10,false);
                for(int i=0; i<3; i++){
                    for(int j=0; j<3; j++){
                        char c = board[row*3+i][col*3+j];
                        if(c!='.'){
                            int num = c - '0';
                            if(seen[num]) return false;
                            seen[num] = true;
                        }
                    }
                }
            }
        }
        return true;
    }
};