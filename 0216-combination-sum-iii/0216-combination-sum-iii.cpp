class Solution {
public:
    void backtrack(vector<int>&curr,vector<vector<int>>&res,int k,int n,int total,int ind)
    {
        if(curr.size()==k && total==n)
        {
            res.push_back(curr);
            return;
        }
        if(total>n||curr.size()>k)return;
        for(int i=ind;i<=9;i++)
        {
            curr.push_back(i);
            backtrack(curr,res,k,n,total+i,i+1);
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>curr;
        vector<vector<int>>res;
        int total=0;
        backtrack(curr,res,k,n,total,1);
        return res;
    }
};