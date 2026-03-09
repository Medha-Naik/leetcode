class Solution {
public:
    int cntDays(vector<int>&bloomDay,int mid,int m,int k)
    {
        int bouquee=0;
        int cnt=0;

        for(int i=0;i<bloomDay.size();i++)
        {   
          if(bloomDay[i]<=mid)
          {
            cnt++;
            if(cnt==k){
                cnt=0;
                bouquee++;
            }
          }
          else{
            cnt=0;
          }
        }
        if(bouquee>=m)return true;
        return false;
      
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int low=1;
        int high=*max_element(bloomDay.begin(),bloomDay.end());
        if(bloomDay.size()<(long long)m*k)return -1;
        int res=-1;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(cntDays(bloomDay,mid,m,k))
            {
                res=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return res;
    }
};