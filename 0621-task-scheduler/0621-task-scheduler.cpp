class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int>freq(26,0);
        for(auto t:tasks)
        {
            freq[t-'A']++;
        }
        priority_queue<int>pq;
        for(int i=0;i<26;i++)
        {
            if(freq[i]>0)pq.push(freq[i]);
        }
        int time=0;
        while(!pq.empty())
        {
            vector<int>temp;
            int cyclecnt=0;
            for(int i=0;i<=n;i++)
            {
                if(!pq.empty())
                {
                    int val=pq.top();
                    pq.pop();
                    val--;
                    if(val>0)temp.push_back(val);
                    cyclecnt++;
                }
               
            }
             for(auto p:temp)
                {
                    pq.push(p);
                }
                time+=pq.empty()?cyclecnt:n+1;
        }
        return time;
    }
};