class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m=heights.size();
        int n=heights[0].size();
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        vector<vector<int>>effort(m,vector<int>(n,INT_MAX));
        int dx[4]={-1,0,0,+1};
        int dy[4]={0,-1,+1,0};
        pq.push({0,{0,0}});
        effort[0][0]=0;
        while(!pq.empty())
        {
            int diff=pq.top().first;
            int row=pq.top().second.first;
            int col=pq.top().second.second;
            pq.pop();
            if(row==m-1&&col==n-1)return diff;
            for(int i=0;i<4;i++)
            {
                int nrow=row+dx[i];
                int ncol=col+dy[i];
                if(nrow>=0&&nrow<m&&ncol>=0&&ncol<n)
                {   
                    int neweffort=max(diff,abs(heights[row][col]-heights[nrow][ncol]));
                    if(neweffort<effort[nrow][ncol])
                    {
                        effort[nrow][ncol]=neweffort;
                        pq.push({neweffort,{nrow,ncol}});
                    }
                    
                }
            }
        }
        return -1;
    }
};