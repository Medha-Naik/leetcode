class Solution {
public:
    void findcombs(vector<int>&candidates,int target,int ind,int n,vector<int>&curr,vector<vector<int>>&res)
    {
        if(target==0)
        {
            res.push_back(curr);
            return;
        }
        if(target<0||ind==n)return;
        for(int i=ind;i<n;i++)
        {
            curr.push_back(candidates[i]);
            findcombs(candidates,target-candidates[i],i,n,curr,res);
            curr.pop_back();
        }

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n=candidates.size();
        vector<int>curr;
        vector<vector<int>>res;
        findcombs(candidates,target,0,n,curr,res);
        return res;
    }
};