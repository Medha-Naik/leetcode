class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int cnt=0;
        mp[0]=1;
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
            int rem=((sum%k)+k)%k;
            if(mp.find(rem)!=mp.end())
            {
                cnt+=mp[rem];
            }
            mp[rem]++;
        }
        return cnt;
    }
};