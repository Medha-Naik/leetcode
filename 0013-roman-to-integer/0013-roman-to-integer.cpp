class Solution {
public:

    int findval(char c)
    {
        if(c=='I')return 1;
        else if(c=='V')return 5;
        else if(c=='X')return 10;
        else if(c=='L')return 50;
        else if(c=='C')return 100;
        else if(c=='D')return 500;
        return 1000;
    }
    int romanToInt(string s) {
        int n=s.size();
        int prevval=findval(s[n-1]);
        int ans=prevval;
        for(int i=n-2;i>=0;i--)
        {
            char c=s[i];
            int val=findval(c);
            if(val<prevval)
            {
                ans-=val;
            }
            else
            {
            ans+=val;
            }
            prevval=val;
        }
        return ans;
    }
};