class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend==INT_MIN&&divisor==-1)return INT_MAX;
        if(dividend==divisor)return 1;

        int sign=(divisor>0)^(dividend>0)?-1:1;

        long a=abs(long(dividend));
        long b=abs(long(divisor));
        long res=0;

        while(a>=b)
        {
            long temp=b,multiple=1;
            while(a>(temp<<1))
            {
                temp<<=1;
                multiple<<=1;
            }
            res+=multiple;
            a-=temp;
            
        }
    return (sign)*res;
    }
};