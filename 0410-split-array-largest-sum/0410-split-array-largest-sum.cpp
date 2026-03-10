class Solution {
public:

    int cntUnits(int mid,vector<int>nums,int k)
    {   
        int cnt=1;
        int units=0;
        for(int i=0;i<nums.size();i++)
        {
            if(units+nums[i]<=mid)
            {
                units+=nums[i];
            }
            else{
                units=nums[i];
                cnt++;
            }
        }
        return cnt<=k;
    }
    int splitArray(vector<int>& nums, int k) {
        int low=*max_element(nums.begin(),nums.end());
        int high=accumulate(nums.begin(),nums.end(),0);
        if(nums.size()<k)return -1;
        int res=-1;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(cntUnits(mid,nums,k))
            {
                res=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return res;
    }
};