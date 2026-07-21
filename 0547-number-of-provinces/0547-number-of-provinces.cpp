class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int m = isConnected.size();
        vector<bool> visited(m, false);
        queue<int> q;
        int cnt =0;

        for(int i=0; i<m; i++)
        {
            if(!visited[i])
            {
                cnt++;
                q.push(i);
                visited[i] = true;

                while(!q.empty())
                {
                    int node=q.front();
                    q.pop();

                    for(int j=0;j<m;j++)
                    {
                        if(isConnected[node][j]==1&&!visited[j])
                        {
                            visited[j]= true;
                            q.push(j);
                        }
                    }
                }
            }
        }
        return cnt;
    }
};