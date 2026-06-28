class Solution {
public:
    int minBitFlips(int start, int goal) {
        int ans=start^goal;
        int cnt=0;
        for(int i=0;i<=31;i++)
        {
            if(ans&1)
            {
                cnt+=1;   
            }
            ans>>=1;
        }
        return cnt;
    }
};