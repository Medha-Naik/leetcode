class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int m=graph.size();
        queue<int>q;
        vector<int>visited(m,0);
       

        for(int i=0;i<m;i++)
        {
            if(!visited[i])
            visited[i]=1;
            q.push(i);
            while(!q.empty()){
            int node=q.front();
            q.pop();
            int color=visited[node];
            for(auto neighbor: graph[node])
            {
                if(!visited[neighbor])
                {
                    visited[neighbor]=(color==1)?2:1;
                    q.push(neighbor);
                }
                else if(color==visited[neighbor])return false;
            }
        }
        }
        
        return true;
    }
};