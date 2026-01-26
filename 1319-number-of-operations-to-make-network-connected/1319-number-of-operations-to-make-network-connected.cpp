class disjointSet{
    public:
        vector<int>parent,size;
        disjointSet(int n)
        {
            parent.resize(n);
            size.resize(n,1);
            for(int i=0;i<n;i++)
            {
                parent[i]=i;
            }
        }
        int findparent(int u)
        {
            if(parent[u]==u)return u;
            return parent[u]=findparent(parent[u]);
        }
        void unionbySize(int u,int v)
        {
            int pou=findparent(u);
            int pov=findparent(v);
            if(pou==pov)return;
            else if(size[pou]<size[pov])
            {
                parent[pou]=pov;
                size[pov]+=size[pou];
            }
            else{
                parent[pov]=pou;
                size[pou]+=size[pov];
            }
        }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        disjointSet ds(n);
        int cntext=0;
        for(auto edge:connections)
        {
            int u=edge[0];
            int v=edge[1];
            if(ds.findparent(u)==ds.findparent(v))cntext++;
            else{
                ds.unionbySize(u,v);
            }
        }
        int comps=0;
        for(int i=0;i<n;i++)
        {
            if(ds.parent[i]==i)comps++;
        }
        int ans=comps-1;
        if(ans<=cntext)return ans;
        return -1;
    }
};