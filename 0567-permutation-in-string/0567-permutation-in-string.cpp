class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int freq1[26]={0};
        for(int i=0;i<s1.size();i++)
        {
            freq1[s1[i]-'a']++;
        }
        int l=0,r=0;
        int n=s2.size();
        int freq2[26]={0};
        while(r<n)
        {   
            freq2[s2[r]-'a']++;
            
            if(r-l+1==s1.size())
            {   
                if(memcmp(freq1,freq2,sizeof(freq1))==0)return true;
                freq2[s2[l]-'a']--;
                l++;
            }
            r++;
        }
        return false;
    }
};