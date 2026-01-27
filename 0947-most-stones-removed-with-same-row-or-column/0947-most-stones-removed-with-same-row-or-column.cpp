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
        if(size[pou]>size[pov])
        {
            parent[pov]=pou;
            size[pou]+=size[pov];
        }
        else{
            parent[pou]=pov;
            size[pov]+=size[pou];
        }
    }


};



class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        int maxrow=0;
        int maxcol=0;
        for(auto it:stones)
        {
            maxrow=max(maxrow,it[0]);
            maxcol=max(maxcol,it[1]);
        }
        disjointSet ds(maxrow+maxcol+2);
        unordered_map<int,int>stonenodes;
        for(auto it:stones)
        {
            int rownode=it[0];
            int colnode=it[1]+maxrow+1;
            ds.unionbySize(rownode,colnode);
            stonenodes[rownode]=1;
            stonenodes[colnode]=1;
        }
        int cnt=0;
        for(auto it:stonenodes)
        {
            if(ds.findparent(it.first)==it.first)cnt++;
        }
        return n-cnt;
    }
};