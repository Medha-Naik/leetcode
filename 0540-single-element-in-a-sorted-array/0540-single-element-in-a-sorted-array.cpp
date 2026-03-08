class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int low=0,high=nums.size()-1;
        int ans;
        while(low<=high)
        {   
            if(low==high)return nums[low];
            int mid=low+(high-low)/2;
            
            if(mid%2==0)
            {
                if(nums[mid]==nums[mid+1])
                {
                    low=mid+2;
                }
                else{
                    high=mid;
                }
            }
            else{
                if(nums[mid]==nums[mid-1])
                {
                    low=mid+1;
                }
                else{
                    high=mid-1;
                }
            }
            ans=nums[mid];
        }
        return nums[low];
    }
};