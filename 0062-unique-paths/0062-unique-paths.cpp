class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int>prev(n,1);
        for(int i =1; i<m; i++)
        {
            vector<int>curr(n,1);
            for(int j =0; j<n; j++)
            {
                curr[j] =(j>0)?curr[j-1]+prev[j]: prev[j]; 
            }
            prev = curr;
        }
        return prev[n-1];
    }
};