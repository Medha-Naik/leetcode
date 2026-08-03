class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>st;
        int n = nums.size();
        
        for(int i = 0; i<n; i++)
        {
            st.insert(nums[i]);
        }
        int cnt = 1;
        int maxcnt = 0;
        for ( auto num :st)
        {
            int cur = num;
            if(!st.count(cur-1))
            {
                cnt =1;
                while(st.count(cur+1))
                {
                    cur = cur+1;
                    cnt++;
                }
                maxcnt = max(maxcnt,cnt);
            }
        }
        return maxcnt;
    }
};