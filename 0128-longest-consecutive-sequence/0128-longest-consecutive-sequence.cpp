class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>st;
        for(int i=0;i<nums.size();i++)st.insert(nums[i]);
        int cnt=1;
        int maxcnt=0;
        for(auto s:st)
        {
            if(st.find(s-1)==st.end())
            {
                cnt=1;
            while(st.find(s+1)!=st.end())
            {
                cnt++;
                s++;
            }
            maxcnt=max(maxcnt,cnt);
        }

        

    }
    return maxcnt;
    }
};