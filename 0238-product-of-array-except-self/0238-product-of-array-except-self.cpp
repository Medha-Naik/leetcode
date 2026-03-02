class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int>res(n,1);
        int pref=1;
        for(int i=1;i<n;i++)
        {
            res[i]=pref*nums[i-1];
            pref*=nums[i-1];
        }
        int suff=1;
        for(int i=n-1;i>=0;i--)
        {
            res[i]*=suff;
            suff*=nums[i];
        }
        return res;
    }
};