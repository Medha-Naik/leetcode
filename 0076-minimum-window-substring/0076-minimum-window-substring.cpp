class Solution {
public:
    string minWindow(string s, string t) {
        vector<int>hash(256,0);
        for(char c: t) hash[c]++;

        int l =0, r = 0;
        int minlen = INT_MAX;
        int sindex = -1;
        int cnt = 0;
        int m = t.size();
        while(r<s.size())
        {
    
            if(hash[s[r]]>0)cnt++;
            hash[s[r]]--;
            
            while(cnt == m)
                {
                    if(r-l+1< minlen)
                    {
                        minlen = r-l+1;
                        sindex = l;
                    }
                    hash[s[l]]++;
                    if(hash[s[l]]> 0) cnt--;
                    l++;
                }
            r++;
            
    
        }

        return sindex == -1?"": s.substr(sindex,minlen);
    }
};