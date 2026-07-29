class Solution {
public:

    vector<int> nextSe(vector<int>& arr)
    {
        int n= arr.size();
        stack<int>st;
        vector<int> res(n);
        int i= n-1;
        while(i>=0)
        {
            while(!st.empty()&& arr[i]<= arr[st.top()])st.pop();
            res[i]=st.empty()?n:st.top();
            st.push(i);
            i--;
        }
        return res;
    }
    vector<int> prevSe(vector<int>& arr)
    {
        int n= arr.size();
        stack<int>st;
        vector<int> res(n);
        int i= 0;
        while(i<n)
        {
            while(!st.empty()&& arr[i]<arr[st.top()])st.pop();
            res[i]=st.empty()?-1:st.top();
            st.push(i);
            i++;
        }
        return res;
    }
    int sumSubarrayMins(vector<int>& arr) {
        vector<int>pse= prevSe(arr);
        vector<int>nse = nextSe(arr);

        long long total = 0;
        int mod = 1e9+7;
        for(int i=0; i<arr.size(); i++)
        {
            long long ne= nse[i] -i;
            long long pe= i-pse[i];
            total= (total+ (ne*pe)%mod * arr[i]) %mod;
        }
        return total;
    }
};