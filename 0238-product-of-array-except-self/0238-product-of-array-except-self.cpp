class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<long long>suff(n);
        vector<long long>pref(n);
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
        long long mul;
        for(int i=0;i<n;i++)
        {
            mul=pref[i]*suff[i];
            res[i]=int(mul);
        }
        return res;
    }
};