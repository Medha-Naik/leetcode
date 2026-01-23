class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>>adj(n);
        vector<long long>dist(n,1e18);
        vector<long long>ways(n,0);
        const int MOD=1e9+7;
        for(auto it:roads)
        {
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>>pq;
        pq.push({0,0});
        dist[0]=0;
        ways[0]=1;
        while(!pq.empty())
        {
            long long dis=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            if(dis>dist[node])continue;
            for(auto it:adj[node])
            {
                int neighbor=it.first;
                long long distance=it.second;
                if(dist[neighbor]>dis+distance)
                {
                    dist[neighbor]=dis+distance;
                    ways[neighbor]=ways[node];
                    pq.push({dist[neighbor],neighbor});
                }
                else if(dis+distance==dist[neighbor])
                {
                    ways[neighbor]=(ways[neighbor]+ways[node])%MOD;
                }
            }
        }
        return ways[n-1];
    }
};