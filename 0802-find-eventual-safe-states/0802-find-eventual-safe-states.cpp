class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int m=graph.size();
        vector<vector<int>>reversed(m);
        vector<int>indegree(m,0);
        queue<int>q;

        for(int i=0;i<m;i++)
        {
            for(auto neighbor: graph[i])
            {
                reversed[neighbor].push_back(i);
                indegree[i]++;
            }
        }
        

        for(int i=0;i<m;i++)
        {
            if(indegree[i]==0)q.push(i);
        }

        vector<int>res;
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            res.push_back(node);
            for(auto neighbor:reversed[node])
            {
                indegree[neighbor]--;
                if(indegree[neighbor]==0)q.push(neighbor);
            }
        }
        sort(res.begin(),res.end());
        return res;
    }
};