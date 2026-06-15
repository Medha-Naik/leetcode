class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend==INT_MIN&& divisor==-1)return INT_MAX;


        long long dvs=abs(long(divisor));
        long long dvd=abs(long(dividend));
        long long res=0;

        while(dvd>=dvs)
        {
            long long temp=dvs,multiple=1;

            while(dvd>=(temp<<1))
            {
                temp<<=1;
                multiple<<=1;
            }
            dvd-=temp;
            res+=multiple;
        }
        if((dividend<0)^(divisor<0))res=-res;
        return (int)res;
    }
};