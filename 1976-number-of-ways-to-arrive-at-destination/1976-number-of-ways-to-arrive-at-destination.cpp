class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {

        vector<vector<pair<int,int>>>grid(n);
        int Mod = 1e9+7;
        for(auto road:roads)
        {
            grid[road[0]].push_back({road[1],road[2]});
            grid[road[1]].push_back({road[0],road[2]});
        }
        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>>pq;
        pq.push({0,0});
        vector<long long>dist(n,1e18);
        dist[0]=0;

        vector<int>paths(n,0);
        paths[0] =1 ;
        while(!pq.empty())
        {
            long long d = pq.top().first;
            int node = pq.top().second;

            pq.pop();
            if(d > dist[node])continue;

            for(auto adj:grid[node])
            {
                int distance = adj.second;
                int neighbor = adj.first;
                if(distance+d< dist[neighbor])
                {
                    dist[neighbor] = distance+d;
                    paths[neighbor]= paths[node];
                    pq.push({dist[neighbor], neighbor});
                }
                else if ( distance+d == dist[neighbor])
                {
                    paths[neighbor]=(paths[neighbor]+paths[node])% Mod;
                }
            }
        }
        return paths[n-1];
    }
};