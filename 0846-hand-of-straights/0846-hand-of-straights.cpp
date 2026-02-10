class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n=hand.size();
        if(n%groupSize!=0)return false;
        map<int,int>mp;
        for(auto h:hand)
        {
            mp[h]++;
        }

        while(!mp.empty())
        {
            int first=mp.begin()->first;
            for(int i=0;i<groupSize;i++)
            {
                int val=first+i;
                if(mp.find(val)==mp.end())return false;

                mp[val]--;
                if(mp[val]==0)
                {
                    mp.erase(val);
                }                
            }
        }
        return true;
    }
};