class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>graph(numCourses);
        queue<int>q;
        vector<int>indegree(numCourses,0);

       for(auto edge: prerequisites)
       {
        graph[edge[1]].push_back(edge[0]);
        indegree[edge[0]]++;
       }
      
       for(int i=0;i<numCourses;i++)
       {
        if(indegree[i]==0)q.push(i);
       }

       vector<int>res;
       while(!q.empty())
       {
        int node=q.front();
        q.pop();
        res.push_back(node);
        for(auto neighbor: graph[node])
        {
            indegree[neighbor]--;
            if(indegree[neighbor]==0)q.push(neighbor);
        }
       }
       return (res.size()==numCourses)?res : vector<int>{};
    }
};