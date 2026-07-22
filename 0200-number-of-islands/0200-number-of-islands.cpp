class Solution {
public:
    int row[4]={0,-1,0,+1};
    int col[4]={-1,0,+1,0};
    void dfs(vector<vector<char>>&grid, vector<vector<int>>&visited, int r, int c, int m, int n)
    {
        visited[r][c]=1;
        for(int i=0;i<4;i++)
        {
            int nr=r+row[i];
            int nc=c+col[i];
            if(nr>=0&& nc>=0&& nr<m && nc<n && grid[nr][nc]=='1'&& visited[nr][nc]==0)
            {
                dfs(grid, visited,nr,nc,m,n);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        int n= grid[0].size();
        vector<vector<int>>visited(m,vector<int>(n,0));
        int cnt=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0; j<n; j++)
            {
                if(!visited[i][j]&&grid[i][j]=='1')
                {
                    dfs(grid,visited,i,j,m,n);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};