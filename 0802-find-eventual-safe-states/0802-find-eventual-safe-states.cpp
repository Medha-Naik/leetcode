class Solution {
public:
    bool dfs(int node,vector<vector<int>>&graph,vector<int>&vis,vector<int>&color)
    {
        vis[node]=1;
        color[node]=1;
        for(auto it:graph[node])
        {
            if(color[it]==1)return true;
            if(color[it]==0&&dfs(it,graph,vis,color))return true;
        }
        color[node]=2;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>vis(n,0);
        vector<int>color(n,0);
        for(int i=0;i<n;i++)
        {
            if(!vis[i])dfs(i,graph,vis,color);
        }
        vector<int>sol;
        for(int i=0;i<n;i++)
        {
            if(color[i]==2)sol.push_back(i);
        }
        return sol;
    }
};