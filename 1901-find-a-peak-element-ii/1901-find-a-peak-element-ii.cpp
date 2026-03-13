class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        int low=0, high=m-1;

        while(low<=high)
        {
            int mid=low+(high-low)/2;
            int maxcol=max_element(mat[mid].begin(),mat[mid].end())-mat[mid].begin();
            bool up=(mid-1<0||mat[mid][maxcol]>mat[mid-1][maxcol]);
            bool down=(mid+1>=m||mat[mid][maxcol]>mat[mid+1][maxcol]);
            if(up&&down)return {mid,maxcol};
            else if(mid-1>=0&&mat[mid-1][maxcol]>mat[mid][maxcol])
            {
                high=mid-1;
            }
            else if(mid+1<m)low=mid+1;
        }
        return {-1,-1};
    }
};