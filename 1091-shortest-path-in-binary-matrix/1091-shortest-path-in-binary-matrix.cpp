class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int m=grid.size();
        if(grid[0][0]||grid[m-1][m-1])return -1;
        queue<pair<int,pair<int,int>>>q;
        q.push({1,{0,0}});
        
        vector<vector<int>>dist(m,vector<int>(m,INT_MAX));
        dist[0][0]=1;
        int dx[8]={-1,-1,-1,0,0,+1,+1,+1};
        int dy[8]={-1,0,+1,-1,+1,-1,0,+1};
        while(!q.empty())
        {
            int dis=q.front().first;
            int row=q.front().second.first;
            int col=q.front().second.second;
            q.pop();
            if(row==m-1&&col==m-1)return dis;
            for(int i=0;i<8;i++)
            {
                int nrow=row+dx[i];
                int ncol=col+dy[i];
                if(nrow<m&&nrow>=0&&ncol<m&&ncol>=0&&grid[nrow][ncol]==0&&dist[nrow][ncol]>dis+1)
                {
                    dist[nrow][ncol]=dis+1;
                    q.push({dis+1,{nrow,ncol}});
                }
            }
        }
        return -1;
    }
};