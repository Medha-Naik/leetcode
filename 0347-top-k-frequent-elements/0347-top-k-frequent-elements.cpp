class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>freq;
        for(auto num:nums)
        {
            freq[num]++;
        }
        int n=nums.size();
        vector<vector<int>>bucket(n+1);
        for(auto &p:freq)
        {
            bucket[p.second].push_back(p.first);
        }
        vector<int>res;
        for(int i=n;i>=1&&res.size()<k;i--)
        {
            for(auto it:bucket[i])
            {
                res.push_back(it);
                if(res.size()==k)break;
            }
        }
        return res;
    }
};