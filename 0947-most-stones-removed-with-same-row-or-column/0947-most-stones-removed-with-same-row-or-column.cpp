class DisjointSet{
    vector<int>size, parent;

    public:

    DisjointSet(int n)
    {
        size.resize(n+1, 1);
        parent.resize(n+1);

        for(int i =0; i<=n; i++)
        {
            parent[i] =i;
        }
    }

    int findParent(int u)
    {
        if(parent[u] == u) return u;
        return parent[u] = findParent(parent[u]);
    }

    void UnionbySize(int u, int v)
    {
        int par_u = findParent(u);
        int par_v = findParent(v);

        if(par_u == par_v)return;
        if(size[par_u]> size[par_v])
        {
            size[par_u]+= size[par_v];
            parent[par_v] = par_u;
        }
        else 
        {
            size[par_v]+= size[par_u];
            parent[par_u] = par_v;
        }
    }
};


class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        int maxrow=0;
        int maxcol =0;
        for(auto it: stones)
        {
            maxrow = max(maxrow,it[0]);
            maxcol = max(maxcol, it[1]);
        }

        DisjointSet ds(maxrow+maxcol+1);

        unordered_map<int,int>nodeStones;
        for(auto it: stones)
        {
            int row = it[0];
            int col = it[1];

            ds.UnionbySize(row, maxrow+col+1);
            nodeStones[row]=1;
            nodeStones[maxrow+col+1]=1;
        }

        int cnt =0;
        for(auto it: nodeStones)
        {
            if(ds.findParent(it.first) == it.first)
            cnt++;
        }
    return n-cnt;
}
};