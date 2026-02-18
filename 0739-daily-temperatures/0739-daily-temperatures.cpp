class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int,int>>st;
        int n=temperatures.size();
        vector<int>res(n,0);
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty()&&st.top().first<=temperatures[i])st.pop();
            if(st.empty())
            {
                res[i]=0;
            }
            else{
                auto it=st.top();
                res[i]=it.second-i;
            }
            st.push({temperatures[i],i});
        }
        return res;
    }
};