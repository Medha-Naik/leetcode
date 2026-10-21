class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        if (n > m) return false;

        vector<int> need(26, 0), window(26, 0);
        for (int i = 0; i < n; i++) {
            need[s1[i] - 'a']++;
            window[s2[i] - 'a']++;
        }

        int matches = 0;
        for (int i = 0; i < 26; i++) {
            if (need[i] == window[i]) matches++;
        }

        for (int i = n; i < m; i++) {
            if (matches == 26) return true;

            int r = s2[i] - 'a';          
            window[r]++;
            if (window[r] == need[r]) matches++;
            else if (window[r] == need[r] + 1) matches--;

            int l = s2[i - n] - 'a';      
            window[l]--;
            if (window[l] == need[l]) matches++;
            else if (window[l] == need[l] - 1) matches--;
        }
        return matches == 26;
    }
};