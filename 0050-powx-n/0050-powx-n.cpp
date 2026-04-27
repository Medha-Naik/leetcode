class Solution {
public:
    double myPow(double x, int n) {
        long long N=n;
        if(n<0)
        {
            x=1/x;
            N=-N;
        }
        double res=1;
        while(N>0)
        {
            if(N%2==0)
            {
                x=x*x;
                N/=2;
            }
            else{
                res*=x;
                N--;
            }
        }
        return res;
    }
};