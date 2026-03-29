class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int currmax=nums[0];
        int currmin=nums[0];
        int maxi=nums[0];
        for(int i=1;i<nums.size();i++)
        {   
            int temp=currmax;
            currmax=max({nums[i],nums[i]*currmax,currmin*nums[i]});
            currmin=min({nums[i],nums[i]*currmin,nums[i]*temp});
            maxi=max(maxi,currmax);
        }
        return maxi;
    }
};