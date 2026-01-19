class Solution {
public:
    bool dfs(int node,vector<vector<int>>&graph,vector<int>&vis,vector<int>&pathvis,vector<int>&check)
    {
        vis[node]=1;
        pathvis[node]=1;
        check[node]=0;
        for(auto it:graph[node])
        {
            if(!vis[it])
            {
                if(dfs(it,graph,vis,pathvis,check)==true)
                {
                    check[node]=0;
                    return true;
                }
            }
            else if(pathvis[it])
            {
                check[node]=0;
                return true;
            }
        }
            check[node]=1;
            pathvis[node]=0;
            return false;
        
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
       int v=graph.size();
       vector<int>vis(v,0);
       vector<int>pathvis(v,0);
       vector<int>check(v,0);
       vector<int>safenodes;
       for(int i=0;i<v;i++)
       {
        if(!vis[i])dfs(i,graph,vis,pathvis,check);
       }
       for(int i=0;i<v;i++)
       {
        if(check[i]==1)safenodes.push_back(i);
       }
       return safenodes;
    }
};