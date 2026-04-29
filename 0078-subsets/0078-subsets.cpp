class Solution {
public:
    void subsets(vector<vector<int>>&res,vector<int>&nums,vector<int>&curr,int i,int n)
    {
        if(i==n)
        {
            res.push_back(curr);
            return;
        }
        curr.push_back(nums[i]);
        subsets(res,nums,curr,i+1,n);
        curr.pop_back();
        subsets(res,nums,curr,i+1,n);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>curr;
        vector<vector<int>>res;
        int n=nums.size();
        subsets(res,nums,curr,0,n);
        return res;
    }
};