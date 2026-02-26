class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int mini=INT_MAX;
        int cost=0;
        for(int i=0;i<n;i++)
        {
           mini=min(mini,prices[i]);
            cost=max(cost,prices[i]-mini);
        }
        return cost;
    }
};