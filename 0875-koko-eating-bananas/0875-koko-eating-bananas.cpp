class Solution {
public:
    long long countHours(int mid,vector<int>&piles)
    {
        int n=piles.size();
        long long cnt=0;
        for(int i=0;i<n;i++)
        {
            
                cnt+=(piles[i]+mid-1)/mid;
            
        }
        return cnt;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1;
        int high=*max_element(piles.begin(),piles.end());
        int ans;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            long long hours=countHours(mid,piles);
            if(hours<=h)
            {   
                ans=mid;
                high=mid-1;
                
            }
            else{
              low=mid+1;
            }
        }
        return ans;
    }
};