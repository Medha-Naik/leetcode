class Solution {
public:
    void dfs(int row,int col,vector<vector<int>>&vis,vector<vector<int>>&grid,int m,int n)
    {   
        
        int dx[4]={0,-1,0,+1};
        int dy[4]={-1,0,+1,0};
        vis[row][col]=1;
        for(int i=0;i<4;i++)
        {
            int nrow=row+dx[i];
            int ncol=col+dy[i];
            if(nrow>=0&&nrow<m&&ncol>=0&&ncol<n&&!vis[nrow][ncol])
            {
                dfs(nrow,ncol,vis,grid,m,n);
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==0)vis[i][j]=1;
            }
        }
        for(int i=0;i<n;i++)
        {
            if(grid[0][i]==1)
            {
                dfs(0,i,vis,grid,m,n);
            }
            if(grid[m-1][i]==1)
            {
                dfs(m-1,i,vis,grid,m,n);
            }
        }
        for(int i=0;i<m;i++)
        {
            if(grid[i][0]==1)
            {
                dfs(i,0,vis,grid,m,n);
            }
            if(grid[i][n-1]==1)
            {
                dfs(i,n-1,vis,grid,m,n);
            }
        }
        int cnt=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(vis[i][j]==0)cnt++;
            }
        }
        return cnt;
    }
};