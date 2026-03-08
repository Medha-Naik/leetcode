class Solution {
public:
    int findMin(vector<int>& nums) {
        int low=0,high=nums.size()-1;
        int lowest=INT_MAX;
        while(low<=high)
        {
            int mid=(low+high)/2;
            lowest=min(lowest,nums[mid]);
            if(nums[low]<=nums[mid])
            {
                lowest=min(lowest,nums[low]);
                low=mid+1;
            }
            else{
                lowest=min(lowest,nums[mid+1]);
                high=mid-1;
            }
        }
        return lowest;
    }
};