class Solution {
public:
    int row[4]={-1,0,1,0};
    int col[4]={0,-1,0,1};
    bool backtrack(vector<vector<char>>&board, string word,int i, int j,int ind)
    {   
        if(ind==word.size())
        {
            return true;
        }
        if(i==board.size()||j==board[0].size()||i<0||j<0)return false;
       
            if(board[i][j]!=word[ind])return false;
            char temp=board[i][j];
            board[i][j]='#';
            for(int k=0;k<4;k++)
            {
                if(backtrack(board,word,i+row[k],j+col[k],ind+1))return true;
            }
            board[i][j]=temp;
        
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {

        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                if(backtrack(board,word,i,j,0))return true;
            }
        }
        return false;

    }
};