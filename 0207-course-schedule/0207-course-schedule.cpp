class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>graph(numCourses);
        for (auto edge: prerequisites)
        {
            graph[edge[1]].push_back(edge[0]);
        }


        vector<int>indegree(numCourses,0);
        queue<int>q;

        for(int i=0;i<numCourses;i++)
        {
            for(auto neighbor:graph[i])indegree[neighbor]++;
        }
        for(int i=0;i<numCourses;i++)
        {
            if(indegree[i]==0)q.push(i);
        }
        int cnt=0;
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            cnt++;
            for(auto neighbor:graph[node])
            {
                indegree[neighbor]--;
                if(indegree[neighbor]==0)
                {
                    q.push(neighbor);
                }
            }
        }
        return cnt==numCourses;
    }
};