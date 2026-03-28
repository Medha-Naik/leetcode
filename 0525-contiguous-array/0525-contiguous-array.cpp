class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int maxlen=0;
        int sum=0;
        unordered_map<int,int>pref;
        pref[0]=-1;
        for(int i=0;i<nums.size();i++)
        {
            nums[i]==0?sum-=1:sum+=1;
            if(pref.find(sum)!=pref.end())
            {
                maxlen=max(maxlen,i-pref[sum]);
            }
            if(pref.find(sum)==pref.end())
            {
                pref[sum]=i;
            }

        }
        return maxlen;
    }
};