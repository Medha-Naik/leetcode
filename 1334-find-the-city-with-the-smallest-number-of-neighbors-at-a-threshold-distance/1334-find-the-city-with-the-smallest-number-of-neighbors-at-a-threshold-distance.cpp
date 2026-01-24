class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
       vector<vector<int>>adj(n,vector<int>(n,INT_MAX));
       for(auto edge:edges)
       {
        adj[edge[0]][edge[1]]=edge[2];
        adj[edge[1]][edge[0]]=edge[2];
       }
       for(int i=0;i<n;i++)
       {
        adj[i][i]=0;
       }
       for(int k=0;k<n;k++)
       {
       for(int i=0;i<n;i++)
       {
        for(int j=0;j<n;j++)
        {
            
        
                if(adj[i][k]!=INT_MAX&&adj[k][j]!=INT_MAX)
                {
                    adj[i][j]=min(adj[i][j],adj[i][k]+adj[k][j]);
                }
          }
        }
       }
        int ans=-1;
        int minreachable=n;
        for(int i=0;i<n;i++)
        {
            int cnt=0;
            for(int j=0;j<n;j++)
            {
                if(i!=j&&adj[i][j]<=distanceThreshold)cnt++;
            }
            if(cnt<=minreachable)
            {
                minreachable=cnt;
                ans=i;
            }
        }
       return ans;
    }
};