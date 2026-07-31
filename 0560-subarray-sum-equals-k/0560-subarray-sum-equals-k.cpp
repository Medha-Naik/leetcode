class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int prefsum=0;
        mp[0]=1;
        int cnt=0;
        for(int n:nums)
        {
            prefsum+=n;
            int target=prefsum-k;
            if(mp.count(target))cnt+=mp[target];
            mp[prefsum]++;
        }
        return cnt;
    }
};