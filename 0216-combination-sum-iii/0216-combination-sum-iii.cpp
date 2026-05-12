class Solution {
public:
    void backtrack(int k,int n, vector<vector<int>>&res,vector<int>&curr,int start)
    {
        if(curr.size()==k&&n==0)
        {
            res.push_back(curr);
            return;
        }
        if(curr.size()>k||n<0)return;
        for(int i=start;i<=9;i++)
        {
            curr.push_back(i);
            backtrack(k,n-i,res,curr,i+1);
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>res;
        vector<int>curr;
        backtrack(k,n,res,curr,1);
        return res;
    }
};