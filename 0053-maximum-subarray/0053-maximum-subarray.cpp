class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int maxsum = INT_MIN;
        int tot = 0;
        for(int i = 0; i<n; i++)
        {
           tot += nums[i];
           maxsum = max(tot, maxsum);
           if(tot<0)
           {
            tot = 0;
           } 
        }
        return maxsum;
    }
};