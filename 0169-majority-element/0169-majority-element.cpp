class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        int cnt=0;
        int majority;
        for(int i=0;i<n;i++)
        {
            if(cnt==0)
            {
                majority= nums[i];
                cnt++;
            }
            else if(nums[i]==majority)
            {
                cnt++;
            }
            else cnt--;
        }
        if(cnt>0)
        {
            cnt=0;
            for(int i=0;i<n;i++)
            {
                if(nums[i]==majority)cnt++;
            }
        }
        if(cnt>n/2)return majority;
        return -1;
    }
};