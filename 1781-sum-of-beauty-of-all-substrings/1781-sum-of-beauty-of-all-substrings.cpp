class Solution {
public:
    int beautySum(string s) {
        int n=s.size();
        
        int total =0;
        for(int i=0; i<n; i++)
        {
            int freq[26]={0};
            
            for(int j=i; j<n; j++)
            {
                freq[s[j]-'a']++;
                int minfreq= INT_MAX;
                int maxfreq= INT_MIN;
                for(int k=0;k<26; k++)
                {   
                    if(freq[k]>0)
                    {
                    minfreq = min(minfreq, freq[k]);
                    maxfreq = max(maxfreq,freq[k]);
                    }
                }
                total+=maxfreq-minfreq;
            }
        }
        return total;
    }
};