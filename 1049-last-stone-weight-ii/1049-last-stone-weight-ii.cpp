class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int totsum = accumulate(stones.begin(), stones.end(), 0);
        vector<bool>dp(totsum+1, false);

        dp[0] = true;
        
        for(int stone : stones)
        {
            for(int s = totsum; s>= stone; s--)
            {
                dp[s] = dp[s]||dp[s-stone];
            }
        }
        int mini = INT_MAX;
        for(int i =0; i<=totsum/2; i++)
        {
            if(dp[i])
            {
            int diff = totsum- 2*i;
            mini = min(diff, mini);
            }
        }
        return mini;
    }
};