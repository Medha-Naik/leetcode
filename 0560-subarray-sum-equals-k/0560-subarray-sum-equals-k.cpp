class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int>freq;
        freq[0] = 1;
        int cnt = 0, total = 0;
        for(int i = 0; i<n; i++)
        {
            total += nums[i];
            int req = total- k;
            if(freq.count(req))
            {
                cnt += freq[req];
            }
            freq[total]++;
        }
        return cnt;
    }
};