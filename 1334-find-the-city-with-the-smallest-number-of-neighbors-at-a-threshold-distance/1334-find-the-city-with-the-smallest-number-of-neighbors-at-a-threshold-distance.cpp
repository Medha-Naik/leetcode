class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        const int INF = 1e9;
        vector<vector<int>> dis(n, vector<int>(n, INF));
        for (int i = 0; i < n; i++) dis[i][i] = 0;

        for (auto& edge : edges) {
            int u = edge[0], v = edge[1], wt = edge[2];
            dis[u][v] = wt;
            dis[v][u] = wt;
        }

        for (int k = 0; k < n; k++)
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    if (dis[i][k] < INF && dis[k][j] < INF)
                        dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);

        int cntCity = n, city = -1;
        for (int i = 0; i < n; i++) {
            int cnt = 0;
            for (int j = 0; j < n; j++) {
                if (i != j && dis[i][j] <= distanceThreshold) cnt++;
            }
            if (cnt <= cntCity) {   
                cntCity = cnt;
                city = i;
            }
        }
        return city;
    }
};