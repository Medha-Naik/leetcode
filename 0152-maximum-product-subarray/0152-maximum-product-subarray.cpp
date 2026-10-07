class Solution {
public:
    int maxProduct(vector<int>& nums) {

        int n = nums.size();
        int cur_max = nums[0];
        int cur_min = nums[0];
        int maxi = nums[0];
        
        for(int i = 1; i<n; i++)
        {
            int a = cur_max*nums[i];
            int b = cur_min*nums[i];

            cur_max = max(nums[i],max( a,b));
            cur_min = min(nums[i], min(a, b));
            maxi = max(cur_max,maxi);
        }
        return maxi;
    }
};