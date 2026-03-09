class Solution {
public:
    bool cntDays(vector<int>&weights,int days, int mid)
    {
        int n=weights.size();
        int totaldays=1;
        int load=0;
        for(int i=0;i<n;i++)
        {
            if(load+weights[i]>mid)
            {
                
                totaldays++;
                load=0;
            }
            
                load+=weights[i];
            
        }
        return (totaldays<=days);
    }
    int shipWithinDays(vector<int>& weights, int days) {

        int low=*max_element(weights.begin(),weights.end());
        int high=accumulate(weights.begin(),weights.end(),0);
        int res=-1;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(cntDays(weights,days,mid))
            {
                high=mid-1;
                res=mid;
            }
            else{
                low=mid+1;
            }
        }
        return res;
    }
};