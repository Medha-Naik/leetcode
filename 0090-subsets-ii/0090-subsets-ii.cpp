class Solution {
public:
    void subsets(vector<int>&curr,vector<int>&nums,vector<vector<int>>&res,int i, int n)
    {
        if(i==n)
        {
            res.push_back(curr);
            return;
        }
        curr.push_back(nums[i]);
        subsets(curr,nums,res,i+1,n);
        curr.pop_back();
        while(i+1<n&&nums[i]==nums[i+1])i++;
        subsets(curr,nums,res,i+1,n);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int>curr;
        vector<vector<int>>res;
        int n=nums.size();
        subsets(curr,nums,res,0,n);
        return res;
    }
};