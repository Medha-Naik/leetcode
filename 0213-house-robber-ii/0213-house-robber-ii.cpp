class Solution {
public:
     int robLinear(vector<int>& nums, int start, int end) {
        if (start > end) return 0;
        int prev = 0;
        int prev2 = 0;

        for (int i = start; i <= end; i++) {
            int take = nums[i] + prev2;
            int nottake = prev;

            int cur = max(take, nottake);
            prev2 = prev;
            prev = cur;
        }
        return prev;
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];

        int case1 = robLinear(nums, 0, n - 2);
        int case2 = robLinear(nums, 1, n - 1);

        return max(case1, case2);
    }
};