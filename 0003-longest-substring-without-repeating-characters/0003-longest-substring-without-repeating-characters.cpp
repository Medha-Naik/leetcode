class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0,r=0,n=s.size();
        int cnt=0;
        vector<int>hash(256,0);
        while(r<n)
        {
            hash[s[r]]++;
            while(hash[s[r]]>1)
            {
                hash[s[l]]--;
                l++;
            }
            cnt=max(cnt,r-l+1);
            r++;
        }
        return cnt;
    }
};