class Solution {
public:
    void findcombos(vector<int>&candidates,int target,int ind,vector<int>&curr,vector<vector<int>>&res,int n)
    {
        if(target==0)
        {
            res.push_back(curr);
            return;
        }
        if(ind==n)return;
        for(int i=ind;i<n;i++)
        {   
            if(candidates[i]>target)return;
            if(i>ind&&candidates[i]==candidates[i-1])continue;
            curr.push_back(candidates[i]);
            findcombos(candidates,target-candidates[i],i+1,curr,res,n);
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int n=candidates.size();
        vector<int>curr;
        vector<vector<int>>res;
        sort(candidates.begin(),candidates.end());
        findcombos(candidates,target,0,curr,res,n);
        return res;
    }
};