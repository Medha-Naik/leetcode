class Solution {
public:
    int calchashvalue(string a,int n)
    {   
        long long mod=1e9+7;
        int base=26;
        long long res=0;
        long long pow=1;
        for(int i=n-1;i>=0;i--)
        {
            res=((res+(a[i]-'a')*pow))%mod;
            pow=(pow*base)%mod;
        }
        return res;
    }
    int repeatedStringMatch(string a, string b) {
        int m=a.size();
        int n=b.size();
        int cnt=1;
        string repeated=a;
        while(repeated.size()<m+n)
        {
            cnt++;
            repeated+=a;
        }
        int hashpattern=calchashvalue(b,n);
       for(int i=0;i<=repeated.size()-n;i++)
       {
            string s=repeated.substr(i,n);
            int hashtext=calchashvalue(s,n);
            if(hashtext==hashpattern)
            {   bool match=true;
                for(int j=0;j<n;j++)
                {
                    if(s[j]!=b[j])
                    {
                        match=false;
                        break;
                    }
                }
                if(match)return (i+m+n-1)/m;
            }
       }
      
      return -1;
    }
    
};