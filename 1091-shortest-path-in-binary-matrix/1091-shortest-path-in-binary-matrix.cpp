class Solution {
public:
    int row[8]={-1,-1,-1,0,0,+1,+1,+1};
    int col[8]={-1,0,+1,-1,+1,-1,0,+1};

    int shortestDist(vector<vector<int>>&grid,int m,int n)
    {
        queue<pair<int,pair<int,int>>>q;
        q.push({1,{0,0}});
        vector<vector<int>>visited(m,vector<int>(n,INT_MAX));

        while(!q.empty())
        {
            auto it=q.front();
            int dist=it.first;
            int r=it.second.first;
            int c=it.second.second;
            q.pop();

            if(r==m-1 && c==n-1)return dist;
            
            for(int i=0;i<8;i++)
            {
                int x=r+row[i];
                int y=c+col[i];
                if( x>=0&& x<m && y>=0 && y<n&& grid[x][y]==0&&visited[x][y]>dist+1)
                {
                    visited[x][y]=dist+1;
                    q.push({dist+1,{x,y}});
                }

            }
        }
    return -1;
    }

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();

        if(grid[0][0]==1||grid[m-1][n-1]==1)return -1;
        return shortestDist(grid,m,n);
    }
};