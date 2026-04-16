class Solution {
public:
    int majorityElement(vector<int>& nums) {
       int n=nums.size();
       int cnt=0;
       int major;
       for(int i=0;i<n;i++)
       {
        if(cnt==0)
        {
            major=nums[i];
            cnt++;
        }
        else if(nums[i]==major)cnt++;
        else cnt--;
       } 
        cnt=0;
       for(int i=0;i<n;i++)
       {
        if(nums[i]==major)cnt++;
       }
       if(cnt>n/2)return major;
       return -1;
    }
};