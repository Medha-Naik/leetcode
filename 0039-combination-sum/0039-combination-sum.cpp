class Solution {
public:
    void findcombs(vector<int>&candidates,int target,int ind,int n,vector<int>&curr,vector<vector<int>>&res)
    {
        if(target==0)
        {
            res.push_back(curr);
            return;
        }
        for(int i=ind;i<n;i++)
        {   
            if(candidates[i]>target)return;
            curr.push_back(candidates[i]);
            findcombs(candidates,target-candidates[i],i,n,curr,res);
            curr.pop_back();
        }

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n=candidates.size();
        vector<int>curr;
        vector<vector<int>>res;
        sort(candidates.begin(),candidates.end());
        findcombs(candidates,target,0,n,curr,res);
        return res;
    }
};