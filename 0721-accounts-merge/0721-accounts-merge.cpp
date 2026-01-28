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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n=accounts.size();
        unordered_map<string,int>mapmailNode;
        disjointSet ds(n);
        for(int i=0;i<n;i++)
        {
            for(int j=1;j<accounts[i].size();j++)
            {
                string mail=accounts[i][j];
                if(mapmailNode.find(mail)==mapmailNode.end())
                {
                    mapmailNode[mail]=i;
                }
                else{
                    ds.unionbySize(i,mapmailNode[mail]);
                }
            }
        }
        vector<vector<string>>mergemail(n);
        for(auto it:mapmailNode)
        {
            string mail=it.first;
            int node=ds.findparent(it.second);
            mergemail[node].push_back(mail);
        }
        vector<vector<string>>ans;
        for(int i=0;i<n;i++)
        {
            if(mergemail[i].size()==0)continue;
            sort(mergemail[i].begin(),mergemail[i].end());
            vector<string>temp;
            temp.push_back(accounts[i][0]);
            for(auto it:mergemail[i])
            {
                temp.push_back(it);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};