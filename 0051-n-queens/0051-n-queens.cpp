class Solution {
public:
    bool canPlaceQueen(int row,int col,int n){
        for(int i=row-1;i>=0;i--){
            if(grid[i][col]=='Q') return false;
        }
        for(int i=row-1,j=col-1;i>=0 && j>=0;i--,j--){
            if(grid[i][j]=='Q') return false;
        }
        for(int i=row-1,j=col+1;i>=0 && j<n;i--,j++){
            if(grid[i][j]=='Q') return false;
        }
        return true;
    }
    vector<vector<string>> result;
    vector<vector<char>> grid;
    void f(int row,int n){
        if(row==n){
            vector<string> res;
            for(int i=0;i<n;i++){
                string temp="";
                for(int j=0;j<n;j++){
                     temp+=grid[i][j];
                }
                res.push_back(temp);
            }
            result.push_back(res);
            return;
        }
        for(int col=0;col<n;col++){
            if(canPlaceQueen(row,col,n)){
                grid[row][col]='Q';
                f(row+1,n);
                grid[row][col]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        grid.clear();
        result.clear();
        grid.resize(n,vector<char> (n,'.'));
        f(0,n);
        return result;
    }
};