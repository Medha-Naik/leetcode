class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>pref;
        int cnt=0;
        int sum=0;
        pref[0]=1;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            int req=sum-k;
            
            if(pref.find(req)!=pref.end())cnt+=pref[req];        
            pref[sum]++;
        }
        return cnt;
    }
};