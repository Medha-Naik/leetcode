class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size();
        int n= grid[0].size();
        vector<vector<int>>visited(m,vector<int>(n,0));
        queue<pair<int,int>>q;
        int freshCount =0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==2)
                {
                    q.push({i,j});
                    visited[i][j]=1;
                }
                else if(grid[i][j]==1)freshCount++;
            }
        }

        if(freshCount ==0) return 0;

        int mins =0;
        int row[4]={0,-1,0,+1};
        int col[4]={-1,0,+1,0};
        while(!q.empty()&& freshCount>0)
        {
            int s=q.size();
            mins++;
            while(s--)
            {
                int x=q.front().first;
                int y=q.front().second;
                q.pop();
                for(int i=0;i<4;i++)
                {
                    int r=x+row[i];
                    int c=y+col[i];

                    if(r>=0&&c>=0&&r<m&&c<n&&!visited[r][c]&&grid[r][c]==1)
                    {
                        visited[r][c]=1;
                        freshCount --;
                        q.push({r,c});
                    }
                }
            }
        }
        return freshCount==0?mins:-1;
    }
};