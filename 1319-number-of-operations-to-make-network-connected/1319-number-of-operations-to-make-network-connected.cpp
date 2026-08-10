class DisjointSet{
    

public:
vector<int>parent,size;
    DisjointSet(int n)
    {
        parent.resize(n+1);
        size.resize(n+1,1);
        for(int i =0; i<=n;i++)
        {
            parent[i] = i;
        }
    }

    int findParent(int u)
    {
        if(parent[u]== u) return u;
        return parent[u] = findParent(parent[u]);
    }
    void unionbySize(int u, int v)
    {
        int par_v = findParent(v);
        int par_u = findParent(u);
        if(par_v == par_u)return;
        if(size[par_v]> size[par_u])
        {
            size[par_v]+= size[par_u];
            parent[par_u]= par_v;
        }
        else 
        {
            size[par_u]+= size[par_v];
            parent[par_v]= par_u;
        }
    }
};

class Solution {
public:



    int makeConnected(int n, vector<vector<int>>& connections) {
        int component = 0;
        int extra =0;
        DisjointSet ds(n);
        for(auto c: connections)
        {
            int u = c[0];
            int v = c[1];
            if(ds.findParent(u) != ds.findParent(v))
            {
                ds.unionbySize(u, v);
            }
            else{
                extra++;
            }
        }

        for(int i =0; i<n ; i++)
        {
            if(ds.parent[i]== i)
            {
                component++;
            }
        }

        return (extra>= component -1)? component-1 :-1;
    }
};