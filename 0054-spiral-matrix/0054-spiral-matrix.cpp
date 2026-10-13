class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<int> res;
        int l= 0, r= n-1, u = 0, d= m-1;

        while(l<=r && u<=d)
        {
            for(int i = l; i<=r; i++)
            {
                res.push_back(matrix[u][i]);
            }
            u++;
            for(int i = u; i<=d; i++)
            {
                res.push_back(matrix[i][r]);
            }
            r--;
            if(u<=d)
            {
            for(int i = r; i>=l; i--)
            {
                res.push_back(matrix[d][i]);
            }
            }
            d--;
            if(l<=r)
            {
            for(int i =d ; i>=u; i--)
            {
                res.push_back(matrix[i][l]);
            }
            }
            l++;
     
        }
        return res;
    }
};