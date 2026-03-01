class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        long long sum=0;
        
        unordered_map<long long,int>mp;
        int n=nums.size();
        mp[0]=-1;
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
            long long rem=((sum%k)+k)%k;
            if(mp.find(rem)!=mp.end()){
                if(i-mp[rem]>=2)return true;
            }
            else{
                mp[rem]=i;
            }
            
        }
        return false;
    }
};