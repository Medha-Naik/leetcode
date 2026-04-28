class Solution {
public:
    long long MOD=1e9+7;

    long long pow(long long x,long long n)
    {   
        long long res=1;
        while(n>0)
        {
            if(n%2==0)
            {
                n/=2;
                x=(x*x)%MOD;
            }
            else{
                n--;
                res=(res*x)%MOD;
            }
        }
        return res;
    }
    int countGoodNumbers(long long n) {
        long long even=(n+1)/2;
        long long  odd=n/2;
        long long res;
        res=((pow(5,even)%MOD)*(pow(4,odd)%MOD))%MOD;
        return res;
    }
};