class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int total = accumulate(nums.begin(), nums.end(), 0);
        if (abs(target) > total || (target + total) % 2 != 0) return 0;
        int S = (target + total) / 2;

        vector<int> dp(S + 1, 0);
        dp[0] = 1;
        for (int n : nums) {
            for (int j = S; j >= n; j--) {
                dp[j] += dp[j - n];
            }
        }
        return dp[S];
    }
};