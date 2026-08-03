class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n= s.size();
        vector<int>hash(26,-1);
        for(int i=0; i<n; i++)
        {
            hash[s[i]-'a']=i;
        }

        int maxlast = -1;
        vector<int>res;
        int start =0;
        for(int i=0;i<n;i++)
        {
            maxlast= max(maxlast,hash[s[i]-'a']);

            if(i == maxlast)
            {
                res.push_back(i-start+1);
                start= i+1;
            }

        }
        return res;
    }
};