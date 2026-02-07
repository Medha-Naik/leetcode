class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        int start=0;
        int astart=-1,aend=-1;
        int maxi=INT_MIN;
        
        for(int i=0;i<n;i++)
        {   sum+=nums[i];
             if(sum>maxi)
            {
                maxi=sum;
                astart=start;
                aend=i;
            }
            if(sum<0)
            {
                sum=0;
                start=i+1;
            }
           
        }
        return maxi;
    }
};