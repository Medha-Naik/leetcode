class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int lastjumpend= 0;
        int maxreach =0;
        int cnt = 0;
        for(int i =0; i<n-1;i++)
        {
            maxreach= max(maxreach, i+nums[i]);
            if(i== lastjumpend)
            {
                lastjumpend = maxreach;
                cnt++;
                if(lastjumpend>=n-1)break;
            }
        }
        return cnt;
    }
};