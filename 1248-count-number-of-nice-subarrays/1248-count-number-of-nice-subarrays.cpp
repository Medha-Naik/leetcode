class Solution {
public:
    int cntnicesubarray(vector<int>&nums,int k)
    {   
        if(k<0)return 0;
        int l=0,r=0;
        int cnt=0;
        int tot=0;
        while(r<nums.size())
        {
            if(nums[r]%2==1)
            {
                cnt++;
            }
            while(cnt>k)
            {
                if(nums[l]%2==1)cnt--;
                l++;
            }
            tot+=r-l+1;
            r++;
        }
        return tot;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return cntnicesubarray(nums,k)-cntnicesubarray(nums,k-1);
    }
};