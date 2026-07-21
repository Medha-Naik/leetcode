class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n= gas.size();
        int curgas=0;
        int start=0;
        int total=0;
        for(int i=0;i<n;i++)
        {
            int diff=gas[i]-cost[i];
            curgas+=diff;
            total+=diff;
            if(curgas<0)
            {
                curgas=0;
                start=i+1;
            }

        }
        return (total<0)?-1:start;
    }
};