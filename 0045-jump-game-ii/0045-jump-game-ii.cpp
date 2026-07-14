class Solution {
public:
    int jump(vector<int>& nums) {
        int l=0,r=0,jumps=0;
        int farthest=0;
        while(r<nums.size()-1)
        {
            for(int i=0;i<=r;i++)
            {
                farthest=max(farthest,i+nums[i]);
            }
            l=r+1;
            r=farthest;
            jumps=jumps+1;
        }
        return jumps;
    }
};