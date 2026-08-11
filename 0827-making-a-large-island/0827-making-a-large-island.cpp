class DisjointSet{
    public :
    vector<int> parent, size;

    DisjointSet(int n)
    {
        size.resize(n+1,1);
        parent.resize(n+1);

        for(int i = 0; i<=n ; i++)
        {
            parent[i] = i;
        }
    }

    int findParent(int u)
    {
        if(parent[u] == u)return u;
        return parent[u]= findParent(parent[u]);
    }

    void unionbySize(int u, int v)
    {
        int par_u = findParent(u);
        int par_v = findParent(v);
        if(par_u == par_v) return;

        if(size[par_u]> size[par_v])
        {
            parent[par_v]= par_u;
            size[par_u]+=size[par_v];
        }
        else{
            parent[par_u] = par_v;
            size[par_v]+= size[par_u];
        }
    }
};



class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();

        int x[4] ={0, -1, 0, +1};
        int y[4] = {-1, 0, +1, 0};

        DisjointSet ds(n*n);

        for (int r = 0; r < n; r++) {
            for (int c = 0; c < n; c++) {
                if (grid[r][c] == 0) continue;

                for (int i = 0; i < 4; i++) {
                    int nr = r + x[i];
                    int nc = c + y[i];

                    if (nr >= 0 && nr < n && nc >= 0 && nc < n && grid[nr][nc] == 1) {
                        int node = r * n + c;
                        int adjNode = nr * n + nc;
                        ds.unionbySize(node, adjNode);
                    }
                }
            }
        }

    if(ds.size[ds.findParent(0)]== n*n)return n*n;
    int maxisland =0;

        for( int i =0; i<n ; i++)
        {
            for(int j =0; j<n; j++)
            {
                if(grid[i][j] == 1)continue;

                unordered_set<int>components;
                for(int k=0; k<4; k++)
                {
                    int nr = i+x[k];
                    int nc = j+y[k];

                    
                    if(nr>=0 && nc>=0 && nr<n && nc<n && grid[nr][nc] ==1 )
                    {
                        components.insert(ds.findParent(nr*n+nc));
                    }
                }
                int total =1;

                for(auto it: components)
                {
                    total+= ds.size[it];
                }
                maxisland = max(maxisland,total);
            }
        }
        return maxisland == 0 ? 1: maxisland;
    }
};