class Solution {
public:
    string frequencySort(string s) {
        int n = s.size();
        unordered_map<char,int>freq;
        for(char ch:s)
        {
            freq[ch]++;
        }
        vector<string>bucket(n+1,"");
        for(auto &[ch,count]:freq)
        {
            bucket[count].append(count,ch);
        }

        string res = "";
        for(int i= n; i>=0;i--)
        {
            if(!bucket[i].empty())
            {
                res+=bucket[i];
            }
        }
        return res;
    }
};