class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int prev = nums[0];
        int prev2 = 0;

        for(int i=1;i<n;i++)
        {
            int take = nums[i]+ prev2;
            int nottake = 0 + prev;

            prev2 = prev; 
            prev = max(take,nottake);
           
        }
        return prev;
    }
};