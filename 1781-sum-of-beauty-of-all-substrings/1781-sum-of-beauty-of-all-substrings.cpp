class Solution {
public:
    int beautySum(string s) {
        int n=s.size();
        int res=0;
        for(int i=0;i<n;i++)
        {
            vector<int>freq(26,0);
            int max_freq=0;
            for(int j=i;j<n;j++)
            {
                int idx=s[j]-'a';
                freq[idx]++;
                max_freq=max(max_freq,freq[idx]);
                int min_freq=INT_MAX;
                for(int k=0;k<26;k++)
                {
                    if(freq[k]>0)
                    {
                        min_freq=min(min_freq,freq[k]);
                    }
                }
                res+=(max_freq-min_freq);
            }
        }
        return res;
    }

};