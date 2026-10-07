class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int,int>mp;
        mp[nums[0]] =0;
        for(int i = 1; i< n; i++)
        {
            int req = target - nums[i];
            if(mp.count(req))return {mp[req], i};
            mp[nums[i]]= i;
        }
        return {-1,-1};
    }
};