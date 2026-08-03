class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalgas = accumulate(gas.begin(), gas.end(),0);
        int totalcost = accumulate(cost.begin(), cost.end(),0);
        if(totalgas<totalcost)return -1;
        int n = gas.size();
        int curgas= 0;
        int start =0;
        for(int i =0; i<n; i++)
        {
            curgas+=gas[i]- cost[i];
            if(curgas<0)
            {
                curgas=0;
                start = i+1;
            }
        }
        return start;
    }
};