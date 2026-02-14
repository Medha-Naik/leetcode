class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>freq;
        for(auto num:nums)
        {
            freq[num]++;
        }
        priority_queue<pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int,int>>>pq;
        for(auto &p:freq)
        {
            pq.push({p.second,p.first});
            if(pq.size()>k)
            {
                pq.pop();
            }
        }
        vector<int>res;
        while(!pq.empty())
        {
            auto it=pq.top();
            pq.pop();
            res.push_back(it.second);
        }
        return res;
    }
};