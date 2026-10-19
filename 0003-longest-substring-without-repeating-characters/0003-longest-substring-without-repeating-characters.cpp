class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int maxlen = 0;
        int len = 0;
        unordered_map<char,int>mp;

        int left = 0, right = 0;
        while(right< n)
        {
            if(mp.count(s[right]))
            {
            left = max(left,mp[s[right]]+1);

            }
            mp[s[right]]= right;
            len = right - left +1;
            maxlen = max(maxlen, len);
            right++;
        }
        return maxlen;
    }
};