class Solution {
public:
    bool checkCapability(int mid,vector<int>&nums,int k)
    {   
        int cnt = 0;
for(int i = 0; i < nums.size(); i++) {
    if(nums[i] <= mid) {
        cnt++;
        i++;  // skip next house
    }
}
return cnt >= k;
    }
    int minCapability(vector<int>& nums, int k) {
        int n=nums.size();
        int res=-1;
        int low=*min_element(nums.begin(),nums.end());
        int high=*max_element(nums.begin(),nums.end());
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(checkCapability(mid,nums,k))
            {
                high=mid-1;
                res=mid;
            }
            else low=mid+1;
        }
        return res;

    }
};