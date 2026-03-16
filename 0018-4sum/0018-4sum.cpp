class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
      int n=nums.size();
      sort(nums.begin(),nums.end());
      vector<vector<int>>res;
      for(int i=0;i<n;i++)
      {
        if(i>0&&nums[i]==nums[i-1])continue;
        for(int j=i+1;j<n;j++)
        {   
            if(j>i+1&&nums[j]==nums[j-1])continue;
            long long sum=0;
            int l=j+1,r=n-1;
            vector<int>temp;
            while(l<r)
            {
                sum=(long long)nums[i]+nums[j]+nums[l]+nums[r];
                if(sum>target)r--;
                else if(sum<target)l++;
                else 
                {
                    temp={nums[i],nums[j],nums[l],nums[r]};
                    res.push_back(temp);
                    l++;
                    r--;
                    while(l<r&&nums[l]==nums[l-1])l++;
                    while(l<r&&nums[r]==nums[r+1])r--;
                }
        }
      }
   
    }
    return res;
    }
};