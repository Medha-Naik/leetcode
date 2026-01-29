class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        int n=grid.size();
        pq.push({grid[0][0],{0,0}});
        vector<vector<int>>vis(n,vector<int>(n,0));
        vis[0][0]=1;
        int dx[4]={0,-1,0,+1};
        int dy[4]={-1,0,+1,0};
        int maxheight=INT_MIN;
        while(!pq.empty())
        {
            auto it=pq.top();
            pq.pop();
            int height=it.first;
            int row=it.second.first;
            int col=it.second.second;
            maxheight=max(maxheight,height);
            if(row==n-1&&col==n-1)return maxheight;
            for(int i=0;i<4;i++)
            {
                int nr=row+dx[i];
                int nc=col+dy[i];
                if(nr>=0&&nr<n&&nc>=0&&nc<n&&!vis[nr][nc])
                {
                    pq.push({grid[nr][nc],{nr,nc}});
                    vis[nr][nc]=1;
                }
            }
        }
        return maxheight;
    }
};