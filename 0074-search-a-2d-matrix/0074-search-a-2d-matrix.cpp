class Solution {
public:

    bool binarysearch(vector<vector<int>>&matrix,int target,int low,int high)
    {   
        int m=matrix[0].size();
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            int row=mid/m;
            int col=mid%m;
            if(matrix[row][col]==target)return true;
            else if(matrix[row][col]<target)low=mid+1;
            else high=mid-1;

        }
        return false;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        int n=matrix[0].size();
        int low=0;
        int high=n*m-1; 
        bool res= binarysearch(matrix,target,low,high);
        return res;
    }
};