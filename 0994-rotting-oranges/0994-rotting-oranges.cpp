class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));
        int steps=0;
        queue<pair<pair<int,int>,int>>q;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==2)
                {
                    q.push({{i,j},0});
                    vis[i][j]=1;
                }
                else if(grid[i][j]==0)vis[i][j]=1;
            }
        }
        int dx[4]={0,-1,0,+1};
        int dy[4]={-1,0,+1,0};
    
        while(!q.empty())
        {
            int row=q.front().first.first;
            int col=q.front().first.second;
            steps=q.front().second;
            q.pop();
             for(int i=0;i<4;i++){
                int nrow=row+dx[i];
                int ncol=col+dy[i];
                if(nrow>=0&&nrow<m&&ncol>=0&&ncol<n&&!vis[nrow][ncol]&&grid[nrow][ncol]==1)
                {
                    vis[nrow][ncol]=1;
                    q.push({{nrow,ncol},steps+1});
                }
                }
            

        }
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
                if(!vis[i][j])return -1;
        }
        return steps;
    }
};