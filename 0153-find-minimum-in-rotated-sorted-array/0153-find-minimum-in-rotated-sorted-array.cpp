class Solution {
public:
    int findMin(vector<int>& nums) {
        int low=0,high=nums.size()-1;
        int lowest=INT_MAX;
        while(low<=high)
        {
            int mid=(low+high)/2;
            lowest=min(nums[mid],lowest);
            if(nums[low]<=nums[mid])
            {
                lowest=min(nums[low],lowest);
                low=mid+1;
            }
            else{
                lowest=min(nums[low],lowest);
                high=mid-1;
            }
        }
           return lowest;
    }
 
};