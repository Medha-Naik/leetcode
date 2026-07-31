class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m= matrix.size();
        int n=matrix[0].size();

        int l=0, r= n-1;
        int t=0, d=m-1;

        vector<int>res;
        while(l<=r&&t<=d)
        {
            for(int i=l;i<=r;i++)
            {
                res.push_back(matrix[t][i]);
            }
            t++;
            for(int i=t;i<=d;i++)
            {
                res.push_back(matrix[i][r]);
            }
            r--;
            if(t<=d)
            {
            for(int i=r;i>=l;i--)
            {
                res.push_back(matrix[d][i]);
            }
            
            d--;
            }
            if(r>=l)
            {
            for(int i=d;i>=t;i--)
            {
                res.push_back(matrix[i][l]);
            }
            l++;
            }
        }
        return res;
    }
};