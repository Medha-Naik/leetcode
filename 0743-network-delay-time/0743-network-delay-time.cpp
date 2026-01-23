class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>adj(n+1);
        for(auto it:times)
        {
            adj[it[0]].push_back({it[1],it[2]});
        }
        vector<int>dist(n+1,INT_MAX);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        dist[k]=0;
        pq.push({0,k});
        while(!pq.empty())
        {
            int time=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            if(time>dist[node])continue;
            for(auto it:adj[node])
            {
                int neighbor=it.first;
                int edw=it.second;
                if(dist[neighbor]>time+edw)
                {
                    dist[neighbor]=time+edw;
                    pq.push({dist[neighbor],neighbor});
                }
            }
        }
        int maxtime=0;
        for(int i=1;i<=n;i++)
        {
            if(dist[i]==INT_MAX)return -1;
            maxtime=max(maxtime,dist[i]);
        }
        return maxtime;
    }
};