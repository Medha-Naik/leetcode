class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<long long> dp(amount + 1, 0);

        dp[0] = 1;

        for (int coin : coins) {
            for (int T = coin; T <= amount; T++) {

                if (dp[T] > INT_MAX - dp[T - coin])
                    dp[T] = INT_MAX;
                else
                    dp[T] += dp[T - coin];
            }
        }

        return dp[amount];
    }
};