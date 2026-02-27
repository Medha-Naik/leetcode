class Solution {
public:
    int rob(vector<int>& nums) {
        int prev1=0;
        int prev2=0;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            int take=nums[i];
            if(i>1)
            {
                take+=prev2;
            }
            int nottake=prev1;
            int curr=max(take,nottake);
            prev2=prev1;
            prev1=curr;
        }
        return prev1;
    }
};