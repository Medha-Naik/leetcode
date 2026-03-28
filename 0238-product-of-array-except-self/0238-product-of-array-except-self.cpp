class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int>suff(n);
        vector<int>pref(n);
        vector<int>res(n);
        pref[0]=1;
        for(int i=1;i<n;i++)
        {
            pref[i]=pref[i-1]*nums[i-1];
        }
        suff[n-1]=1;
        for(int i=n-2;i>=0;i--)
        {
            suff[i]=suff[i+1]*nums[i+1];
        }
        long long mul=1;
        for(int i=0;i<n;i++)
        {
            mul=suff[i]*pref[i];
            res[i]=mul;
        }
return res;
    }
};