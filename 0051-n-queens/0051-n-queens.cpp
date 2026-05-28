class Solution {
public:
    
    void solve(int col, vector<string>&board, vector<vector<string>>&res,int n, vector<int>&leftrow, vector<int>&lowdiag, vector<int>&upperdiag)
    {
        if(col==n){
            res.push_back(board);
            return;
        }
        for(int row=0;row<n;row++)
        {
            if(leftrow[row]==0 && lowdiag[row+col] == 0 && upperdiag[n-1 + col - row] == 0)
            {   
                board[row][col] = 'Q';
                leftrow[row] = 1;
                lowdiag [row + col] =1;
                upperdiag[n-1 + col - row] = 1;
                solve(col+1,board,res,n,leftrow,lowdiag,upperdiag);
                board[row][col] = '.';
                leftrow[row] = 0;
                lowdiag [row + col] =0;
                upperdiag[n-1 + col - row] = 0;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>board(n);
        string s(n,'.');
        vector<int>leftrow(n,0);
        vector<int>lowdiag(2*n-1,0);
        vector<int>upperdiag(2*n-1,0);
        for(int i=0;i<n;i++)
        {
            board[i]=s;
        }
        solve(0,board,ans,n,leftrow,lowdiag,upperdiag);
        return ans;
    }
};