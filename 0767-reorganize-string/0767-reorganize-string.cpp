class Solution {
public:
    string reorganizeString(string s) {
        int freq[26]={0};
        int maxfreq=0;
        char ch;
        for(int i=0;i<s.size();i++)
        {
            freq[s[i]-'a']++;
            if(maxfreq<freq[s[i]-'a'])
            {
                 ch=s[i];
                 maxfreq=freq[s[i]-'a'];
            }
        }
        int n=s.size();
        if (maxfreq>(n+1)/2)return "";
        int idx=0;
        string res(n, ' ');
        while(idx<n&&freq[ch-'a']>0)
        {
            res[idx]=ch;
            idx+=2;
            freq[ch-'a']--;
        }
        
        for(int i=0;i<26;i++)
        {
            while(freq[i]>0)
            {
                if(idx>=n)idx=1;
                res[idx]='a'+i;
                idx+=2;
                freq[i]--;
            }
        }
        return res;
    }
};