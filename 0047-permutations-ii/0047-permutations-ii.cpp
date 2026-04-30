class Solution {
public:
    void permute(vector<int>&nums,vector<vector<int>>&res,int ind,int n)
    {
        if(ind==n)
        {
            res.push_back(nums);
            return;
        }
        set<int>seen;
        for(int i=ind;i<n;i++)
        {
            if(seen.count(nums[i]))continue;
            seen.insert(nums[i]);
            swap(nums[i],nums[ind]);
            permute(nums,res,ind+1,n);
            swap(nums[i],nums[ind]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<vector<int>>res;
        permute(nums,res,0,n);
        return res;
    }
};