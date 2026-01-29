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
        else if(size[pou]>size[pov])
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


    bool isvalid( int m, int n, int r, int c)
    {
        return c<n&&c>=0&&r>=0&&r<n;
    }
    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        disjointSet ds(n*n);
        int dx[4]={0,-1,0,+1};
        int dy[4]={-1,0,+1,0};
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                {
                    for(int k=0;k<4;k++)
                    {
                        int adjr=i+dx[k];
                        int adjc=j+dy[k];
                        if(isvalid(n,n,adjr,adjc)&&grid[adjr][adjc]==1)
                        {
                            int node=i*n+j;
                            int adjnode=adjr*n+adjc;
                            ds.unionbySize(node,adjnode);
                        }
                    }
                }
            }
        }
        int maxarea=0;
        bool haszero=false;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==0)
                {   
                    haszero=true;
                    unordered_set<int>parents;
                    int curr=1;
                    for(int d=0;d<4;d++)
                    {
                        int nr=i+dx[d];
                        int nc=j+dy[d];
                        if(isvalid(n,n,nr,nc)&&grid[nr][nc]==1)
                        {
                            int adjnode=nr*n+nc;
                            int parentnode=ds.findparent(adjnode);
                            parents.insert(parentnode);
                        }
                    }
                    for(int p:parents)
                    {
                        curr+=ds.size[p];

                    }
                    maxarea=max(maxarea,curr);
                }
            }
        }
        if(!haszero)
        {
            for(int i=0;i<n;i++)
            {
                maxarea=max(maxarea,ds.size[ds.findparent(i)]);
            }
        }
        return maxarea;
    }
};