class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int freqp[26]={0};
        if(s.size()<p.size())return {};
        for(int i=0;i<p.size();i++)
        {
            freqp[p[i]-'a']++;
        }
        int freqs[26]={0};
        int l=0,r=0;
        int n=s.size();
        vector<int>res;
        while(r<n)
        {
            freqs[s[r]-'a']++;
            if(r-l+1==p.size())
            {
                if(memcmp(freqs,freqp,sizeof(freqs))==0)res.push_back(l);
                freqs[s[l]-'a']--;
                l++;
            }
            r++;
        }
        return res;
    }
};