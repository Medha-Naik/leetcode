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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string,int>emails;
        int n = accounts.size();
        DisjointSet ds(n);
        for( int i = 0; i<n; i++)
        {
            for( int j =1; j<accounts[i].size() ; j++)
            {
                if(emails.find(accounts[i][j])== emails.end())
                {
                    emails[accounts[i][j]] = i;
                }
                else{
                    ds.unionbySize(emails[accounts[i][j]],i);
                }
            }
        }
        vector<vector<string>>mergedMail(n);
        for (auto it: emails)
        {
            string mail = it.first;
            int node = ds.findParent(it.second);
            mergedMail[node].push_back(mail);
        }

        vector<vector<string>>ans;

        for(int i =0; i<n; i++)
        {
            if(mergedMail[i].size() == 0) continue;

            sort(mergedMail[i].begin(), mergedMail[i].end());
            vector<string>temp;
            temp.push_back(accounts[i][0]);
            for(auto it: mergedMail[i])
            {
                temp.push_back(it);
            }
            ans.push_back(temp);
        }
    return ans;
    }
};