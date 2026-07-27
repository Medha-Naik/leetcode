class Solution {
public:
    bool isAnagram(string s, string t) {
        
        if(s.size()!=t.size()) return false;

        unordered_map<char, int>mp;
        int n = s.size();
        for(int i=0; i<n; i++)
        {
            mp[s[i]]++;
        }

        for(int i=0; i<n; i++)
        {
            mp[t[i]]--;
            if(mp[t[i]]==0)mp.erase(t[i]);
        }
        if(mp.size()!=0)return false;

        return true;

    }
};