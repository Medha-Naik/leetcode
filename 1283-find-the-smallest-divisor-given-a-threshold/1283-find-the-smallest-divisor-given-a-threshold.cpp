class Solution {
public:
    bool cntsum(int mid,vector<int>&nums,int threshold)
    {
        int n=nums.size();
        int res=0;
        for(int i=0;i<n;i++)
        {
            res+=(nums[i]+mid-1)/mid;
        }
        return (res<=threshold);
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low=1;
        int high=*max_element(nums.begin(),nums.end());
        int res;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(cntsum(mid,nums,threshold))
            {
                high=mid-1;
                res=mid;
            }
            else low=mid+1;
        }
        return res;
    }
};